/*
 * phi_stability.c — ABR v0.5
 *
 * math_v4: phi stability plugin
 *
 * Computes a stability metric based on the golden ratio (φ ≈ 1.618):
 *
 *   window -> unary(op_abs)
 *           -> binary(op_mul, rhs = 1618)
 *           -> binary(op_div, rhs = 1000)
 *
 * Phoenix Annotation (scflder):
 *   f = front (plugin input)
 *   s = second (operator-chain step)
 *   l = last (plugin output)
 *   d = degree domain (window width)
 *   r = residue domain (plugin result)
 */
#include "abr.h"
#include "abr_plugin.h"
#include "abr_math_v4_common.h"

#include <stdlib.h>

/* Forward declaration of factory. */
abr_plugin* abr_plugin_phi_stability_factory(void);

/* Create function. */
static void phi_create(abr_plugin* self)
{
    (void)self;
}

/* Execute function. */
static abr_plugin_result phi_execute(
    abr_plugin* self,
    abr_context* ctx
)
{
    (void)self;

    /* Build operator chain */
    abr_operator_chain chain;
    abr_operator_chain_init(&chain);

    /* Unary: absolute value */
    abr_unary_op op_abs =
        abr_operator_registry_get_unary("abs");
    if (op_abs)
        abr_operator_chain_add_unary(&chain, op_abs);

    /* Binary: multiply by 1618 (scaled φ) */
    abr_binary_op op_mul =
        abr_operator_registry_get_binary("mul");
    if (op_mul)
        abr_operator_chain_add_binary(&chain, op_mul, 1618);

    /* Binary: divide by 1000 (normalize) */
    abr_binary_op op_div =
        abr_operator_registry_get_binary("div");
    if (op_div)
        abr_operator_chain_add_binary(&chain, op_div, 1000);

    /* Execute chain */
    return abr_math_v4_execute_chain(ctx, &chain);
}

/* Destroy function. */
static void phi_destroy(abr_plugin* self)
{
    free(self);
}

/* Factory. */
abr_plugin* abr_plugin_phi_stability_factory(void)
{
    abr_plugin* p = (abr_plugin*)malloc(sizeof(*p));
    p->name    = "phi_stability";
    p->create  = phi_create;
    p->execute = phi_execute;
    p->destroy = phi_destroy;
    return p;
}

