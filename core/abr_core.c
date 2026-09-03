/*
 * abr_core.c — ABR v0.5
 *
 * Central core engine for ABR.
 * Provides unified execution semantics over:
 *   - VM layer
 *   - execution layer
 *   - dispatch layer
 *   - synthetic VM trace
 *
 * Phoenix Annotation (scflder):
 *   f = front (initial window)
 *   s = second (step through execution)
 *   l = last (terminal window)
 *   d = degree domain (window width)
 *   r = residue domain (last result)
 */

#include "abr_core.h"
#include "abr_vm.h"
#include "abr_exec.h"

/* Initialize core engine with initial window and width. */
void abr_core_init(
    abr_core* core,
    uint64_t window,
    size_t width
)
{
    if (!core) return;
    abr_vm_init(&core->vm, window, width);
}

/* Execute extraction through core engine. */
uint64_t abr_core_extract(
    abr_core* core,
    const uint8_t* src,
    size_t src_size,
    size_t bit_offset,
    size_t bit_length
)
{
    if (!core || !src) return 0;
    return abr_vm_extract(&core->vm, src, src_size, bit_offset, bit_length);
}

/* Execute slicing through core engine. */
uint64_t abr_core_slice(
    abr_core* core,
    uint64_t window,
    size_t bit_offset,
    size_t bit_length
)
{
    if (!core) return 0;
    return abr_vm_slice(&core->vm, window, bit_offset, bit_length);
}

/* Execute plugin through core engine. */
void abr_core_plugin(
    abr_core* core,
    const char* plugin_name
)
{
    if (!core || !plugin_name) return;
    abr_vm_plugin(&core->vm, plugin_name);
}

