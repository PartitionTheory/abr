cmake_minimum_required(VERSION 3.16)
project(abr VERSION 0.5 LANGUAGES C)

set(CMAKE_C_STANDARD 11)
set(CMAKE_C_STANDARD_REQUIRED ON)

include_directories(
    include
    core/operators
    core/registry
    core/runtime
    core/system
    core/dispatch
    core/loader
)

set(ABR_CORE_SOURCES
    core/runtime/abr_runtime_context.c
    core/runtime/abr_runtime_execute.c
    core/runtime/abr_runtime_pipeline.c
    core/system/abr_system.c
    core/dispatch/abr_dispatch.c
    core/stream/abr_stream.c
    core/operators/abr_operators.c
    core/operators/abr_operator_chain.c
    core/loader/abr_plugin_loader.c
    core/loader/abr_plugin_loader_builtin.c
    core/loader/abr_plugin_loader_math_v4.c
    core/registry/abr_plugin_registry.c
)

set(ABR_BUILTIN_PLUGINS
    plugins/builtin/identity.c
    plugins/builtin/not.c
)

set(ABR_MATH_V4_PLUGINS
    plugins/math_v4/manifold_dynamics.c
    plugins/math_v4/manifold_dynamics_extension.c
    plugins/math_v4/invariant_explorer.c
    plugins/math_v4/recursion_engine.c
    plugins/math_v4/density_index.c
    plugins/math_v4/phi_stability.c
    plugins/math_v4/domain_seed.c
    plugins/math_v4/operator_chain.c
    plugins/math_v4/abr_math_v4_execute_chain.c
)

set(ABR_CLI_SOURCES
    cli/abr_cli.c
    cli/main.c
)

set(ABR_VM_SOURCES
    vm/abr_vm.c
)

add_library(abr_builtin_plugins STATIC ${ABR_BUILTIN_PLUGINS})
add_library(abr_math_v4_plugins STATIC ${ABR_MATH_V4_PLUGINS})
add_library(abr_core STATIC ${ABR_CORE_SOURCES})

target_link_libraries(abr_core
    PRIVATE
        abr_builtin_plugins
)

add_executable(abr ${ABR_CLI_SOURCES})
target_link_libraries(abr PRIVATE
    -Wl,--start-group
        abr_core
        abr_math_v4_plugins
    -Wl,--end-group
)

add_executable(abr_vm ${ABR_VM_SOURCES})
target_link_libraries(abr_vm PRIVATE abr_core)

