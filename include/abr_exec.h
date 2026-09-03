/*
 * abr_exec.h — ABR v0.5
 *
 * Execution layer for ABR.
 * This is the ABI boundary between CLI/SDK and the dispatch layer.
 *
 * Phoenix Annotation (scflder):
 *   f = front of execution entry
 *   s = second / step in dispatch selection
 *   l = last stage before returning result
 *   c = clock domain (context clock may advance)
 *   d = degree domain (window width may change)
 *   e = eternal set (invariants preserved)
 *   r = residue domain (last result stored)
 */

#ifndef ABR_EXEC_H
#define ABR_EXEC_H

#include "abr_dispatch.h"
#include "abr_plugin.h"
#include "windowset.h"
#include "abr_context.h"
#include "abr_flags.h"

/* -------------------------------------------------------------------------
 * abr_exec_set
 *
 * Execute a non-branching plugin.
 * ------------------------------------------------------------------------- */
static inline WindowSet abr_exec_set(
    const abr_plugin* p,
    const WindowSet* in,
    const abr_flags_t* fl,
    abr_context_t* ctx
)
{
    return abr_dispatch_set(p, in, fl, ctx);
}

/* -------------------------------------------------------------------------
 * abr_exec_branch
 *
 * Execute a branching plugin.
 * ------------------------------------------------------------------------- */
static inline WindowSet* abr_exec_branch(
    const abr_plugin* p,
    const WindowSet* in,
    const abr_flags_t* fl,
    abr_context_t* ctx,
    size_t* out_count
)
{
    return abr_dispatch_branch(p, in, fl, ctx, out_count);
}

#endif /* ABR_EXEC_H */

