/*
 * abr_runtime_pipeline.c — ABR v0.5
 *
 * Canonical multi-plugin execution pipeline.
 *
 * Responsibilities:
 *   - execute a sequence of plugins
 *   - propagate context window/residue
 *   - stop on error
 *   - provide deterministic pipeline behavior
 *
 * Phoenix Annotation (scflder):
 *   f = front (initial window)
 *   s = second (pipeline step)
 *   l = last (final window)
 *   d = degree domain (pipeline length)
 *   r = residue domain (propagated result)
 */

#include "abr_runtime_pipeline.h"
#include "abr_runtime_execute.h"

abr_plugin_result abr_runtime_pipeline_execute(
    abr_plugin** plugins,
    size_t count,
    abr_context* ctx
)
{
    abr_plugin_result last = {0};

    if (!plugins || !ctx)
    {
        ctx->status_code   = -1;
        ctx->error_message = "pipeline: null plugin list or context";
        ctx->plugin_name   = "(none)";
        return last;
    }

    for (size_t i = 0; i < count; i++)
    {
        abr_plugin* p = plugins[i];
        if (!p)
        {
            ctx->status_code   = -2;
            ctx->error_message = "pipeline: null plugin instance";
            ctx->plugin_name   = "(none)";
            return last;
        }

        last = abr_runtime_execute(p, ctx);

        if (ctx->status_code != 0)
        {
            /* Stop pipeline on error */
            return last;
        }
    }

    return last;
}

