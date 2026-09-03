/*
 * abr_math_v4_common.h — ABR v0.5
 *
 * Shared infrastructure for all math_v4 plugins.
 * Provides:
 *   - common metadata
 *   - operator-chain helpers
 *   - plugin-result helpers
 *   - unified ABI for math_v4 plugin families
 *
 * Phoenix Annotation (scflder):
 *   f = front (plugin input)
 *   s = second (math_v4 step)
 *   l = last (plugin output)
 *   d = degree domain (window width)
 *   r = residue domain (plugin result)
 */

#ifndef ABR_MATH_V4_COMMON_H
#define ABR_MATH_V4_COMMON_H

#include <stdint.h>
#include "abr_plugin.h"
#include "abr_operator_chain.h"
#include "abr_operator_registry.h"

/* Common math_v4 plugin result helper. */
static inline abr_plugin_result abr_math_v4_result(
    abr_context* ctx,
    uint64_t window
)
{
    abr_plugin_result result;
    result.window  = window;
    result.residue = window;

    ctx->window  = window;
    ctx->residue = window;

    return result;
}

/* Common operator-chain execution helper. */
static inline abr_plugin_result abr_math_v4_execute_chain(
    abr_context* ctx,
    abr_operator_chain* chain
)
{
    uint64_t out = abr_operator_chain_execute(chain, ctx, ctx->window);
    return abr_math_v4_result(ctx, out);
}

#endif /* ABR_MATH_V4_COMMON_H */

