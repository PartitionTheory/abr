#ifndef ABR_CORE_H
#define ABR_CORE_H

/*
 * ABR-Rebirth: Core Runtime Structures
 * Internal header — not for external API use.
 *
 * Defines the fundamental opaque structures used by the core subsystem.
 * These are allocated and managed by abr_core.c (to be populated by CO).
 */

#include <stddef.h>

#ifdef __cplusplus
extern "C" {
#endif

/* Forward declarations for internal subsystems */
typedef struct abr_runtime abr_runtime_t;
typedef struct abr_context abr_context_t;

/*
 * Core runtime structure.
 * Holds global state, plugin registry, operator tables, and VM bindings.
 */
struct abr_runtime {
    int initialized;
    void *plugin_registry;
    void *operator_table;
    void *vm_state;
};

/*
 * Computation context.
 * Holds per-execution reversible state, gradient limits, and coherence flags.
 */
struct abr_context {
    abr_runtime_t *runtime;
    void *vm_exec_state;
    int gradient_level;
    int coherence_flag;
};

#ifdef __cplusplus
}
#endif

#endif /* ABR_CORE_H */

