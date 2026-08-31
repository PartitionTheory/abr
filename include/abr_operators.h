#ifndef ABR_OPERATORS_H
#define ABR_OPERATORS_H

/*
 * ABR-Rebirth: Operator Subsystem
 * Internal header — not for external API use.
 *
 * Operators are the fundamental reversible mathematical actions.
 * They are registered with the runtime, validated by the interface layer,
 * and executed by the VM with gradient/coherence enforcement.
 */

#include <stddef.h>

#ifdef __cplusplus
extern "C" {
#endif

/* Forward declarations */
typedef struct abr_runtime abr_runtime_t;
typedef struct abr_context abr_context_t;

/*
 * Operator dispatch function type.
 * Every operator implementation must match this signature.
 *
 * Returns 0 on success, non-zero on failure.
 */
typedef int (*abr_operator_fn)(abr_context_t *ctx, void *args);

/*
 * Operator entry in the operator table.
 * This is the internal representation used by the operator subsystem.
 */
typedef struct abr_operator_entry {
    int operator_id;
    abr_operator_fn fn;
    const char *name;
    int gradient_cost;
    int coherence_requirement;
} abr_operator_entry_t;

/*
 * Register an operator implementation.
 * Called internally by the interface layer after metadata validation.
 *
 * Returns 0 on success, non-zero on failure.
 */
int abr_operator_register(abr_runtime_t *rt,
                          int operator_id,
                          abr_operator_fn fn,
                          const char *name,
                          int gradient_cost,
                          int coherence_requirement);

/*
 * Lookup an operator entry by ID.
 * Returns pointer to entry or NULL if not found.
 */
const abr_operator_entry_t *abr_operator_lookup(abr_runtime_t *rt, int operator_id);

#ifdef __cplusplus
}
#endif

#endif /* ABR_OPERATORS_H */

