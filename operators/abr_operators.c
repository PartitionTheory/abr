/*
 * abr_operators.c — ABR v0.5
 *
 * Canonical operator layer for ABR.
 * Implements:
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

#include "abr_operators.h"
#include "abr_context.h"

/* ------------------------- */
/*   Unary Operators (v0.5)  */
/* ------------------------- */

uint64_t abr_op_identity(abr_context* ctx, uint64_t window)
{
    if (!ctx) return 0;
    ctx->window  = window; /* f,s,l */
    ctx->residue = window; /* r */
    return window;
}

uint64_t abr_op_not(abr_context* ctx, uint64_t window)
{
    if (!ctx) return 0;
    uint64_t result = ~window;
    ctx->window  = result;
    ctx->residue = result;
    return result;
}

uint64_t abr_op_shift_left(abr_context* ctx, uint64_t window)
{
    if (!ctx) return 0;
    uint64_t result = window << 1;
    ctx->window  = result;
    ctx->residue = result;
    return result;
}

uint64_t abr_op_shift_right(abr_context* ctx, uint64_t window)
{
    if (!ctx) return 0;
    uint64_t result = window >> 1;
    ctx->window  = result;
    ctx->residue = result;
    return result;
}

/* -------------------------- */
/*   Binary Operators (v0.5)  */
/* -------------------------- */

uint64_t abr_op_and(abr_context* ctx, uint64_t lhs, uint64_t rhs)
{
    if (!ctx) return 0;
    uint64_t result = lhs & rhs;
    ctx->window  = result;
    ctx->residue = result;
    return result;
}

uint64_t abr_op_or(abr_context* ctx, uint64_t lhs, uint64_t rhs)
{
    if (!ctx) return 0;
    uint64_t result = lhs | rhs;
    ctx->window  = result;
    ctx->residue = result;
    return result;
}

uint64_t abr_op_xor(abr_context* ctx, uint64_t lhs, uint64_t rhs)
{
    if (!ctx) return 0;
    uint64_t result = lhs ^ rhs;
    ctx->window  = result;
    ctx->residue = result;
    return result;
}

