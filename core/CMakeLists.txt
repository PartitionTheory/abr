# ---------------------------------------------------------------------------
# ABR Core Library
# Builds the static core: libabr_core.a
# ---------------------------------------------------------------------------

add_library(abr_core
    ../src/abr_core.c
)
target_include_directories(abr_core PUBLIC ../include)

