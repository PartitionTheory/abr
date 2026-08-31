# ---------------------------------------------------------------------------
# ABR VM Library
# Builds the static VM: libabr_vm.a
# ---------------------------------------------------------------------------

add_library(abr_vm
    ../src/abr_vm.c
)
target_include_directories(abr_vm PUBLIC ../include)
target_link_libraries(abr_vm PUBLIC abr_core)

