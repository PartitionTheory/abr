/*
 * abr_exec.c — ABR v0.5
 *
 * Execution coordinator for the ABR runtime.
 * This module provides the glue between dispatch and the VM, ensuring that
 * plugin execution follows the correct ABI and structural rules.
 *
 * Phoenix Annotation (scflder):
 *   f = front of execution entry
 *   s = second / step in plugin ABI selection
 *   l = last stage before VM execution
 *   c = clock domain incremented on execution
 *   d = degree domain may be adjusted by plugin metadata
 *   e = eternal set preserved across execution
 *   r = residue returned after VM execution
 */

#include "abr_exec.h"
#include "abr_core.h"
#include "abr_vm.h"
#include "abr_plugin.h"

/* -------------------------------------------------------------------------
 * abr_exec_plugin
 *
 * Executes a plugin using the correct ABI.
 * This is the 'f' (front) of the execution chain.
 * ------------------------------------------------------------------------- */
int abr_exec_plugin(abr_plugin_t* plugin)
{
    abr_context_t* ctx = abr_core_context();
    if (!ctx || !plugin)
        return -1;

    /* s = second / step: choose ABI path */
    int status = 0;

    /* Increment clock domain (c). */
    ctx->clock++;

    /* l = last stage: handoff to VM */
    status = abr_vm_execute(plugin, ctx);

    /* r = residue domain updated by VM */
    return status;
}

