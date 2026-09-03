/*
 * abr_operator_chain.h — ABR v0.5
 *
 * Canonical operator-chain subsystem for ABR.
 * Defines the stable ABI for:
 *   - sequences of unary/binary operators
 *   - chained window-domain transforms
 *   - chained residue-domain transforms
 *
 * Phoenix Annotation (scflder):
 *   f = front (chain input)
 *   s = second (step through chain)
 *   l = last (chain output)
 *   d = degree domain (window width)
 *   r = residue domain (chain result)
 */

#ifndef ABR_OPERATOR_CHAIN_H
#define ABR_OPERATOR_CHAIN_H

#include <stdint.h>
#include <stddef.h>
#include "abr_context.h"
#include "abr_operators.h"

/* Operator chain entry type. */
typedef enum {
    ABR_CHAIN_UNARY,
    ABR_CHAIN_BINARY
} abr_chain_type;

/* Operator chain node. */
typedef struct abr_operator_chain_node {
    abr_chain_type type;

    /* Unary operator */
    abr_unary_op unary;

    /* Binary operator */
    abr_binary_op binary;
    uint64_t rhs; /* right-hand operand for binary ops */

    struct abr_operator_chain_node* next;
} abr_operator_chain_node;

/* Operator chain object. */
typedef struct abr_operator_chain {
    abr_operator_chain_node* head;
    abr_operator_chain_node* tail;
} abr_operator_chain;

/* Initialize an empty operator chain. */
void abr_operator_chain_init(abr_operator_chain* chain);

/* Append unary operator to chain. */
void abr_operator_chain_add_unary(
    abr_operator_chain* chain,
    abr_unary_op op
);

/* Append binary operator to chain. */
void abr_operator_chain_add_binary(
    abr_operator_chain* chain,
    abr_binary_op op,
    uint64_t rhs
);

/* Execute operator chain. */
uint64_t abr_operator_chain_execute(
    abr_operator_chain* chain,
    abr_context* ctx,
    uint64_t window
);

#endif /* ABR_OPERATOR_CHAIN_H */

