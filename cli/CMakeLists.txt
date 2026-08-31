# ---------------------------------------------------------------------------
# ABR CLI Executable
# Builds: abr
# ---------------------------------------------------------------------------

add_executable(abr
    ../src/main.c
    ../src/abr_cli.c
)

target_include_directories(abr PUBLIC ../include)

target_link_libraries(abr
    abr_core
    abr_vm
    abr_interface
    abr_operators
    abr_stream
    abr_plugins
    abr_plugin_registry
)

add_library(abr_cli_commands
    abr_cli_commands.c
    abr_cli_integration.c
)
target_include_directories(abr_cli_commands PRIVATE ../include)

