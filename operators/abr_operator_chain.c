/*
 * abr_operator_chain.c — ABR v0.5
 *
 * Canonical operator-chain subsystem for ABR.
 * Implements:
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

#include "abr_operator_chain.h"
#include <stdlib.h>

/* Initialize an empty operator chain. */
void abr_operator_chain_init(abr_operator_chain* chain)
{
    if (!chain) return;
    chain->head = NULL;
    chain->tail = NULL;
}

/* Append unary operator to chain. */
void abr_operator_chain_add_unary(
    abr_operator_chain* chain,
    abr_unary_op op
)
{
    if (!chain || !op) return;

    abr_operator_chain_node* node =
        (abr_operator_chain_node*)malloc(sizeof(*node));

    node->type  = ABR_CHAIN_UNARY;
    node->unary = op;
    node->binary = NULL;
    node->rhs = 0;
    node->next = NULL;

    if (!chain->head)
        chain->head = node;
    else
        chain->tail->next = node;

    chain->tail = node;
}

/* Append binary operator to chain. */
void abr_operator_chain_add_binary(
    abr_operator_chain* chain,
    abr_binary_op op,
    uint64_t rhs
)
{
    if (!chain || !op) return;

    abr_operator_chain_node* node =
        (abr_operator_chain_node*)malloc(sizeof(*node));

    node->type   = ABR_CHAIN_BINARY;
    node->unary  = NULL;
    node->binary = op;
    node->rhs    = rhs;
    node->next   = NULL;

    if (!chain->head)
        chain->head = node;
    else
        chain->tail->next = node;

    chain->tail = node;
}

/* Execute operator chain. */
uint64_t abr_operator_chain_execute(
    abr_operator_chain* chain,
    abr_context* ctx,
    uint64_t window
)
{
    if (!chain || !ctx) return 0;

    uint64_t current = window;
    abr_operator_chain_node* node = chain->head;

    while (node) {
        if (node->type == ABR_CHAIN_UNARY) {
            current = node->unary(ctx, current);
        } else {
            current = node->binary(ctx, current, node->rhs);
        }
        node = node->next;
    }

    return current;
}

