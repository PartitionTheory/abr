# ---------------------------------------------------------------------------
# ABR Stream Library
# Builds the static stream library: libabr_stream.a
# ---------------------------------------------------------------------------

add_library(abr_stream STATIC)

target_include_directories(abr_stream
    PUBLIC
        ${CMAKE_CURRENT_SOURCE_DIR}/../include
        ${CMAKE_CURRENT_SOURCE_DIR}/../core
        ${CMAKE_CURRENT_SOURCE_DIR}/../vm
        ${CMAKE_CURRENT_SOURCE_DIR}/../interface
)

# Stream sources will be added incrementally as CO populates .c files.
# For now, this is an empty static library scaffold.

# Example (future):
# target_sources(abr_stream
#     PRIVATE
#         abr_stream.c
#         abr_stream_buffer.c
#         abr_stream_window.c
# )

