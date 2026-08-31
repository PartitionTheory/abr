# ---------------------------------------------------------------------------
# ABR Interface Library
# Builds the static interface: libabr_interface.a
# ---------------------------------------------------------------------------

add_library(abr_interface STATIC)

target_include_directories(abr_interface
    PUBLIC
        ${CMAKE_CURRENT_SOURCE_DIR}/../include
        ${CMAKE_CURRENT_SOURCE_DIR}/../core
        ${CMAKE_CURRENT_SOURCE_DIR}/../vm
)

# Interface sources will be added incrementally as CO populates .c files.
# For now, this is an empty static library scaffold.

# Example (future):
# target_sources(abr_interface
#     PRIVATE
#         abr_interface_api.c
#         abr_interface_struct.c
#         abr_interface_validate.c
# )

