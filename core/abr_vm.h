/*
 * abr_vm.h — ABR v0.5
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

#ifndef ABR_VM_H
#define ABR_VM_H

#include <stdint.h>
#include <stddef.h>
#include "abr_context.h"
#include "abr_exec.h"

/* VM object (v0.5 minimal). */
typedef struct abr_vm {
    abr_context ctx;   /* execution context */
} abr_vm;

/* Initialize VM with initial window and width. */
void abr_vm_init(
    abr_vm* vm,
    uint64_t window,
    size_t width
);

/* Execute extraction through VM. */
uint64_t abr_vm_extract(
    abr_vm* vm,
    const uint8_t* src,
    size_t src_size,
    size_t bit_offset,
    size_t bit_length
);

/* Execute slicing through VM. */
uint64_t abr_vm_slice(
    abr_vm* vm,
    uint64_t window,
    size_t bit_offset,
    size_t bit_length
);

/* Execute plugin through VM. */
void abr_vm_plugin(
    abr_vm* vm,
    const char* plugin_name
);

#endif /* ABR_VM_H */

