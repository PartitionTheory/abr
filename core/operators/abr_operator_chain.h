/*
 * abr_operator_chain.h — ABR v0.5
 *
 * Operator-chain subsystem interface.
 */

#ifndef ABR_OPERATOR_CHAIN_H
#define ABR_OPERATOR_CHAIN_H

#include <stdint.h>
#include <stddef.h>
#include "abr_operators.h"
#include "abr_plugin_result.h"
#include "abr_runtime_context.h"

#define ABR_OPERATOR_CHAIN_MAX 64

typedef enum
{
    ABR_OP_UNARY,
    ABR_OP_BINARY

} abr_operator_type;

typedef struct
{
    abr_operator_type type;

    union
    {
        abr_unary_op  unary;
        abr_binary_op binary;
    };

    uint64_t rhs;

} abr_operator_step;

typedef struct
{
    abr_operator_step ops[ABR_OPERATOR_CHAIN_MAX];
    size_t count;

} abr_operator_chain;

void abr_operator_chain_init(abr_operator_chain* chain);
void abr_operator_chain_add_unary(abr_operator_chain* chain, abr_unary_op op);
void abr_operator_chain_add_binary(abr_operator_chain* chain, abr_binary_op op, uint64_t rhs);

abr_plugin_result abr_operator_chain_execute(
    abr_operator_chain* chain,
    abr_context* ctx
);

#endif /* ABR_OPERATOR_CHAIN_H */

