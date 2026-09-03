/*
 * abr_core.c — ABR v0.5
 *
 * Core runtime coordinator for the ABR system.
 * This file initializes the runtime, binds the VM, dispatch layer,
 * operator set, and plugin registry into a coherent execution environment.
 *
 * Phoenix Annotation (scflder):
 *   f = front of runtime initialization sequence
 *   s = second / step in the boot chain
 *   l = last stage before VM activation
 *   c = clock domain for runtime progression
 *   d = degree expansion for unary operations
 *   e = eternal set (persistent invariants)
 *   r = residue propagation after operator execution
 *
 * These variables describe structural behaviour, not code symbols.
 */

#include "abr_core.h"
#include "abr_context.h"
#include "abr_dispatch.h"
#include "abr_exec.h"
#include "abr_plugin.h"
#include "abr_vm.h"

#include <stdlib.h>

/* -------------------------------------------------------------------------
 * Core State
 * ------------------------------------------------------------------------- */

static abr_context_t* g_ctx = NULL;

/* -------------------------------------------------------------------------
 * abr_core_init
 *
 * Initializes the ABR runtime.
 * This is the 'f' (front) of the boot sequence.
 * It establishes the context, loads plugins, and prepares the VM.
 * ------------------------------------------------------------------------- */
int abr_core_init(void)
{
    g_ctx = abr_context_create();
    if (!g_ctx)
        return -1;

    /* s = second step: load plugins */
    if (abr_plugin_registry_init(g_ctx) != 0)
        return -1;

    /* l = last step before VM activation */
    if (abr_vm_init(g_ctx) != 0)
        return -1;

    return 0;
}

/* -------------------------------------------------------------------------
 * abr_core_shutdown
 *
 * Shuts down the ABR runtime.
 * Residue 'r' is cleared, eternal-set 'e' invariants are preserved.
 * ------------------------------------------------------------------------- */
void abr_core_shutdown(void)
{
    if (!g_ctx)
        return;

    abr_vm_shutdown(g_ctx);
    abr_plugin_registry_shutdown(g_ctx);
    abr_context_destroy(g_ctx);

    g_ctx = NULL;
}

/* -------------------------------------------------------------------------
 * abr_core_context
 *
 * Returns the global context.
 * This exposes the clock 'c' and degree 'd' domains indirectly.
 * ------------------------------------------------------------------------- */
abr_context_t* abr_core_context(void)
{
    return g_ctx;
}

