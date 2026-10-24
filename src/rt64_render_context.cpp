#include "hle/rt64_application.h"
#include "ultramodern/renderer_context.hpp"
#include "ultramodern/config.hpp"
#include "gui/rt64_inspector.h"
#include "rhi/rt64_render_hooks.h"
#include "imgui/imgui.h"

#include <algorithm>
#include <atomic>
#include <chrono>
#include <cstdio>
#include <memory>
#include <mutex>
extern std::atomic<bool> render_diagnostics_visible;

namespace {
uint8_t dmem[0x1000]{};
uint8_t imem[0x1000]{};
uint32_t mi_intr{};
uint32_t dpc_start{}, dpc_end{}, dpc_current{}, dpc_status{}, dpc_clock{}, dpc_bufbusy{}, dpc_pipebusy{}, dpc_tmem{};

void check_interrupts() {}

class RT64Context;
static RT64Context* active_context = nullptr;
static void draw_render_diagnostics(RenderCommandList* command_list, RenderFramebuffer* framebuffer);

static const char* graphics_api_name(RT64::UserConfiguration::GraphicsAPI api) {
    switch (api) {
    case RT64::UserConfiguration::GraphicsAPI::D3D12: return "D3D12";
    case RT64::UserConfiguration::GraphicsAPI::Vulkan: return "Vulkan";
    case RT64::UserConfiguration::GraphicsAPI::Metal: return "Metal";
    case RT64::UserConfiguration::GraphicsAPI::Automatic: return "Auto";
    default: return "Unknown";
    }
}

static const char* presentation_mode_name(RT64::EnhancementConfiguration::Presentation::Mode mode) {
    switch (mode) {
    case RT64::EnhancementConfiguration::Presentation::Mode::Console: return "Console";
    case RT64::EnhancementConfiguration::Presentation::Mode::SkipBuffering: return "SkipBuffering";
    case RT64::EnhancementConfiguration::Presentation::Mode::PresentEarly: return "PresentEarly";
    default: return "Unknown";
    }
}

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
        app->userConfig.resolution = RT64::UserConfiguration::Resolution::WindowIntegerScale;
        app->userConfig.filtering = RT64::UserConfiguration::Filtering::AntiAliasedPixelScaling;
        app->userConfig.upscale2D = RT64::UserConfiguration::Upscale2D::ScaledOnly;
        app->userConfig.threePointFiltering = true;
        app->userConfig.validate();
        setup_result = map_result(app->setup(handle.thread_id));
        chosen_api = ultramodern::renderer::GraphicsApi::Auto;
        if (setup_result == ultramodern::renderer::SetupResult::Success) {
            diagnostics = std::make_unique<RT64::Inspector>(
                app->device.get(),
                app->swapChain.get(),
                app->chosenGraphicsAPI,
                nullptr
            );
            ImGui::GetIO().IniFilename = nullptr;
            active_context = this;
            RT64::SetRenderHooks(nullptr, &draw_render_diagnostics, nullptr);
        }
        else {
            app.reset();
        }
        (void)developer_mode;
    }
    ~RT64Context() override {
        if (active_context == this) {
            RT64::SetRenderHooks(nullptr, nullptr, nullptr);
            active_context = nullptr;
        }
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
    void shutdown() override {
        if (!shutdown_complete && app) {
            app->end();
            shutdown_complete = true;
        }
        if (active_context == this) {
            RT64::SetRenderHooks(nullptr, nullptr, nullptr);
            active_context = nullptr;
        }
        diagnostics.reset();
    }
    void draw_diagnostics(RenderCommandList* command_list) {
        if (!app || diagnostics == nullptr || command_list == nullptr) return;
        if (!render_diagnostics_visible.load(std::memory_order_relaxed)) {
            reset_fps();
            return;
        }

        update_fps();
        diagnostics->newFrame(app->presentGraphicsWorker.get());
        constexpr ImGuiWindowFlags window_flags =
            ImGuiWindowFlags_NoDecoration |
            ImGuiWindowFlags_AlwaysAutoResize |
            ImGuiWindowFlags_NoSavedSettings |
            ImGuiWindowFlags_NoInputs |
            ImGuiWindowFlags_NoFocusOnAppearing |
            ImGuiWindowFlags_NoNav;
        ImGui::SetNextWindowPos(ImVec2(8.0f, 8.0f), ImGuiCond_Always);
        ImGui::SetNextWindowBgAlpha(0.72f);
        if (ImGui::Begin("##duke64_render_diagnostics", nullptr, window_flags)) {
            const uint32_t width = app->swapChain ? app->swapChain->getWidth() : 0;
            const uint32_t height = app->swapChain ? app->swapChain->getHeight() : 0;
            ImGui::Text("FPS %.1f | Display %u Hz", measured_fps, get_display_framerate());
            ImGui::Text("API %s | Backbuffer %ux%u", graphics_api_name(app->chosenGraphicsAPI), width, height);
            ImGui::Text("Scale %.2fx | Present %s", get_resolution_scale(), presentation_mode_name(app->enhancementConfig.presentation.mode));
            ImGui::TextUnformatted("F3: hide diagnostics");
        }
        ImGui::End();
        diagnostics->endFrame();
        diagnostics->draw(command_list);
    }
    uint32_t get_display_framerate() const override {
        return (app && app->presentQueue && app->presentQueue->ext.sharedResources)
            ? app->presentQueue->ext.sharedResources->swapChainRate : 60;
    }
    float get_resolution_scale() const override {
        if (!app) return 1.0f;
        if (app->sharedQueueResources) {
            std::scoped_lock lock(app->sharedQueueResources->configurationMutex);
            return app->sharedQueueResources->resolutionScale.y;
        }
        return static_cast<float>(app->userConfig.resolutionMultiplier);
    }

private:
    using clock = std::chrono::steady_clock;

    void reset_fps() {
        fps_window_start = {};
        fps_frame_count = 0;
        measured_fps = 0.0;
    }
    void update_fps() {
        const clock::time_point now = clock::now();
        if (fps_window_start == clock::time_point{}) {
            fps_window_start = now;
        }
        ++fps_frame_count;
        const double elapsed = std::chrono::duration<double>(now - fps_window_start).count();
        if (elapsed >= 0.25) {
            measured_fps = static_cast<double>(fps_frame_count) / elapsed;
            fps_window_start = now;
            fps_frame_count = 0;
        }
    }
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
    std::unique_ptr<RT64::Inspector> diagnostics;
    bool shutdown_complete = false;
    clock::time_point fps_window_start{};
    uint32_t fps_frame_count = 0;
    double measured_fps = 0.0;
};
static void draw_render_diagnostics(RenderCommandList* command_list,
                                    RenderFramebuffer*) {
    if (active_context != nullptr) {
        active_context->draw_diagnostics(command_list);
    }
}
}

std::unique_ptr<ultramodern::renderer::RendererContext> create_render_context(uint8_t* rdram, ultramodern::renderer::WindowHandle handle, bool developer_mode) {
    return std::make_unique<RT64Context>(rdram, handle, developer_mode);
}
