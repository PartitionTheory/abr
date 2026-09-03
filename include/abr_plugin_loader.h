/*
 * ABR‑Rebirth: Plugin Loader (v0.4‑greenbuild)
 * --------------------------------------------
 * This header merges:
 *   - Phase 4 ABI-based plugin loading (dynamic .so)
 *   - v0.4 constructor-based plugin loading (static registry)
 *
 * Both systems coexist. ABI loading will be deprecated in v0.5.
 */

#ifndef ABR_PLUGIN_LOADER_H
#define ABR_PLUGIN_LOADER_H

#include <stddef.h>
#include "abr_interface.h"
#include "abr_core.h"
#include "abr_plugin_registry.h"
#include "abr_plugin.h"

#ifdef __cplusplus
extern "C" {
#endif

/* ------------------------------------------------------------------------- */
/* Phase 4 ABI Loader (existing system)                                      */
/* ------------------------------------------------------------------------- */

/* Load a plugin from a shared library path */
int abr_plugin_loader_load(abr_runtime_t *rt, const char *path);

/* Unload a previously loaded plugin */
int abr_plugin_loader_unload(abr_runtime_t *rt, const char *path);

/* Register plugin operators via ABI */
int abr_plugin_load(abr_runtime_t *rt, const abr_plugin_abi_t *abi);


/* ------------------------------------------------------------------------- */
/* v0.4 Constructor Loader (new system)                                      */
/* ------------------------------------------------------------------------- */

/*
 * Load all v0.4 plugins using the static registry + factory constructors.
 * Returns an array of abr_plugin* of length *count.
 */
abr_plugin** abr_plugin_load_all(size_t* count);

/*
 * Free all plugins created by abr_plugin_load_all().
 */
void abr_plugin_free_all(abr_plugin** list, size_t count);


#ifdef __cplusplus
}
#endif

#endif /* ABR_PLUGIN_LOADER_H */

