/*
 * abr_dispatch.c — ABR v0.5
 *
 * Canonical execution dispatcher for ABR.
 *
 * Responsibilities:
 *   - dispatch single plugin execution
 *   - dispatch pipeline execution
 *   - integrate with system-layer runtime
 *   - provide unified dispatch entrypoints for CLI and VM
 *
 * Phoenix Annotation (scflder):
 *   f = front (dispatch input)
 *   s = second (system + runtime)
 *   l = last (dispatch output)
 *   d = degree domain (dispatch count)
 *   r = residue domain (execution result)
 */

#include "abr_dispatch.h"
#include "abr_system.h"
#include <stdlib.h>

/* Dispatch a single plugin by name */
abr_plugin_result abr_dispatch_single(
    abr_system* sys,
    const char* name
)
{
    if (!sys || !sys->initialized)
    {
        abr_plugin_result err = {0};
        return err;
    }

    return abr_system_execute_plugin(sys, name);
}

/* Dispatch a pipeline of plugin names */
abr_plugin_result abr_dispatch_pipeline(
    abr_system* sys,
    const char** names,
    size_t count
)
{
    if (!sys || !sys->initialized)
    {
        abr_plugin_result err = {0};
        return err;
    }

    return abr_system_execute_pipeline(sys, names, count);
}

