/*
 * abr_dispatch.c — ABR v0.5
 *
 * Dispatch layer for the ABR runtime.
 * Responsible for routing execution requests from the core to the VM and
 * plugin registry. This module does not perform computation itself; it
 * orchestrates the flow of data and control.
 *
 * Phoenix Annotation (scflder):
 *   f = front of dispatch entry
 *   s = second / step in plugin selection
 *   l = last stage before VM execution
 *   c = clock domain incremented on dispatch
 *   d = degree domain may be adjusted by plugin metadata
 *   e = eternal set preserved across dispatch
 *   r = residue returned after VM execution
 */

#include "abr_dispatch.h"
#include "abr_core.h"
#include "abr_plugin_registry.h"
#include "abr_vm.h"

/* -------------------------------------------------------------------------
 * abr_dispatch_execute
 *
 * Main dispatch entry point.
 * This is the 'f' (front) of the dispatch chain.
 * ------------------------------------------------------------------------- */
int abr_dispatch_execute(const char* plugin_name)
{
    abr_context_t* ctx = abr_core_context();
    if (!ctx)
        return -1;

    /* s = second / step: select plugin */
    abr_plugin_t* plugin = abr_plugin_registry_get(plugin_name);
    if (!plugin)
        return -1;

    /* Increment clock domain (c). */
    ctx->clock++;

    /* l = last stage: handoff to VM */
    int status = abr_vm_execute(plugin, ctx);

    /* r = residue domain updated by VM */
    return status;
}

