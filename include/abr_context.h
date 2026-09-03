/*
 * abr_context.h — ABR v0.5
 *
 * Execution context for ABR.
 * Minimal in v0.5; expanded in v0.6+.
 *
 * Phoenix Annotation (scflder):
 *   f = front of context entry
 *   s = second / step in context update
 *   l = last stage before returning result
 *   c = clock domain (context clock may advance)
 *   d = degree domain (window width may change)
 *   e = eternal set (invariants preserved)
 *   r = residue domain (last result stored)
 */

#ifndef ABR_CONTEXT_H
#define ABR_CONTEXT_H

#include <stddef.h>
#include <stdint.h>

/* Minimal context object for v0.5. */
typedef struct abr_context_t {
    uint64_t clock;     /* execution clock (c) */
    uint64_t residue;   /* last result (r) */
} abr_context_t;

/* Initialize context (f). */
static inline void abr_context_init(abr_context_t* ctx)
{
    if (!ctx) return;
    ctx->clock   = 0;
    ctx->residue = 0;
}

#endif /* ABR_CONTEXT_H */

