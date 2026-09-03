/*
 * abr_operator_registry.c — ABR v0.5
 *
 * Canonical operator registry for ABR.
 * Implements:
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

#include "abr_operator_registry.h"
#include <stdlib.h>
#include <string.h>

/* Initialize registry. */
void abr_operator_registry_init(abr_operator_registry* reg)
{
    if (!reg) return;
    reg->head = NULL;
}

/* Register unary operator. */
void abr_operator_registry_add_unary(
    abr_operator_registry* reg,
    const char* name,
    abr_unary_op op
)
{
    if (!reg || !name || !op) return;

    abr_operator_registry_entry* entry =
        (abr_operator_registry_entry*)malloc(sizeof(*entry));

    entry->name   = name;
    entry->type   = ABR_OPREG_UNARY;
    entry->unary  = op;
    entry->binary = NULL;
    entry->next   = reg->head;

    reg->head = entry;
}

/* Register binary operator. */
void abr_operator_registry_add_binary(
    abr_operator_registry* reg,
    const char* name,
    abr_binary_op op
)
{
    if (!reg || !name || !op) return;

    abr_operator_registry_entry* entry =
        (abr_operator_registry_entry*)malloc(sizeof(*entry));

    entry->name   = name;
    entry->type   = ABR_OPREG_BINARY;
    entry->unary  = NULL;
    entry->binary = op;
    entry->next   = reg->head;

    reg->head = entry;
}

/* Lookup unary operator by name. */
abr_unary_op abr_operator_registry_get_unary(
    abr_operator_registry* reg,
    const char* name
)
{
    if (!reg || !name) return NULL;

    abr_operator_registry_entry* e = reg->head;
    while (e) {
        if (e->type == ABR_OPREG_UNARY &&
            strcmp(e->name, name) == 0)
        {
            return e->unary;
        }
        e = e->next;
    }
    return NULL;
}

/* Lookup binary operator by name. */
abr_binary_op abr_operator_registry_get_binary(
    abr_operator_registry* reg,
    const char* name
)
{
    if (!reg || !name) return NULL;

    abr_operator_registry_entry* e = reg->head;
    while (e) {
        if (e->type == ABR_OPREG_BINARY &&
            strcmp(e->name, name) == 0)
        {
            return e->binary;
        }
        e = e->next;
    }
    return NULL;
}

