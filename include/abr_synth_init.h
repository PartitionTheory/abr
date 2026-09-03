/*
 * abr_synth_init.h — ABR v0.5
 *
 * Unified synthetic metadata initializer.
 * Minimal in v0.5; expanded in v0.6+.
 *
 * Phoenix Annotation (scflder):
 *   f = front of synthetic init entry
 *   s = second / step in metadata assembly
 *   l = last stage before returning result
 *   c = clock domain (context clock may advance)
 *   d = degree domain (window width may change)
 *   e = eternal set (invariants preserved)
 *   r = residue domain (last result stored)
 */

#ifndef ABR_SYNTH_INIT_H
#define ABR_SYNTH_INIT_H

#include "abr_synth.h"
#include "abr_synth_vm.h"

/* -------------------------------------------------------------------------
 * abr_synth_set
 *
 * Set status and message on a synthetic object.
 * ------------------------------------------------------------------------- */
static inline void abr_synth_set(
    abr_synth* s,
    const char* status,
    const char* message
)
{
    if (!s) return;
    s->status  = status;
    s->message = message;
}

/* -------------------------------------------------------------------------
 * abr_synth_vm_set
 *
 * Set status and message on a synthetic VM object.
 * ------------------------------------------------------------------------- */
static inline void abr_synth_vm_set(
    abr_synth_vm* s,
    const char* status,
    const char* message
)
{
    if (!s) return;
    s->status  = status;
    s->message = message;
}

#endif /* ABR_SYNTH_INIT_H */

