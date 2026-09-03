# ---------------------------------------------------------------------------
# ABR Plugin System (Hybrid Architecture)
# Builds:
#   - Static plugin core: libabr_plugins.a
#   - Static plugin registry: libabr_plugin_registry.a
#   - Pure‑math v0.4 plugin suite: libabr_math_v4_plugins.a
# ---------------------------------------------------------------------------

add_library(abr_plugins
    ../src/abr_plugin.c
)
target_include_directories(abr_plugins PUBLIC ../include)
target_link_libraries(abr_plugins PUBLIC abr_core abr_interface abr_operators)

add_subdirectory(registry)
add_subdirectory(learnmath)
add_subdirectory(math_v4)

