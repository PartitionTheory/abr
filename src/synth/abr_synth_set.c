#include "abr_context.h"
#include "abr_synth_operator.h"
#include <string.h>

/*
 * Phoenix v0.4-greenbuild:
 * Synthetic Operator Set Registry.
 *
 * This registry groups synthetic operators into named sets.
 * Future synthetic operators (math, reversible, structural)
 * will be added to these sets.
 */

typedef struct abr_synth_set_entry {
    const char* set_name;
    abr_synth_operator_t** operators;
    int operator_count;
} abr_synth_set_entry;

/* For now, we support a small static registry. */
static abr_synth_set_entry synth_sets[8];
static int synth_set_count = 0;

/*
 * Register a synthetic operator into a named set.
 */
void abr_synth_set_add(const char* set_name,
                       abr_synth_operator_t* op)
{
    /* Find existing set */
    for (int i = 0; i < synth_set_count; i++) {
        if (strcmp(synth_sets[i].set_name, set_name) == 0) {
            synth_sets[i].operators[synth_sets[i].operator_count++] = op;
            return;
        }
    }

    /* Create new set */
    synth_sets[synth_set_count].set_name = set_name;
    synth_sets[synth_set_count].operators =
        (abr_synth_operator_t**)malloc(sizeof(void*) * 32);
    synth_sets[synth_set_count].operator_count = 0;

    synth_sets[synth_set_count].operators[
        synth_sets[synth_set_count].operator_count++] = op;

    synth_set_count++;
}

/*
 * Register all operators in a set.
 */
void abr_synth_set_register_all(abr_context_t* ctx,
                                const char* set_name)
{
    for (int i = 0; i < synth_set_count; i++) {
        if (strcmp(synth_sets[i].set_name, set_name) == 0) {
            for (int j = 0; j < synth_sets[i].operator_count; j++) {
                abr_synth_operator_register(ctx, synth_sets[i].operators[j]);
            }
            return;
        }
    }
}

