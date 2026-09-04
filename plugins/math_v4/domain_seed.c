/*
 * domain_seed.c — ABR v0.5
 *
 * math_v4: domain seed plugin
 *
 * Computes a domain seed transformation:
 *
 *   window -> unary(op_identity)
 *           -> binary(op_add, rhs = (window & 0xFF))
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
abr_plugin* abr_plugin_domain_seed_factory(void);

/* Create function. */
static void domain_seed_create(abr_plugin* self)
{
    (void)self;
}

/* Execute function. */
static abr_plugin_result domain_seed_execute(
    abr_plugin* self,
    abr_context* ctx
)
{
    (void)self;

    /* Build operator chain */
    abr_operator_chain chain;
    abr_operator_chain_init(&chain);

    /* Unary: identity */
    abr_unary_op op_identity =
        abr_operator_registry_get_unary("identity");
    if (op_identity)
        abr_operator_chain_add_unary(&chain, op_identity);

    /* Binary: add low byte of window */
    uint64_t rhs = (ctx->window & 0xFF);

    abr_binary_op op_add =
        abr_operator_registry_get_binary("add");
    if (op_add)
        abr_operator_chain_add_binary(&chain, op_add, rhs);

    /* Execute chain */
    return abr_math_v4_execute_chain(ctx, &chain);
}

/* Destroy function. */
static void domain_seed_destroy(abr_plugin* self)
{
    free(self);
}

/* Factory. */
abr_plugin* abr_plugin_domain_seed_factory(void)
{
    abr_plugin* p = (abr_plugin*)malloc(sizeof(*p));
    p->name    = "domain_seed";
    p->create  = domain_seed_create;
    p->execute = domain_seed_execute;
    p->destroy = domain_seed_destroy;
    return p;
}

