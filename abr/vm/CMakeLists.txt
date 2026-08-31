# ---------------------------------------------------------------------------
# ABR VM Library
# Builds the static VM: libabr_vm.a
# ---------------------------------------------------------------------------

add_library(abr_vm STATIC)

target_include_directories(abr_vm
    PUBLIC
        ${CMAKE_CURRENT_SOURCE_DIR}/../include
        ${CMAKE_CURRENT_SOURCE_DIR}/../core
)

# VM sources will be added incrementally as CO populates .c files.
# For now, this is an empty static library scaffold.

# Example (future):
# target_sources(abr_vm
#     PRIVATE
#         abr_vm_exec.c
#         abr_vm_state.c
#         abr_vm_gradient.c
#         abr_vm_coherence.c
# )

