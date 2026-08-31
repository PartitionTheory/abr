# ---------------------------------------------------------------------------
# ABR Plugin System (Hybrid Architecture)
# Builds:
#   - Static plugin registry: libabr_plugins.a
#   - Dynamic plugin modules: *.so
# ---------------------------------------------------------------------------

# Plugin registry (static)
add_library(abr_plugins STATIC)

target_include_directories(abr_plugins
    PUBLIC
        ${CMAKE_CURRENT_SOURCE_DIR}/../include
        ${CMAKE_CURRENT_SOURCE_DIR}/../core
        ${CMAKE_CURRENT_SOURCE_DIR}/../vm
        ${CMAKE_CURRENT_SOURCE_DIR}/../interface
)

# Registry sources will be added later by CO.
# Example (future):
# target_sources(abr_plugins PRIVATE abr_plugin_registry.c)

# ---------------------------------------------------------------------------
# Dynamic plugin modules
# ---------------------------------------------------------------------------

add_subdirectory(registry)
add_subdirectory(learnmath)

