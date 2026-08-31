# ---------------------------------------------------------------------------
# ABR Operators Library
# Builds the static operators library: libabr_operators.a
# ---------------------------------------------------------------------------

add_library(abr_operators STATIC)

target_include_directories(abr_operators
    PUBLIC
        ${CMAKE_CURRENT_SOURCE_DIR}/../include
        ${CMAKE_CURRENT_SOURCE_DIR}/../core
        ${CMAKE_CURRENT_SOURCE_DIR}/../vm
        ${CMAKE_CURRENT_SOURCE_DIR}/../interface
)

# Operator sources will be added incrementally as CO populates .c files.
# For now, this is an empty static library scaffold.

# Example (future):
# target_sources(abr_operators
#     PRIVATE
#         abr_op_domain.c
#         abr_op_window.c
#         abr_op_gradient.c
#         abr_op_coherence.c
# )

