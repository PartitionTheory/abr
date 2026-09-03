/*
 * abr_operators.h — ABR v0.5
 *
 * Operator subsystem interface.
 */

#ifndef ABR_OPERATORS_H
#define ABR_OPERATORS_H

#include <stdint.h>

typedef uint64_t (*abr_unary_op)(uint64_t);
typedef uint64_t (*abr_binary_op)(uint64_t, uint64_t);

abr_unary_op  abr_operator_registry_get_unary(const char* name);
abr_binary_op abr_operator_registry_get_binary(const char* name);

#endif /* ABR_OPERATORS_H */

