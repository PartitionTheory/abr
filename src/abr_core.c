/*
 * ABR-Rebirth: Core Runtime Implementation
 *
 * Implements the fundamental runtime and context management functions
 * declared in abr.h and abr_core.h.
 */
#include "abr_synth_init.h"

#include "abr.h"
#include "abr_core.h"
#include "abr_vm.h"
#include "abr_interface.h"
#include "abr_plugin.h"

#include <stdlib.h>
#include <string.h>

/* ------------------------------------------------------------------------- */
/* Version string                                                            */
/* ------------------------------------------------------------------------- */

static const char *ABR_VERSION_STRING = "ABR-Rebirth-0.1.0";

/* ------------------------------------------------------------------------- */
/* Runtime and context lifecycle                                             */
/* ------------------------------------------------------------------------- */

abr_runtime_t *abr_init(void)
{
    abr_runtime_t *rt = (abr_runtime_t *)malloc(sizeof(abr_runtime_t));
    if (!rt) {
        return NULL;
    }

    memset(rt, 0, sizeof(*rt));
    rt->initialized = 1;

    /* Plugin registry, operator table, and VM state will be wired up
     * incrementally as Phase 3 progresses. For now, they are NULL. */

    rt->plugin_registry = NULL;
    rt->vm_state        = NULL;

    return rt;
}

void abr_shutdown(abr_runtime_t *rt)
{
    if (!rt) {
        return;
    }

    /* VM state, plugin registry, and operator table cleanup will be added
     * once those subsystems are populated. */

    rt->initialized = 0;
    free(rt);
}

abr_context_t *abr_context_create(abr_runtime_t *rt)
{
    if (!rt || !rt->initialized) {
        return NULL;
    }

    abr_context_t *ctx = (abr_context_t *)malloc(sizeof(abr_context_t));
    if (!ctx) {
        return NULL;
    }

    memset(ctx, 0, sizeof(*ctx));
	/* Bind context to runtime subsystems */
	ctx->operator_registry = rt->operators;
	ctx->plugin_registry   = rt->plugin_registry;
	ctx->vm_state          = rt->vm_state;

	/* Initialize context-local subsystems */
	ctx->stream_state      = NULL;
	ctx->dispatch_state    = NULL;
	ctx->synth_sets        = NULL;

	/* Load synthetic operators */
	abr_synth_init(ctx);

    return ctx;
}

void abr_context_destroy(abr_context_t *ctx)
{
    if (!ctx) {
        return;
    }

    /* VM execution state cleanup will be added when VM wiring is complete. */

    free(ctx);
}

const char *abr_version(void)
{
    return ABR_VERSION_STRING;
}

