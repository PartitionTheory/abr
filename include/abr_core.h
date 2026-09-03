#include "abr_interface.h"
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
struct abr_context;

/*
 * Core runtime structure.
 * Holds global state, plugin registry, operator tables, and VM bindings.
 */
struct abr_runtime {
    int initialized;

    /* Plugin registry (Phase 4 Step 02) */
    void *plugin_registry;

    /* Operator registry (Phase 4 Step 01) */
    int operator_count;
    const abr_operator_info_t **operators;

    /* VM state (Phase 4 Step 03) */
    void *vm_state;
};

#ifdef __cplusplus
}
#endif

abr_runtime_t *abr_init(void);
void abr_shutdown(abr_runtime_t *rt);

#endif /* ABR_CORE_H */

