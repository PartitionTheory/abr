/*
 * abr_vm.c — ABR v0.5
 *
 * Minimal VM layer for ABR.
 * Provides a lightweight execution wrapper around:
 *   - context
 *   - dispatch
 *   - execution layer
 *   - synthetic VM trace
 *
 * Phoenix Annotation (scflder):
 *   f = front (initial window)
 *   s = second (step through execution)
 *   l = last (terminal window)
 *   d = degree domain (window width)
 *   r = residue domain (last result)
 */

#include "abr_vm.h"
#include "abr_exec.h"
#include "abr_context.h"

/* Initialize VM with initial window and width. */
void abr_vm_init(
    abr_vm* vm,
    uint64_t window,
    size_t width
)
{
    if (!vm) return;
    abr_context_init(&vm->ctx, window, width);
}

/* Execute extraction through VM. */
uint64_t abr_vm_extract(
    abr_vm* vm,
    const uint8_t* src,
    size_t src_size,
    size_t bit_offset,
    size_t bit_length
)
{
    if (!vm || !src) return 0;
    return abr_exec_extract(&vm->ctx, src, src_size, bit_offset, bit_length);
}

/* Execute slicing through VM. */
uint64_t abr_vm_slice(
    abr_vm* vm,
    uint64_t window,
    size_t bit_offset,
    size_t bit_length
)
{
    if (!vm) return 0;
    return abr_exec_slice(&vm->ctx, window, bit_offset, bit_length);
}

/* Execute plugin through VM. */
void abr_vm_plugin(
    abr_vm* vm,
    const char* plugin_name
)
{
    if (!vm || !plugin_name) return;
    abr_exec_plugin(&vm->ctx, plugin_name);
}

