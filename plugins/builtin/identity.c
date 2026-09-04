/*
 * identity.c — ABR v0.5 builtin plugin
 *
 * Provides the identity transformation:
 *   window'  = window
 *   residue' = residue
 */

#include "abr.h"
#include <stdlib.h>

static void identity_create(struct abr_plugin* plugin)
{
    plugin->data = NULL;
}

static abr_plugin_result identity_execute(struct abr_plugin* plugin,
                                          struct abr_context* ctx)
{
    abr_plugin_result result;
    result.window  = ctx->window;
    result.residue = ctx->residue;
    return result;
}

static void identity_destroy(struct abr_plugin* plugin)
{
    /* no-op */
}

struct abr_plugin* abr_plugin_identity(void)
{
    struct abr_plugin* p = malloc(sizeof(struct abr_plugin));
    p->name    = "identity";
    p->create  = identity_create;
    p->execute = identity_execute;
    p->destroy = identity_destroy;
    p->data    = NULL;
    return p;
}
#include "abr.h"

abr_plugin* abr_plugin_identity_factory(void)
{
    abr_plugin* p = (abr_plugin*)malloc(sizeof(abr_plugin));
    if (!p)
        return NULL;

    p->name    = "identity";
    p->create  = NULL;   /* no internal state */
    p->destroy = NULL;   /* no internal state */

    p->execute = identity_execute;   /* your existing execute function */

    return p;
}

