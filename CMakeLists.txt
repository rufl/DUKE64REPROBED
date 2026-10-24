cmake_minimum_required(VERSION 3.20)
project(Duke64Recompiled LANGUAGES C CXX)

set(CMAKE_C_STANDARD 17)
set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

set(RT64_STATIC TRUE)
set(RT64_SDL_WINDOW_VULKAN TRUE)
add_compile_definitions(HLSL_CPU)
add_subdirectory(${CMAKE_CURRENT_SOURCE_DIR}/lib/rt64 ${CMAKE_CURRENT_BINARY_DIR}/rt64)

add_subdirectory(${CMAKE_CURRENT_SOURCE_DIR}/../N64ModernRuntime ${CMAKE_CURRENT_BINARY_DIR}/N64ModernRuntime)

add_library(Duke64RecompiledFuncs STATIC)
file(GLOB DUKE64_RECOMP_C CONFIGURE_DEPENDS "${CMAKE_CURRENT_SOURCE_DIR}/RecompiledFuncs/*.c")
file(GLOB DUKE64_RECOMP_CXX CONFIGURE_DEPENDS "${CMAKE_CURRENT_SOURCE_DIR}/RecompiledFuncs/*.cpp")
target_sources(Duke64RecompiledFuncs PRIVATE ${DUKE64_RECOMP_C} ${DUKE64_RECOMP_CXX})
target_compile_options(Duke64RecompiledFuncs PRIVATE
    -fno-strict-aliasing -fwrapv -Wno-unused-variable -Wno-implicit-function-declaration
    # The synchronous audio task must finish within one VI interval in Debug builds.
    $<$<CONFIG:Debug>:-O2>
)
target_include_directories(Duke64RecompiledFuncs PRIVATE
    ${CMAKE_CURRENT_SOURCE_DIR}/../N64ModernRuntime/ultramodern/include
    ${CMAKE_CURRENT_SOURCE_DIR}/../N64ModernRuntime/librecomp/include
    ${CMAKE_CURRENT_SOURCE_DIR}/../N64ModernRuntime/N64Recomp/include
    ${CMAKE_CURRENT_SOURCE_DIR}/lib/rt64/src
    ${CMAKE_CURRENT_SOURCE_DIR}/lib/rt64/src/contrib
    ${CMAKE_CURRENT_SOURCE_DIR}/src
)
target_link_libraries(Duke64RecompiledFuncs PRIVATE librecomp ultramodern)
add_compile_definitions(NOMINMAX)
include(FetchContent)
FetchContent_Declare(
    sdl2
    URL https://github.com/libsdl-org/SDL/releases/download/release-2.30.3/SDL2-devel-2.30.3-VC.zip
)
FetchContent_MakeAvailable(sdl2)
FetchContent_Declare(
    gamepad_motion_helpers
    GIT_REPOSITORY https://github.com/JibbSmart/GamepadMotionHelpers.git
    GIT_TAG f1a76007ec058122a4bb6f19c816c6c0c7b7f12a
)
FetchContent_MakeAvailable(gamepad_motion_helpers)

add_executable(Duke64Recompiled
    src/main.cpp
    src/rt64_render_context.cpp
    src/mod_assets.cpp
    src/missing_funcs.c
    rsp/aspMain.cpp
    duke64.rc
)
target_include_directories(Duke64Recompiled PRIVATE
    ${CMAKE_CURRENT_SOURCE_DIR}/lib/rt64/src/contrib
    ${CMAKE_CURRENT_SOURCE_DIR}/lib/rt64/src/contrib/hlslpp/include
    ${CMAKE_CURRENT_SOURCE_DIR}/../N64ModernRuntime/librecomp/include
    ${CMAKE_CURRENT_SOURCE_DIR}/../N64ModernRuntime/N64Recomp/include
    ${CMAKE_CURRENT_SOURCE_DIR}/lib/rt64/src
    ${CMAKE_CURRENT_SOURCE_DIR}/RecompiledFuncs
    ${CMAKE_CURRENT_SOURCE_DIR}/lib/rt64/src/contrib
    ${sdl2_SOURCE_DIR}/include
)
target_compile_options(Duke64Recompiled PRIVATE
    -msse4.1
    # Keep the generated ASP audio task real-time while retaining debug symbols.
    $<$<CONFIG:Debug>:-O2>
)
target_link_directories(Duke64Recompiled PRIVATE ${sdl2_SOURCE_DIR}/lib/x64)
target_link_libraries(Duke64Recompiled PRIVATE Duke64RecompiledFuncs rt64 librecomp ultramodern SDL2 GamepadMotionHelpers Winmm.lib Shell32.lib)
add_custom_command(TARGET Duke64Recompiled POST_BUILD
    COMMAND ${CMAKE_COMMAND} -E copy_if_different
        "${sdl2_SOURCE_DIR}/lib/x64/SDL2.dll"
        "${CMAKE_CURRENT_SOURCE_DIR}/lib/rt64/src/contrib/dxc/bin/x64/dxil.dll"
        "${CMAKE_CURRENT_SOURCE_DIR}/lib/rt64/src/contrib/dxc/bin/x64/dxcompiler.dll"
        $<TARGET_FILE_DIR:Duke64Recompiled>
)

add_executable(Duke64Launcher WIN32
    src/launcher_main.cpp
    duke64.rc
)
target_compile_definitions(Duke64Launcher PRIVATE UNICODE _UNICODE)
target_link_libraries(Duke64Launcher PRIVATE Comdlg32.lib Shell32.lib)
