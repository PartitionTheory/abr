#include "abr_context.h"
#include <stdlib.h>

abr_context_t* abr_context_create(struct abr_runtime* rt)
{
    abr_context_t* ctx = calloc(1, sizeof(abr_context_t));
    ctx->operator_registry = NULL;
    ctx->plugin_registry   = NULL;
    ctx->synth_sets        = NULL;
    ctx->vm_state          = NULL;
    ctx->stream_state      = NULL;
    ctx->dispatch_state    = NULL;

    /* runtime pointer is stored inside context if needed */
    (void)rt;

    return ctx;
}

void abr_context_destroy(abr_context_t* ctx)
{
    free(ctx);
}

