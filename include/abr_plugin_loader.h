/*
 * ABR‑Rebirth: Plugin Operator Loader (Phase 4 Step 06)
 * -----------------------------------------------------
 * This module defines the API for loading operator definitions
 * from plugins and integrating them into the ABR runtime.
 *
 * It does not modify any Phase 1–3 subsystem. Instead, it adds
 * new Phase 4 functionality for dynamic operator expansion.
 */

#ifndef ABR_PLUGIN_LOADER_H
#define ABR_PLUGIN_LOADER_H

/*
 * ABR‑Rebirth: Plugin Loader (Phase 4)
 * ------------------------------------
 * Loads plugin shared libraries, retrieves their ABI, and registers
 * operators with the ABR runtime.
 */

#include "abr_interface.h"
#include "abr_core.h"
#include "abr_plugin_abi.h"
#include "abr_plugin_registry.h"

#ifdef __cplusplus
extern "C" {
#endif

/* Load a plugin from a shared library path */
int abr_plugin_loader_load(abr_runtime_t *rt, const char *path);

/* Unload a previously loaded plugin */
int abr_plugin_loader_unload(abr_runtime_t *rt, const char *path);

int abr_plugin_load(abr_runtime_t *rt, const abr_plugin_abi_t *abi);


#ifdef __cplusplus
}
#endif

#endif /* ABR_PLUGIN_LOADER_H */

