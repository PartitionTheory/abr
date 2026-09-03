/*
 * operator_chain.c — ABR v0.5
 *
 * math_v4: operator chain plugin
 *
 * Applies a composed operator chain:
 *
 *   window -> unary(op_neg)
 *           -> binary(op_add, rhs = 5)
 *           -> unary(op_shift_left)
 *
 * Phoenix Annotation (scflder):
 *   f = front (plugin input)
 *   s = second (operator-chain step)
 *   l = last (plugin output)
 *   d = degree domain (window width)
 *   r = residue domain (plugin result)
 */

#include "abr_math_v4_common.h"
#include <stdlib.h>

/* Forward declaration of factory. */
abr_plugin* abr_plugin_operator_chain_factory(void);

/* Create function. */
static void operator_chain_create(abr_plugin* self)
{
    (void)self;
}

/* Execute function. */
static abr_plugin_result operator_chain_execute(
    abr_plugin* self,
    abr_context* ctx
)
{
    (void)self;

    /* Build operator chain */
    abr_operator_chain chain;
    abr_operator_chain_init(&chain);

    /* Unary: negation */
    abr_unary_op op_neg =
        abr_operator_registry_get_unary("neg");
    if (op_neg)
        abr_operator_chain_add_unary(&chain, op_neg);

    /* Binary: add 5 */
    abr_binary_op op_add =
        abr_operator_registry_get_binary("add");
    if (op_add)
        abr_operator_chain_add_binary(&chain, op_add, 5);

    /* Unary: shift left */
    abr_unary_op op_shift_left =
        abr_operator_registry_get_unary("shift_left");
    if (op_shift_left)
        abr_operator_chain_add_unary(&chain, op_shift_left);

    /* Execute chain */
    return abr_math_v4_execute_chain(ctx, &chain);
}

/* Destroy function. */
static void operator_chain_destroy(abr_plugin* self)
{
    free(self);
}

/* Factory. */
abr_plugin* abr_plugin_operator_chain_factory(void)
{
    abr_plugin* p = (abr_plugin*)malloc(sizeof(*p));
    p->name    = "operator_chain";
    p->create  = operator_chain_create;
    p->execute = operator_chain_execute;
    p->destroy = operator_chain_destroy;
    return p;
}

