/*
 * abr_runtime_execute.c — ABR v0.5
 *
 * Canonical runtime execution entrypoint.
 *
 * Responsibilities:
 *   - execute a plugin instance
 *   - update context window/residue
 *   - handle errors and status codes
 *   - provide deterministic runtime behavior
 *
 * Phoenix Annotation (scflder):
 *   f = front (initial window)
 *   s = second (plugin execution)
 *   l = last (final window)
 *   d = degree domain (window width)
 *   r = residue domain (propagated result)
 */

#include "abr_runtime_execute.h"
#include "abr_runtime_context.h"

abr_plugin_result abr_runtime_execute(
    abr_plugin* plugin,
    abr_context* ctx
)
{
    if (!plugin || !ctx)
    {
        abr_plugin_result err = {0};
        err.window  = 0;
        err.residue = 0;

        ctx->status_code   = -1;
        ctx->error_message = "runtime: null plugin or context";
        ctx->plugin_name   = "(none)";

        return err;
    }

    ctx->plugin_name   = plugin->name;
    ctx->status_code   = 0;
    ctx->error_message = NULL;

    /* Execute plugin */
    abr_plugin_result result = plugin->execute(plugin, ctx);

    /* Update context */
    ctx->window  = result.window;
    ctx->residue = result.residue;

    return result;
}

