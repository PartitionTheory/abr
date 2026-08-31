#ifndef ABR_VM_H
#define ABR_VM_H

/*
 * ABR-Rebirth: Virtual Machine Execution Engine
 * Internal header — not for external API use.
 *
 * Defines the VM state structures and execution interfaces.
 * The VM is responsible for reversible operator execution,
 * gradient/coherence enforcement, and domain/window transitions.
 */

#include <stddef.h>

#ifdef __cplusplus
extern "C" {
#endif

/* Forward declarations */
typedef struct abr_runtime abr_runtime_t;
typedef struct abr_context abr_context_t;

/*
 * VM execution state.
 * Holds reversible stacks, operator dispatch tables,
 * and gradient/coherence enforcement metadata.
 */
typedef struct abr_vm_state {
    void *operator_dispatch;
    void *reverse_stack;
    size_t reverse_stack_size;
    int gradient_limit;
    int coherence_mode;
} abr_vm_state_t;

/*
 * Initialize VM state for a given runtime.
 * Returns a pointer to abr_vm_state_t or NULL on failure.
 */
abr_vm_state_t *abr_vm_init(abr_runtime_t *rt);

/*
 * Destroy VM state and release all associated resources.
 */
void abr_vm_shutdown(abr_vm_state_t *vm);

/*
 * Execute an operator within a context.
 * Returns 0 on success, non-zero on failure.
 */
int abr_vm_execute(abr_context_t *ctx, int operator_id, void *args);

#ifdef __cplusplus
}
#endif

#endif /* ABR_VM_H */

