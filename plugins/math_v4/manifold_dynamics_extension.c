/*
 * manifold_dynamics_extension.c — ABR v0.5
 *
 * math_v4: manifold dynamics extension plugin
 *
 * Extends the manifold dynamics transformation:
 *
 *   window -> unary(op_shift_left)
 *           -> binary(op_add, rhs = 3)
 *           -> unary(op_shift_right)
 *           -> binary(op_xor, rhs = 0xA5)
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
abr_plugin* abr_plugin_manifold_dynamics_extension_factory(void);

/* Create function. */
static void manifold_ext_create(abr_plugin* self)
{
    (void)self;
}

/* Execute function. */
static abr_plugin_result manifold_ext_execute(
    abr_plugin* self,
    abr_context* ctx
)
{
    (void)self;

    /* Build operator chain */
    abr_operator_chain chain;
    abr_operator_chain_init(&chain);

    /* Unary: shift left */
    abr_unary_op op_shift_left =
        abr_operator_registry_get_unary("shift_left");
    if (op_shift_left)
        abr_operator_chain_add_unary(&chain, op_shift_left);

    /* Binary: add 3 */
    abr_binary_op op_add =
        abr_operator_registry_get_binary("add");
    if (op_add)
        abr_operator_chain_add_binary(&chain, op_add, 3);

    /* Unary: shift right */
    abr_unary_op op_shift_right =
        abr_operator_registry_get_unary("shift_right");
    if (op_shift_right)
        abr_operator_chain_add_unary(&chain, op_shift_right);

    /* Binary: XOR with 0xA5 */
    abr_binary_op op_xor =
        abr_operator_registry_get_binary("xor");
    if (op_xor)
        abr_operator_chain_add_binary(&chain, op_xor, 0xA5);

    /* Execute chain */
    return abr_math_v4_execute_chain(ctx, &chain);
}

/* Destroy function. */
static void manifold_ext_destroy(abr_plugin* self)
{
    free(self);
}

/* Factory. */
abr_plugin* abr_plugin_manifold_dynamics_extension_factory(void)
{
    abr_plugin* p = (abr_plugin*)malloc(sizeof(*p));
    p->name    = "manifold_dynamics_extension";
    p->create  = manifold_ext_create;
    p->execute = manifold_ext_execute;
    p->destroy = manifold_ext_destroy;
    return p;
}

