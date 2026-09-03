# ---------------------------------------------------------------------------
# ABR Plugin Registry (Static)
# Builds: libabr_plugin_registry.a
# ---------------------------------------------------------------------------

add_library(abr_plugin_registry
    abr_plugin_registry.c
)
target_include_directories(abr_plugin_registry PUBLIC ../../include)
target_link_libraries(abr_plugin_registry PUBLIC abr_plugins)

