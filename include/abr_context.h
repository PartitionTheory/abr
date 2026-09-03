/*
 * abr_context.h — ABR v0.5
 *
 * Defines the unified ABR context object used across core, sdk,
 * plugins, pipeline, system, and VM.
 *
 * Phoenix Annotation (scflder):
 *   f = front of context creation
 *   s = second / step in context mutation
 *   l = last stage during destruction
 *   c = clock domain
 *   d = degree domain
 *   e = eternal set
 *   r = residue domain
 */

#ifndef ABR_CONTEXT_H
#define ABR_CONTEXT_H

#include <stddef.h>
#include <stdint.h>

/* Unified ABR context */
typedef struct abr_context {
    size_t clock;     /* c domain */
    size_t degree;    /* d domain */
    void*  eternal;   /* e domain */
    void*  residue;   /* r domain */
} abr_context_t;

/* Initialize context (f). */
static inline void abr_context_init(abr_context_t* ctx)
{
    if (!ctx) return;
    ctx->clock  = 0;
    ctx->degree = 0;
    ctx->eternal = NULL;
    ctx->residue = NULL;
}

/* Destroy context (l). */
static inline void abr_context_destroy(abr_context_t* ctx)
{
    (void)ctx;
    /* v0.5: no dynamic fields */
}

#endif /* ABR_CONTEXT_H */

