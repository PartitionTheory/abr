# ---------------------------------------------------------------------------
# ABR CLI Executable
# Builds: abr
# ---------------------------------------------------------------------------

add_executable(abr4
    abr_cli_ext.c
    main_ext.c
    ../cli/abr_cli.c
)

target_include_directories(abr4 PUBLIC ../include)
target_link_libraries(abr4 PUBLIC abr_core abr_vm abr_interface abr_operators)

