#include "hle/rt64_application.h"
#include "ultramodern/renderer_context.hpp"
#include "ultramodern/config.hpp"

#include <algorithm>
#include <cstdio>
#include <memory>

namespace {
uint8_t dmem[0x1000]{};
uint8_t imem[0x1000]{};
uint32_t mi_intr{};
uint32_t dpc_start{}, dpc_end{}, dpc_current{}, dpc_status{}, dpc_clock{}, dpc_bufbusy{}, dpc_pipebusy{}, dpc_tmem{};

void check_interrupts() {}

class RT64Context final : public ultramodern::renderer::RendererContext {
public:
    RT64Context(uint8_t* rdram, ultramodern::renderer::WindowHandle handle, bool developer_mode) {
        static uint8_t header[0x40] = {
            0x80, 0x37, 0x12, 0x40, 0x00, 0x00, 0x00, 0x0F, 0x80, 0x04, 0xB4, 0x00, 0x00, 0x00, 0x14, 0x48,
            0xA2, 0x73, 0xAB, 0x56, 0xDA, 0x33, 0xDB, 0x9A, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
            0x44, 0x55, 0x4B, 0x45, 0x20, 0x4E, 0x55, 0x4B, 0x45, 0x4D, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20,
            0x20, 0x20, 0x20, 0x20, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x4E, 0x44, 0x4E, 0x45, 0x00
        };
        RT64::Application::Core core{};
        core.window = handle.window;
        core.HEADER = header;
        core.RDRAM = rdram;
        core.DMEM = dmem;
        core.IMEM = imem;
        core.MI_INTR_REG = &mi_intr;
        core.DPC_START_REG = &dpc_start;
        core.DPC_END_REG = &dpc_end;
        core.DPC_CURRENT_REG = &dpc_current;
        core.DPC_STATUS_REG = &dpc_status;
        core.DPC_CLOCK_REG = &dpc_clock;
        core.DPC_BUFBUSY_REG = &dpc_bufbusy;
        core.DPC_PIPEBUSY_REG = &dpc_pipebusy;
        core.DPC_TMEM_REG = &dpc_tmem;
        auto* vi = ultramodern::renderer::get_vi_regs();
        core.VI_STATUS_REG = &vi->VI_STATUS_REG;
        core.VI_ORIGIN_REG = &vi->VI_ORIGIN_REG;
        core.VI_WIDTH_REG = &vi->VI_WIDTH_REG;
        core.VI_INTR_REG = &vi->VI_INTR_REG;
        core.VI_V_CURRENT_LINE_REG = &vi->VI_V_CURRENT_LINE_REG;
        core.VI_TIMING_REG = &vi->VI_TIMING_REG;
        core.VI_V_SYNC_REG = &vi->VI_V_SYNC_REG;
        core.VI_H_SYNC_REG = &vi->VI_H_SYNC_REG;
        core.VI_LEAP_REG = &vi->VI_LEAP_REG;
        core.VI_H_START_REG = &vi->VI_H_START_REG;
        core.VI_V_START_REG = &vi->VI_V_START_REG;
        core.VI_V_BURST_REG = &vi->VI_V_BURST_REG;
        core.VI_X_SCALE_REG = &vi->VI_X_SCALE_REG;
        core.VI_Y_SCALE_REG = &vi->VI_Y_SCALE_REG;
        core.checkInterrupts = check_interrupts;
        RT64::ApplicationConfiguration app_config{};
        app_config.useConfigurationFile = false;
        app = std::make_unique<RT64::Application>(core, app_config);
        setup_result = map_result(app->setup(handle.thread_id));
        chosen_api = ultramodern::renderer::GraphicsApi::Auto;
        if (setup_result != ultramodern::renderer::SetupResult::Success) app.reset();
    }
    bool valid() override { return app != nullptr; }
    bool update_config(const ultramodern::renderer::GraphicsConfig& old_config, const ultramodern::renderer::GraphicsConfig& new_config) override {
        if (!app || old_config == new_config) return false;
        app->updateUserConfig(true);
        return true;
    }
    void enable_instant_present() override {
        if (!app) return;
        app->enhancementConfig.presentation.mode = RT64::EnhancementConfiguration::Presentation::Mode::PresentEarly;
        app->updateEnhancementConfig();
    }
    void send_dl(const OSTask* task) override {
        if (!app) return;
        app->state->rsp->reset();
        app->interpreter->loadUCodeGBI(task->t.ucode & 0x3FFFFFF, task->t.ucode_data & 0x3FFFFFF, true);
        app->processDisplayLists(app->core.RDRAM, task->t.data_ptr & 0x3FFFFFF, 0, true);
    }
    void send_dummy_workload(uint32_t fb_address) override {
        if (app) app->updateScreen();
        (void)fb_address;
    }
    void update_screen() override { if (app) app->updateScreen(); }
    void shutdown() override { if (app) app->end(); }
    uint32_t get_display_framerate() const override {
        return (app && app->presentQueue && app->presentQueue->ext.sharedResources)
            ? app->presentQueue->ext.sharedResources->swapChainRate : 60;
    }
    float get_resolution_scale() const override {
        if (!app) return 1.0f;
        if (app->userConfig.resolution == RT64::UserConfiguration::Resolution::Manual)
            return static_cast<float>(app->userConfig.resolutionMultiplier);
        return 1.0f;
    }

private:
    static ultramodern::renderer::SetupResult map_result(RT64::Application::SetupResult result) {
        switch (result) {
        case RT64::Application::SetupResult::Success: return ultramodern::renderer::SetupResult::Success;
        case RT64::Application::SetupResult::DynamicLibrariesNotFound: return ultramodern::renderer::SetupResult::DynamicLibrariesNotFound;
        case RT64::Application::SetupResult::InvalidGraphicsAPI: return ultramodern::renderer::SetupResult::InvalidGraphicsAPI;
        case RT64::Application::SetupResult::GraphicsAPINotFound: return ultramodern::renderer::SetupResult::GraphicsAPINotFound;
        case RT64::Application::SetupResult::GraphicsDeviceNotFound: return ultramodern::renderer::SetupResult::GraphicsDeviceNotFound;
        }
        return ultramodern::renderer::SetupResult::GraphicsDeviceNotFound;
    }
    std::unique_ptr<RT64::Application> app;
};
}

std::unique_ptr<ultramodern::renderer::RendererContext> create_render_context(uint8_t* rdram, ultramodern::renderer::WindowHandle handle, bool developer_mode) {
    return std::make_unique<RT64Context>(rdram, handle, developer_mode);
}
