# Phase‑3 CLI (split/join)
add_executable(abr
    abr_cli_dispatch.c
    cli_split.c
    cli_join.c
    main_phase3.c
)

target_include_directories(abr PUBLIC ../include)
target_link_libraries(abr PUBLIC
    abr_core
    abr_stream
    abr_vm
    abr_operators
    abr_plugin_registry
    abr_math_v4_plugins
)

