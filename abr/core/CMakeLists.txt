# ---------------------------------------------------------------------------
# ABR Core Library
# Builds the static core: libabr_core.a
# ---------------------------------------------------------------------------

add_library(abr_core STATIC)

target_include_directories(abr_core
    PUBLIC
        ${CMAKE_CURRENT_SOURCE_DIR}/../include
)

# Core sources will be added incrementally as CO populates .c files.
# For now, this is an empty static library scaffold.

# Example (future):
# target_sources(abr_core
#     PRIVATE
#         abr_core_domain.c
#         abr_core_window.c
#         abr_core_gradient.c
# )

