# ---------------------------------------------------------------------------
# ABR Interface Library
# Builds the static interface: libabr_interface.a
# ---------------------------------------------------------------------------

add_library(abr_interface
    ../src/abr_interface.c
)
target_include_directories(abr_interface PUBLIC ../include)
target_link_libraries(abr_interface PUBLIC abr_core abr_vm)

