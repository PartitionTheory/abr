cmake_minimum_required(VERSION 3.16)

# ---------------------------------------------------------------------------
# ABR-Rebirth: Synthetic Mathematics Runtime
# Root CMake configuration (Hybrid Architecture)
# ---------------------------------------------------------------------------

project(abr VERSION 0.1.0 LANGUAGES C)

# Use modern C standard
set(CMAKE_C_STANDARD 11)
set(CMAKE_C_STANDARD_REQUIRED ON)
set(CMAKE_POSITION_INDEPENDENT_CODE ON)

# Enable verbose output for EF safeguard verification
set(CMAKE_VERBOSE_MAKEFILE ON)

# ---------------------------------------------------------------------------
# Include subdirectories
# ---------------------------------------------------------------------------

add_subdirectory(core)
add_subdirectory(vm)
add_subdirectory(interface)
add_subdirectory(stream)
add_subdirectory(operators)
add_subdirectory(plugins)
add_subdirectory(cli)
add_subdirectory(tests)

# ---------------------------------------------------------------------------
# Installation layout (future use)
# ---------------------------------------------------------------------------

install(DIRECTORY include/ DESTINATION include)

# ---------------------------------------------------------------------------
# Notes:
# - Core builds static library: libabr_core.a
# - VM builds static library: libabr_vm.a
# - Plugins build dynamic modules: *.so
# - CLI builds executable: abr
# ---------------------------------------------------------------------------

