/*
 * abr_operators.h — ABR v0.5
 *
 * Canonical operator layer for ABR.
 * Defines the stable ABI for:
 *   - unary operators
 *   - binary operators
 *   - window-domain transforms
 *   - residue-domain transforms
 *
 * Phoenix Annotation (scflder):
 *   f = front (operator input)
 *   s = second (step through operator)
 *   l = last (operator output)
 *   d = degree domain (window width)
 *   r = residue domain (operator result)
 */

#ifndef ABR_OPERATORS_H
#define ABR_OPERATORS_H

#include <stdint.h>
#include <stddef.h>
#include "abr_context.h"

/* Unary operator signature. */
typedef uint64_t (*abr_unary_op)(
    abr_context* ctx,
    uint64_t window
);

/* Binary operator signature. */
typedef uint64_t (*abr_binary_op)(
    abr_context* ctx,
    uint64_t lhs,
    uint64_t rhs
);

/* Canonical unary operators (v0.5 minimal). */
uint64_t abr_op_identity(abr_context* ctx, uint64_t window);
uint64_t abr_op_not(abr_context* ctx, uint64_t window);
uint64_t abr_op_shift_left(abr_context* ctx, uint64_t window);
uint64_t abr_op_shift_right(abr_context* ctx, uint64_t window);

/* Canonical binary operators (v0.5 minimal). */
uint64_t abr_op_and(abr_context* ctx, uint64_t lhs, uint64_t rhs);
uint64_t abr_op_or(abr_context* ctx, uint64_t lhs, uint64_t rhs);
uint64_t abr_op_xor(abr_context* ctx, uint64_t lhs, uint64_t rhs);

#endif /* ABR_OPERATORS_H */

