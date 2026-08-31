# ---------------------------------------------------------------------------
# ABR LearnMath Plugin (Dynamic Module)
# Builds: abr_learnmath.so
# ---------------------------------------------------------------------------

add_library(abr_learnmath SHARED)

target_include_directories(abr_learnmath
    PUBLIC
        ${CMAKE_CURRENT_SOURCE_DIR}/../../include
        ${CMAKE_CURRENT_SOURCE_DIR}/../../core
        ${CMAKE_CURRENT_SOURCE_DIR}/../../vm
        ${CMAKE_CURRENT_SOURCE_DIR}/../../interface
)

# Plugin sources will be added later by CO.
# For now, this is an empty dynamic module scaffold.

# Example (future):
# target_sources(abr_learnmath PRIVATE abr_learnmath.c)

# Ensure plugin has no undefined symbols at link time
target_link_libraries(abr_learnmath
    PRIVATE
        abr_core
        abr_vm
        abr_interface
        abr_operators
        abr_stream
        abr_plugin_registry
)

