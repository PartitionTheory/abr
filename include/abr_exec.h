#ifndef ABR_EXEC_H
#define ABR_EXEC_H

/*
 * ABR‑Rebirth: Execution Layer (Phase 4 Step 01)
 * ------------------------------------------------
 * This module defines the high‑level execution API used by
 * the interface layer, VM, and operator dispatch system.
 *
 * Phase 4 introduces dynamic operator execution, reversible
 * semantics, and synthetic math integration. The execution
 * layer provides the stable entry points for these behaviors.
 */

#include "abr_interface.h"
#include "abr_vm.h"
#include "abr_operators.h"

#ifdef __cplusplus
extern "C" {
#endif

/* Execute an operator by name. Returns 0 on success. */
int abr_exec_by_name(abr_context_t *ctx, const char *name, void *args);

/* Execute an operator by ID. Returns 0 on success. */
int abr_exec_by_id(abr_context_t *ctx, int operator_id, void *args);

#ifdef __cplusplus
}
#endif

#endif /* ABR_EXEC_H */
