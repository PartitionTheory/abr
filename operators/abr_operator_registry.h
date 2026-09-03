/*
 * abr_operator_registry.h — ABR v0.5
 *
 * Canonical operator registry for ABR.
 * Provides:
 *   - global operator lookup
 *   - unary/binary operator registration
 *   - operator discovery for plugins and chains
 *
 * Phoenix Annotation (scflder):
 *   f = front (registry input)
 *   s = second (lookup step)
 *   l = last (resolved operator)
 *   d = degree domain (window width)
 *   r = residue domain (operator result)
 */

#ifndef ABR_OPERATOR_REGISTRY_H
#define ABR_OPERATOR_REGISTRY_H

#include <stdint.h>
#include <stddef.h>
#include "abr_operators.h"

/* Registry entry type. */
typedef enum {
    ABR_OPREG_UNARY,
    ABR_OPREG_BINARY
} abr_opreg_type;

/* Registry entry. */
typedef struct abr_operator_registry_entry {
    const char* name;
    abr_opreg_type type;

    /* Unary operator */
    abr_unary_op unary;

    /* Binary operator */
    abr_binary_op binary;

    struct abr_operator_registry_entry* next;
} abr_operator_registry_entry;

/* Registry object. */
typedef struct abr_operator_registry {
    abr_operator_registry_entry* head;
} abr_operator_registry;

/* Initialize registry. */
void abr_operator_registry_init(abr_operator_registry* reg);

/* Register unary operator. */
void abr_operator_registry_add_unary(
    abr_operator_registry* reg,
    const char* name,
    abr_unary_op op
);

/* Register binary operator. */
void abr_operator_registry_add_binary(
    abr_operator_registry* reg,
    const char* name,
    abr_binary_op op
);

/* Lookup unary operator by name. */
abr_unary_op abr_operator_registry_get_unary(
    abr_operator_registry* reg,
    const char* name
);

/* Lookup binary operator by name. */
abr_binary_op abr_operator_registry_get_binary(
    abr_operator_registry* reg,
    const char* name
);

#endif /* ABR_OPERATOR_REGISTRY_H */

