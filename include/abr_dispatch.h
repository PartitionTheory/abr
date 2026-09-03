/*
 * abr_dispatch.h — ABR v0.5
 *
 * Dispatch layer for plugin execution.
 * This is the ABI boundary between CLI, SDK, VM, and plugin registry.
 *
 * Phoenix Annotation (scflder):
 *   f = front of dispatch entry
 *   s = second / step in plugin selection
 *   l = last stage before plugin execution
 *   c = clock domain (context clock may advance)
 *   d = degree domain (window width may change)
 *   e = eternal set (invariants preserved)
 *   r = residue domain (last result stored)
 */

#ifndef ABR_DISPATCH_H
#define ABR_DISPATCH_H

#include "abr_plugin.h"
#include "windowset.h"
#include "abr_context.h"
#include "abr_flags.h"

/* -------------------------------------------------------------------------
 * abr_dispatch_set
 *
 * Non-branching plugin dispatch.
 * ------------------------------------------------------------------------- */
static inline WindowSet abr_dispatch_set(
    const abr_plugin* p,
    const WindowSet* in,
    const abr_flags_t* fl,
    abr_context_t* ctx
)
{
    if (!p || !p->process_set)
        return *in; /* identity */

    return p->process_set(in, fl, ctx);
}

/* -------------------------------------------------------------------------
 * abr_dispatch_branch
 *
 * Branching plugin dispatch.
 * ------------------------------------------------------------------------- */
static inline WindowSet* abr_dispatch_branch(
    const abr_plugin* p,
    const WindowSet* in,
    const abr_flags_t* fl,
    abr_context_t* ctx,
    size_t* out_count
)
{
    if (!p || !p->process_branch) {
        *out_count = 1;
        WindowSet* ws = malloc(sizeof(WindowSet));
        *ws = *in;
        return ws;
    }

    return p->process_branch(in, fl, ctx, out_count);
}

#endif /* ABR_DISPATCH_H */

