# ---------------------------------------------------------------------------
# ABR Plugin Registry (Static)
# Builds: libabr_plugin_registry.a
# ---------------------------------------------------------------------------

add_library(abr_plugin_registry STATIC)

target_include_directories(abr_plugin_registry
    PUBLIC
        ${CMAKE_CURRENT_SOURCE_DIR}/../../include
        ${CMAKE_CURRENT_SOURCE_DIR}/../../core
        ${CMAKE_CURRENT_SOURCE_DIR}/../../vm
        ${CMAKE_CURRENT_SOURCE_DIR}/../../interface
)

# Registry sources will be added later by CO.
# Example (future):
# target_sources(abr_plugin_registry PRIVATE abr_plugin_registry.c)

