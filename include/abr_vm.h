/*
 * abr_vm.h — ABR v0.5
 *
 * Minimal VM layer for ABR.
 * Provides a simple execution wrapper around abr_interface_run_set().
 *
 * Phoenix Annotation (scflder):
 *   f = front of VM entry
 *   s = second / step in VM scheduling
 *   l = last stage before returning result
 *   c = clock domain (context clock may advance)
 *   d = degree domain (window width may change)
 *   e = eternal set (invariants preserved)
 *   r = residue domain (last result stored)
 */

#ifndef ABR_VM_H
#define ABR_VM_H

#include "abr_interface.h"
#include "abr_plugin.h"
#include "windowset.h"
#include "abr_context.h"
#include "abr_flags.h"

/* Minimal VM object for v0.5. */
typedef struct abr_vm {
    abr_context_t ctx;   /* execution context */
    abr_flags_t   fl;    /* execution flags   */
} abr_vm;

/* Initialize VM (f). */
static inline void abr_vm_init(abr_vm* vm)
{
    if (!vm) return;
    abr_context_init(&vm->ctx);
    abr_flags_init(&vm->fl);
}

/* Execute a plugin through the VM (l). */
static inline WindowSet abr_vm_exec(
    abr_vm* vm,
    const abr_plugin* p,
    const WindowSet* in
)
{
    return abr_interface_run_set(p, in, &vm->fl, &vm->ctx);
}

#endif /* ABR_VM_H */

