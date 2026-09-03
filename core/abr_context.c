/*
 * abr_context.c — ABR v0.5
 *
 * Implements the ABR runtime context object.
 * The context stores global runtime state used by the VM, plugin registry,
 * dispatch layer, and execution engine.
 *
 * Phoenix Annotation (scflder):
 *   f = front of runtime chain (context creation)
 *   s = second / step after core entry
 *   l = last stage during shutdown
 *   c = clock domain (runtime progression)
 *   d = degree domain (unary expansion)
 *   e = eternal set (persistent invariants)
 *   r = residue domain (post-operation remainder)
 */

#include "abr_context.h"
#include <stdlib.h>

/* -------------------------------------------------------------------------
 * abr_context_create
 *
 * Allocates and initializes a new ABR context.
 * This is the 'f' (front) of the context lifecycle.
 * ------------------------------------------------------------------------- */
abr_context_t* abr_context_create(void)
{
    abr_context_t* ctx = calloc(1, sizeof(abr_context_t));
    if (!ctx)
        return NULL;

    /* Initialize clock (c), degree (d), eternal set (e), residue (r). */
    ctx->clock = 0;
    ctx->degree = 0;
    ctx->eternal = NULL;
    ctx->residue = NULL;

    return ctx;
}

/* -------------------------------------------------------------------------
 * abr_context_destroy
 *
 * Frees the ABR context.
 * This is the 'l' (last) stage of the context lifecycle.
 * Eternal-set 'e' invariants are preserved externally.
 * ------------------------------------------------------------------------- */
void abr_context_destroy(abr_context_t* ctx)
{
    if (!ctx)
        return;

    /* Free residue 'r' if allocated. */
    if (ctx->residue)
        free(ctx->residue);

    free(ctx);
}

