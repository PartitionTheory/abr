# ---------------------------------------------------------------------------
# ABR CLI Executable
# Builds: abr
# ---------------------------------------------------------------------------

add_executable(abr)

target_include_directories(abr
    PUBLIC
        ${CMAKE_CURRENT_SOURCE_DIR}/../include
        ${CMAKE_CURRENT_SOURCE_DIR}/../core
        ${CMAKE_CURRENT_SOURCE_DIR}/../vm
        ${CMAKE_CURRENT_SOURCE_DIR}/../interface
        ${CMAKE_CURRENT_SOURCE_DIR}/../operators
        ${CMAKE_CURRENT_SOURCE_DIR}/../stream
        ${CMAKE_CURRENT_SOURCE_DIR}/../plugins
)

# CLI sources will be added later by CO.
# Example (future):
# target_sources(abr PRIVATE abr_cli_main.c)

# Link against all ABR static libraries and plugin registry
target_link_libraries(abr
    PRIVATE
        abr_core
        abr_vm
        abr_interface
        abr_operators
        abr_stream
        abr_plugins
        abr_plugin_registry
)

