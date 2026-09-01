#ifndef ABR_INTERFACE_H
#define ABR_INTERFACE_H

/*
 * ABR-Rebirth: Interface Layer
 * Internal header — not for external API use.
 *
 * The interface layer provides stable ABI boundaries between:
 *   - Core runtime
 *   - VM execution engine
 *   - Operator subsystem
 *   - Plugin registry
 *   - Dynamic plugins
 *
 * All internal subsystems call through this interface to ensure
 * coherence, gradient safety, and reversible execution semantics.
 */

#include <stddef.h>

#ifdef __cplusplus
extern "C" {
#endif

/* Forward declarations */
typedef struct abr_runtime abr_runtime_t;
typedef struct abr_context abr_context_t;

/*
 * Operator metadata exposed through the interface.
 * Plugins and internal operators register themselves using this structure.
 */
typedef struct abr_operator_info {
    int operator_id;
    const char *name;
    const char *description;
    int gradient_cost;
    int coherence_requirement;
} abr_operator_info_t;

/*
 * Register an operator with the ABR runtime.
 * Returns 0 on success, non-zero on failure.
 */
int abr_register_operator(abr_runtime_t *rt, const abr_operator_info_t *info);

/*
 * Lookup operator metadata by ID.
 * Returns pointer to metadata or NULL if not found.
 */
const abr_operator_info_t *abr_get_operator_info(abr_runtime_t *rt, int operator_id);

/*
 * Execute an operator through the interface layer.
 * This wraps VM execution and enforces interface-level invariants.
 */
int abr_interface_execute(abr_context_t *ctx, int operator_id, void *args);

#ifdef __cplusplus
}
#endif
abr_context_t *abr_context_create(abr_runtime_t *rt);
void abr_context_destroy(abr_context_t *ctx);

#endif /* ABR_INTERFACE_H */

/*
 * Phoenix Epoch: Bitstream Window API (v0.4‑greenbuild)
 *
 * Exposes structural slices of the ABR bitstream to plugins.
 * Plugins use windows to inspect or manipulate local regions of the stream.
 */

#include "abr_stream.h"

/*
 * Extract a bitwindow from the context's bound stream.
 * Returns an empty window if the context or stream is invalid.
 */
abr_bitwindow abr_interface_window(abr_context_t* ctx, size_t offset, size_t length);

#ifndef ABR_INTERFACE_PLUGIN_CLASS_EXEC_H
#define ABR_INTERFACE_PLUGIN_CLASS_EXEC_H

#include "abr_plugin.h"

/* Phoenix v0.4-greenbuild: class-based plugin execution API */
abr_plugin_result
abr_interface_exec_plugin_by_class(abr_context_t* ctx,
                                   const char* class_tag,
                                   const char* json);

#endif

