# ---------------------------------------------------------------------------
# ABR Test Suite
# Builds: abr_tests
# ---------------------------------------------------------------------------

add_executable(abr_tests
    ../src/abr_core.c   # placeholder until real tests exist
)

target_include_directories(abr_tests PUBLIC ../include)
target_link_libraries(abr_tests PUBLIC abr_core)

