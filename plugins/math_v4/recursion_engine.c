/*
 * recursion_engine.c — ABR v0.5
 *
 * math_v4: recursion engine plugin
 *
 * Performs a recursive operator-chain transformation:
 *
 *   define R(n):
 *       if n == 0: return window
 *       else:
 *           window -> unary(op_shift_right)
 *                   -> binary(op_xor, rhs = n)
 *           return R(n - 1)
 *
 * Phoenix Annotation (scflder):
 *   f = front (plugin input)
 *   s = second (recursive step)
 *   l = last (plugin output)
 *   d = degree domain (window width)
 *   r = residue domain (plugin result)
 */
#include "abr.h"
#include "abr_plugin.h"
#include "abr_math_v4_common.h"
#include "abr_operators.h"
#include "abr_operator_chain.h"
#include "abr_plugin_registry.h"

#include <stdlib.h>

/* Forward declaration of factory. */
abr_plugin* abr_plugin_recursion_engine_factory(void);

/* Recursive helper. */
static uint64_t recursion_apply(
    abr_context* ctx,
    uint64_t window,
    uint64_t depth
)
{
    if (depth == 0)
        return window;

    /* Build operator chain */
    abr_operator_chain chain;
    abr_operator_chain_init(&chain);

    /* Unary: shift right */
    abr_unary_op op_shift_right =
        abr_operator_registry_get_unary("shift_right");
    if (op_shift_right)
        abr_operator_chain_add_unary(&chain, op_shift_right);

    /* Binary: XOR with depth */
    abr_binary_op op_xor =
        abr_operator_registry_get_binary("xor");
    if (op_xor)
        abr_operator_chain_add_binary(&chain, op_xor, depth);

    /* Execute chain */
    abr_plugin_result r = abr_math_v4_execute_chain(ctx, &chain);
    uint64_t out = r.window;

    /* Recurse */
    return recursion_apply(ctx, out, depth - 1);

}

/* Create function. */
static void recursion_create(abr_plugin* self)
{
    (void)self;
}

/* Execute function. */
static abr_plugin_result recursion_execute(
    abr_plugin* self,
    abr_context* ctx
)
{
    (void)self;

    /* Depth is derived from the current window. */
    uint64_t depth = (ctx->window & 0xF); /* low nibble */

    uint64_t out = recursion_apply(ctx, ctx->window, depth);

    abr_plugin_result r;
    r.window  = out;
    r.residue = ctx->residue;   /* or 0 if you want a pure transform */

return r;

}

/* Destroy function. */
static void recursion_destroy(abr_plugin* self)
{
    free(self);
}

/* Factory. */
abr_plugin* abr_plugin_recursion_engine_factory(void)
{
    abr_plugin* p = (abr_plugin*)malloc(sizeof(*p));
    p->name    = "recursion_engine";
    p->create  = recursion_create;
    p->execute = recursion_execute;
    p->destroy = recursion_destroy;
    return p;
}

