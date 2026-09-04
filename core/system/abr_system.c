/*
 * abr_system.c — ABR v0.5
 *
 * Canonical system-layer runtime.
 *
 * Responsibilities:
 *   - initialize runtime context
 *   - initialize plugin registry
 *   - invoke unified plugin loader
 *   - provide system-level execution entrypoints
 *   - bridge CLI/VM to runtime pipeline
 *
 * Phoenix Annotation (scflder):
 *   f = front (system initialization)
 *   s = second (loader + registry)
 *   l = last (runtime ready)
 *   d = degree domain (system state)
 *   r = residue domain (execution result)
 */

#include "abr_system.h"
#include "abr_runtime_context.h"
#include "abr_plugin_loader.h"
#include "abr_plugin_registry.h"
#include "abr_runtime_execute.h"
#include "abr_runtime_pipeline.h"
#include <stdlib.h>

/* Initialize the ABR system */
void abr_system_init(abr_system* sys)
{
    if (!sys)
        return;

    /* Initialize context */
    sys->ctx = (abr_context*)malloc(sizeof(abr_context));
    sys->ctx->window       = 0;
    sys->ctx->residue      = 0;
    sys->ctx->plugin_name  = NULL;
    sys->ctx->status_code  = 0;
    sys->ctx->error_message = NULL;
    sys->ctx->flags        = 0;

   /* Initialize plugin registry */
   abr_plugin_registry_init();

   /* Register builtin plugins */
   abr_plugin_loader_builtin_register_all();

   /* Register math_v4 plugins */
   abr_plugin_loader_math_v4_register_all();

    sys->initialized = 1;
}

/* Destroy system */
void abr_system_destroy(abr_system* sys)
{
    if (!sys)
        return;

    if (sys->ctx)
        free(sys->ctx);

    sys->initialized = 0;
}

/* Execute a single plugin by name */
abr_plugin_result abr_system_execute_plugin(
    abr_system* sys,
    const char* name
)
{
    abr_plugin_result result = {0};

    if (!sys || !sys->initialized)
        return result;

    abr_plugin* p = abr_plugin_registry_create_by_name(name);
    if (!p)
    {
        sys->ctx->status_code   = -1;
        sys->ctx->error_message = "system: plugin not found";
        sys->ctx->plugin_name   = name;
        return result;
    }

    result = abr_runtime_execute(p, sys->ctx);

    if (p->destroy)
        p->destroy(p);

    return result;
}

/* Execute a pipeline of plugin names */
abr_plugin_result abr_system_execute_pipeline(
    abr_system* sys,
    const char** names,
    size_t count
)
{
    abr_plugin_result result = {0};

    if (!sys || !sys->initialized)
        return result;

    /* Allocate plugin instances */
    abr_plugin** plugins = (abr_plugin**)malloc(sizeof(abr_plugin*) * count);

    for (size_t i = 0; i < count; i++)
        plugins[i] = abr_plugin_registry_create_by_name(names[i]);

    result = abr_runtime_pipeline_execute(plugins, count, sys->ctx);

    /* Destroy plugin instances */
    for (size_t i = 0; i < count; i++)
        if (plugins[i] && plugins[i]->destroy)
            plugins[i]->destroy(plugins[i]);

    free(plugins);

    return result;
}

