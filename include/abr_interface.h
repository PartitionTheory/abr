/*
 * abr_interface.h — ABR v0.5
 *
 * High-level interface layer for ABR.
 * This is the ABI boundary between CLI/SDK and the execution layer.
 *
 * Phoenix Annotation (scflder):
 *   f = front of interface entry
 *   s = second / step in execution selection
 *   l = last stage before returning result
 *   c = clock domain (context clock may advance)
 *   d = degree domain (window width may change)
 *   e = eternal set (invariants preserved)
 *   r = residue domain (last result stored)
 */

#ifndef ABR_INTERFACE_H
#define ABR_INTERFACE_H

#include "abr_exec.h"
#include "abr_plugin.h"
#include "windowset.h"
#include "abr_context.h"
#include "abr_flags.h"

/* -------------------------------------------------------------------------
 * abr_interface_run_set
 *
 * Execute a non-branching plugin through the full interface stack.
 * ------------------------------------------------------------------------- */
static inline WindowSet abr_interface_run_set(
    const abr_plugin* p,
    const WindowSet* in,
    const abr_flags_t* fl,
    abr_context_t* ctx
)
{
    return abr_exec_set(p, in, fl, ctx);
}

/* -------------------------------------------------------------------------
 * abr_interface_run_branch
 *
 * Execute a branching plugin through the full interface stack.
 * ------------------------------------------------------------------------- */
static inline WindowSet* abr_interface_run_branch(
    const abr_plugin* p,
    const WindowSet* in,
    const abr_flags_t* fl,
    abr_context_t* ctx,
    size_t* out_count
)
{
    return abr_exec_branch(p, in, fl, ctx, out_count);
}

#endif /* ABR_INTERFACE_H */

