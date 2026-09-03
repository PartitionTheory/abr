cmake_minimum_required(VERSION 3.16)
project(abr C)

set(CMAKE_C_STANDARD 17)
include_directories(${CMAKE_SOURCE_DIR}/include)

add_subdirectory(cli)
add_subdirectory(core)
add_subdirectory(vm)
add_subdirectory(interface)
add_subdirectory(operators)
add_subdirectory(stream)
add_subdirectory(plugins)
add_subdirectory(tests)
#
# ABR‑Rebirth: Phase 4 CMake Integration
# --------------------------------------
# Phase 4 Step 09
#
# This block integrates all new Phase 4 subsystems into the
# existing ABR CMake architecture. No Phase 1–3 targets are
# modified; only new add_subdirectory() entries are added.
#

# Phase 4: Execution Layer
add_subdirectory(exec)

# Phase 4: Reversible Semantics Layer
add_subdirectory(reverse)

# Phase 4: Synthetic Math Layer
add_subdirectory(synth)

# Phase 4: Operator Dispatch Layer
add_subdirectory(dispatch)

# Phase 4: CLI Command Extensions
add_subdirectory(cli_ext)

# Phase 4: Plugin Operator Loader
add_subdirectory(plugins/loader)

