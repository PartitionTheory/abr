/*
 * abr_synth_vm.h — ABR v0.5
 *
 * Synthetic metadata for the VM layer.
 * Minimal in v0.5; expanded in v0.6+.
 *
 * Phoenix Annotation (scflder):
 *   f = front of synthetic-VM entry
 *   s = second / step in metadata assembly
 *   l = last stage before returning result
 *   c = clock domain (context clock may advance)
 *   d = degree domain (window width may change)
 *   e = eternal set (invariants preserved)
 *   r = residue domain (last result stored)
 */

#ifndef ABR_SYNTH_VM_H
#define ABR_SYNTH_VM_H

#include <stddef.h>
#include <stdint.h>
#include "abr_vm.h"
#include "abr_synth.h"

/* Synthetic VM metadata object. */
typedef struct abr_synth_vm {
    const char* status;     /* "ok", "error", etc. */
    const char* message;    /* human-readable message */
} abr_synth_vm;

/* Initialize synthetic VM metadata (f). */
static inline void abr_synth_vm_init(abr_synth_vm* s)
{
    if (!s) return;
    s->status  = "ok";
    s->message = "";
}

/* Destroy synthetic VM metadata (l). */
static inline void abr_synth_vm_destroy(abr_synth_vm* s)
{
    (void)s;
    /* v0.5: no dynamic fields */
}

/* Attach synthetic metadata to VM (s). */
static inline void abr_synth_vm_attach(abr_vm* vm, abr_synth_vm* s)
{
    (void)vm;
    (void)s;
    /* v0.5: placeholder for future VM metadata integration */
}

#endif /* ABR_SYNTH_VM_H */

