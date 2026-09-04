/*
 * invariant_explorer.c — ABR v0.5
 *
 * math_v4: invariant explorer plugin
 *
 * Performs a simple operator-chain based invariant transformation:
 *   window -> unary(op_abs)
 *           -> binary(op_mod, rhs = 7)
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
#include "abr_operators.h"
#include "abr_operator_chain.h"
#include "abr_plugin_registry.h"

#include <stdlib.h>

/* Forward declaration of factory. */
abr_plugin* abr_plugin_invariant_explorer_factory(void);

/* Create function. */
static void invariant_create(abr_plugin* self)
{
    (void)self;
}

/* Execute function. */
static abr_plugin_result invariant_execute(
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

    /* Binary: modulo 7 */
    abr_binary_op op_mod =
        abr_operator_registry_get_binary("mod");
    if (op_mod)
        abr_operator_chain_add_binary(&chain, op_mod, 7);

    /* Execute chain */
    return abr_math_v4_execute_chain(ctx, &chain);
}

/* Destroy function. */
static void invariant_destroy(abr_plugin* self)
{
    free(self);
}

/* Factory. */
abr_plugin* abr_plugin_invariant_explorer_factory(void)
{
    abr_plugin* p = (abr_plugin*)malloc(sizeof(*p));
    p->name    = "invariant_explorer";
    p->create  = invariant_create;
    p->execute = invariant_execute;
    p->destroy = invariant_destroy;
    return p;
}

