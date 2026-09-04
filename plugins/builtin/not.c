/*
 * not.c — ABR v0.5 builtin plugin
 *
 * Provides the bitwise NOT transformation:
 *   window'  = ~window
 *   residue' = residue
 */

#include "abr.h"
#include <stdlib.h>

static void not_create(struct abr_plugin* plugin)
{
    plugin->data = NULL;
}

static abr_plugin_result not_execute(struct abr_plugin* plugin,
                                     struct abr_context* ctx)
{
    abr_plugin_result result;
    result.window  = ~ctx->window;
    result.residue = ctx->residue;
    return result;
}

static void not_destroy(struct abr_plugin* plugin)
{
    /* no-op */
}

struct abr_plugin* abr_plugin_not(void)
{
    struct abr_plugin* p = malloc(sizeof(struct abr_plugin));
    p->name    = "not";
    p->create  = not_create;
    p->execute = not_execute;
    p->destroy = not_destroy;
    p->data    = NULL;
    return p;
}
#include "abr.h"

abr_plugin* abr_plugin_not_factory(void)
{
    abr_plugin* p = (abr_plugin*)malloc(sizeof(abr_plugin));
    if (!p)
        return NULL;

    p->name    = "not";
    p->create  = NULL;
    p->destroy = NULL;

    p->execute = not_execute;   /* your existing execute function */

    return p;
}

