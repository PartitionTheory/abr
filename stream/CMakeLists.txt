# ---------------------------------------------------------------------------
# ABR Stream Library
# Builds the static stream library: libabr_stream.a
# ---------------------------------------------------------------------------

add_library(abr_stream
    ../src/abr_stream.c
)
target_include_directories(abr_stream PUBLIC ../include)
target_link_libraries(abr_stream PUBLIC abr_core)

