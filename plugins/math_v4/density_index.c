/*
 * density_index.c — ABR v0.5
 *
 * math_v4: density index plugin
 *
 * Computes a simple density metric:
 *
 *   window -> unary(op_popcount)
 *           -> binary(op_mul, rhs = 2)
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
abr_plugin* abr_plugin_density_index_factory(void);

/* Create function. */
static void density_create(abr_plugin* self)
{
    (void)self;
}

/* Execute function. */
static abr_plugin_result density_execute(
    abr_plugin* self,
    abr_context* ctx
)
{
    (void)self;

    /* Build operator chain */
    abr_operator_chain chain;
    abr_operator_chain_init(&chain);

    /* Unary: popcount */
    abr_unary_op op_popcount =
        abr_operator_registry_get_unary("popcount");
    if (op_popcount)
        abr_operator_chain_add_unary(&chain, op_popcount);

    /* Binary: multiply by 2 */
    abr_binary_op op_mul =
        abr_operator_registry_get_binary("mul");
    if (op_mul)
        abr_operator_chain_add_binary(&chain, op_mul, 2);

    /* Execute chain */
    return abr_math_v4_execute_chain(ctx, &chain);
}

/* Destroy function. */
static void density_destroy(abr_plugin* self)
{
    free(self);
}

/* Factory. */
abr_plugin* abr_plugin_density_index_factory(void)
{
    abr_plugin* p = (abr_plugin*)malloc(sizeof(*p));
    p->name    = "density_index";
    p->create  = density_create;
    p->execute = density_execute;
    p->destroy = density_destroy;
    return p;
}

