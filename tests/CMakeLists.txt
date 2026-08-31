# ---------------------------------------------------------------------------
# ABR Test Suite (Phase 4 Placeholder)
# ---------------------------------------------------------------------------

add_library(abr_tests STATIC
    ../src/abr_core.c
)

target_include_directories(abr_tests PUBLIC ../include)

