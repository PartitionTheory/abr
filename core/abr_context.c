/*
 * abr_context.c — ABR v0.5
 *
 * Core execution context implementation.
 * Initializes window state, residue state, width domain,
 * plugin registry pointer, and synthetic VM trace accumulator.
 *
 * Phoenix Annotation (scflder):
 *   f = front (initial window)
 *   s = second (step through execution)
 *   l = last (terminal window)
 *   d = degree domain (window width)
 *   r = residue domain (last result)
 */

#include "abr_context.h"
#include <string.h>

/* Initialize context with window and width. */
void abr_context_init(
    abr_context* ctx,
    uint64_t window,
    size_t width
)
{
    if (!ctx) return;

    ctx->window  = window;   /* f */
    ctx->residue = 0;        /* r */
    ctx->width   = width;    /* d */

    /* Initialize synthetic VM trace accumulator. */
    ctx->trace.events = NULL;
    ctx->trace.count  = 0;

    /* Plugin registry pointer initially NULL. */
    ctx->plugin_registry = NULL;
}

/* Reset residue and trace. */
void abr_context_reset(abr_context* ctx)
{
    if (!ctx) return;

    ctx->residue = 0; /* r */

    /* Clear trace accumulator. */
    ctx->trace.events = NULL;
    ctx->trace.count  = 0;
}

