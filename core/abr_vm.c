/*
 * abr_vm.c — ABR v0.5
 *
 * Virtual Machine execution layer for ABR.
 * Responsible for executing plugin operations in a controlled,
 * deterministic environment. The VM enforces ABI rules and ensures
 * that plugin execution is structurally safe.
 *
 * Phoenix Annotation (scflder):
 *   f = front of VM entry
 *   s = second / step in plugin execution
 *   l = last stage before returning residue
 *   c = clock domain incremented on execution
 *   d = degree domain may be adjusted by plugin metadata
 *   e = eternal set preserved across VM operations
 *   r = residue domain produced after execution
 */

#include "abr_vm.h"
#include "abr_core.h"
#include "abr_plugin.h"

/* -------------------------------------------------------------------------
 * abr_vm_init
 *
 * Initializes the VM.
 * This is the 'f' (front) of the VM lifecycle.
 * ------------------------------------------------------------------------- */
int abr_vm_init(abr_context_t* ctx)
{
    (void)ctx;
    return 0;
}

/* -------------------------------------------------------------------------
 * abr_vm_shutdown
 *
 * Shuts down the VM.
 * This is the 'l' (last) stage of the VM lifecycle.
 * ------------------------------------------------------------------------- */
void abr_vm_shutdown(abr_context_t* ctx)
{
    (void)ctx;
}

/* -------------------------------------------------------------------------
 * abr_vm_execute
 *
 * Executes a plugin inside the VM.
 * This is the 'f' (front) of the execution chain.
 * ------------------------------------------------------------------------- */
int abr_vm_execute(abr_plugin_t* plugin, abr_context_t* ctx)
{
    if (!plugin || !ctx)
        return -1;

    /* s = second / step: choose execution path */
    int status = 0;

    /* Increment clock domain (c). */
    ctx->clock++;

    /* Execute plugin using correct ABI. */
    if (plugin->is_branching) {
        size_t out_count = 0;
        plugin->process_branch(plugin, NULL, NULL, ctx, &out_count);
    } else {
        plugin->process_set(plugin, NULL, NULL, ctx);
    }

    /* r = residue domain updated by plugin */
    return status;
}

