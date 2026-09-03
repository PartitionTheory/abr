/*
 * abr_operators.c — ABR v0.5
 *
 * Canonical operator subsystem for ABR.
 *
 * Responsibilities:
 *   - define unary and binary operators
 *   - provide operator lookup by name
 *   - integrate with operator-chain subsystem
 *   - support math_v4 plugin execution
 *
 * Phoenix Annotation (scflder):
 *   f = front (operator input)
 *   s = second (operator application)
 *   l = last (operator output)
 *   d = degree domain (operator type)
 *   r = residue domain (result propagation)
 */

#include "abr_operators.h"
#include <string.h>

/* Unary operators */
static uint64_t op_neg(uint64_t x)        { return ~x; }
static uint64_t op_shift_left(uint64_t x) { return x << 1; }
static uint64_t op_shift_right(uint64_t x){ return x >> 1; }

/* Binary operators */
static uint64_t op_add(uint64_t a, uint64_t b) { return a + b; }
static uint64_t op_xor(uint64_t a, uint64_t b) { return a ^ b; }

/* Lookup unary operator by name */
abr_unary_op abr_operator_registry_get_unary(const char* name)
{
    if (strcmp(name, "neg") == 0)
        return op_neg;

    if (strcmp(name, "shift_left") == 0)
        return op_shift_left;

    if (strcmp(name, "shift_right") == 0)
        return op_shift_right;

    return NULL;
}

/* Lookup binary operator by name */
abr_binary_op abr_operator_registry_get_binary(const char* name)
{
    if (strcmp(name, "add") == 0)
        return op_add;

    if (strcmp(name, "xor") == 0)
        return op_xor;

    return NULL;
}

