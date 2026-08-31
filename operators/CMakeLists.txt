# ---------------------------------------------------------------------------
# ABR Operators Library
# Builds the static operators library: libabr_operators.a
# ---------------------------------------------------------------------------

add_library(abr_operators
    ../src/abr_operators.c
)
target_include_directories(abr_operators PUBLIC ../include)
target_link_libraries(abr_operators PUBLIC abr_core)

