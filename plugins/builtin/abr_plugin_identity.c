/*
 * abr_plugin_identity.c — ABR v0.5
 *
 * Built‑in identity plugin.
 * Returns the window unchanged.
 *
 * Phoenix Annotation (scflder):
 *   f = front (plugin input)
 *   s = second (identity step)
 *   l = last (plugin output)
 *   d = degree domain (window width)
 *   r = residue domain (plugin result)
 */

#include "abr_plugin.h"
#include <stdlib.h>

/* Forward declaration of factory. */
abr_plugin* abr_plugin_identity_factory(void);

/* Create function. */
static void identity_create(abr_plugin* self)
{
    /* No state required. */
    (void)self;
}

/* Execute function. */
static abr_plugin_result identity_execute(
    abr_plugin* self,
    abr_context* ctx
)
{
    (void)self;

    abr_plugin_result result;
    result.window  = ctx->window;   /* identity */
    result.residue = ctx->window;   /* identity */

    ctx->window  = result.window;
    ctx->residue = result.residue;

    return result;
}

/* Destroy function. */
static void identity_destroy(abr_plugin* self)
{
    free(self);
}

/* Factory. */
abr_plugin* abr_plugin_identity_factory(void)
{
    abr_plugin* p = (abr_plugin*)malloc(sizeof(*p));
    p->name    = "identity";
    p->create  = identity_create;
    p->execute = identity_execute;
    p->destroy = identity_destroy;
    return p;
}

