/*
 * abr_operator_chain.c — ABR v0.5
 *
 * Canonical operator-chain subsystem for ABR.
 *
 * Responsibilities:
 *   - maintain ordered list of unary and binary operators
 *   - apply operators sequentially to a window
 *   - integrate with math_v4 plugin execution
 *   - provide deterministic operator-chain behavior
 *
 * Phoenix Annotation (scflder):
 *   f = front (initial window)
 *   s = second (operator-chain step)
 *   l = last (final window)
 *   d = degree domain (chain length)
 *   r = residue domain (propagated result)
 */

#include "abr_operator_chain.h"
#include "abr_operators.h"
#include "abr_plugin_result.h"
#include "abr_runtime_context.h"
#include <stdlib.h>

/* Initialize chain */
void abr_operator_chain_init(abr_operator_chain* chain)
{
    chain->count = 0;
}

/* Add unary operator */
void abr_operator_chain_add_unary(
    abr_operator_chain* chain,
    abr_unary_op op
)
{
    if (chain->count < ABR_OPERATOR_CHAIN_MAX)
    {
        chain->ops[chain->count].type = ABR_OP_UNARY;
        chain->ops[chain->count].unary = op;
        chain->count++;
    }
}

/* Add binary operator */
void abr_operator_chain_add_binary(
    abr_operator_chain* chain,
    abr_binary_op op,
    uint64_t rhs
)
{
    if (chain->count < ABR_OPERATOR_CHAIN_MAX)
    {
        chain->ops[chain->count].type = ABR_OP_BINARY;
        chain->ops[chain->count].binary = op;
        chain->ops[chain->count].rhs = rhs;
        chain->count++;
    }
}

/* Execute chain */
abr_plugin_result abr_operator_chain_execute(
    abr_operator_chain* chain,
    abr_context* ctx
)
{
    abr_plugin_result result;
    result.window  = ctx->window;
    result.residue = ctx->residue;

    for (size_t i = 0; i < chain->count; i++)
    {
        abr_operator_step* step = &chain->ops[i];

        if (step->type == ABR_OP_UNARY)
        {
            result.window = step->unary(result.window);
        }
        else if (step->type == ABR_OP_BINARY)
        {
            result.window = step->binary(result.window, step->rhs);
        }
    }

    return result;
}

