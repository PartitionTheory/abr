/*
 * ABR-Rebirth: Operator Subsystem Implementation
 *
 * Implements the internal operator table and registration/lookup helpers.
 */

#include "abr_operators.h"
#include "abr_core.h"

#include <stdlib.h>
#include <string.h>

/* ------------------------------------------------------------------------- */
/* Internal operator table                                                   */
/* ------------------------------------------------------------------------- */

typedef struct abr_operator_table {
    abr_operator_entry_t *entries;
    size_t count;
    size_t capacity;
} abr_operator_table_t;

/*
 * For now, we store the operator table in the runtime->operator_table
 * as an opaque pointer to abr_operator_table_t.
 */

static abr_operator_table_t *abr_get_table(abr_runtime_t *rt)
{
    static abr_operator_table_t *tbl = NULL;

    if (!rt || !rt->initialized) {
        return NULL;
    }

    if (!tbl) {
        tbl = (abr_operator_table_t *)malloc(sizeof(abr_operator_table_t));
        if (!tbl) {
            return NULL;
        }
        tbl->entries  = NULL;
        tbl->count    = 0;
        tbl->capacity = 0;
    }

    return tbl;
}

/* ------------------------------------------------------------------------- */
/* Registration                                                              */
/* ------------------------------------------------------------------------- */

int abr_operator_register(abr_runtime_t *rt,
                          int operator_id,
                          abr_operator_fn fn,
                          const char *name,
                          int gradient_cost,
                          int coherence_requirement)
{
    abr_operator_table_t *tbl = abr_get_table(rt);
    if (!tbl) {
        return -1;
    }

    /* Grow table if needed */
    if (tbl->count == tbl->capacity) {
        size_t new_cap = (tbl->capacity == 0) ? 8 : tbl->capacity * 2;
        abr_operator_entry_t *new_entries =
            (abr_operator_entry_t *)realloc(tbl->entries,
                                            new_cap * sizeof(abr_operator_entry_t));
        if (!new_entries) {
            return -2;
        }
        tbl->entries  = new_entries;
        tbl->capacity = new_cap;
    }

    abr_operator_entry_t *e = &tbl->entries[tbl->count++];
    e->operator_id          = operator_id;
    e->fn                   = fn;
    e->name                 = name;
    e->gradient_cost        = gradient_cost;
    e->coherence_requirement = coherence_requirement;

    return 0;
}

/* ------------------------------------------------------------------------- */
/* Lookup                                                                    */
/* ------------------------------------------------------------------------- */

const abr_operator_entry_t *abr_operator_lookup(abr_runtime_t *rt, int operator_id)
{
    abr_operator_table_t *tbl = abr_get_table(rt);
    if (!tbl) {
        return NULL;
    }

    for (size_t i = 0; i < tbl->count; ++i) {
        if (tbl->entries[i].operator_id == operator_id) {
            return &tbl->entries[i];
        }
    }

    return NULL;
}

