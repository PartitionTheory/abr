#include "../../include/abr_interface.h"
#include "../../include/abr_core.h"
#include "../../include/abr_plugin_abi.h"
#include "../../include/abr_plugin_registry.h"

#ifndef ABR_PLUGIN_LOADER_H
#define ABR_PLUGIN_LOADER_H

/*
 * ABR‑Rebirth: Plugin Loader (Phase 4)
 * ------------------------------------
 * Responsible for loading operator metadata from plugins and
 * registering them with the ABR runtime.
 */

#ifdef __cplusplus
extern "C" {
#endif

/* Load all plugins and register their operators. */
int abr_plugin_loader_load_all(abr_runtime_t *rt);

/* Load a single plugin file. */
int abr_plugin_loader_load_file(abr_runtime_t *rt, const char *path);

/* Register operators exposed by a plugin. */
int abr_plugin_loader_register(abr_runtime_t *rt,
                               const abr_operator_info_t *ops,
                               int count);

#ifdef __cplusplus
}
#endif

#endif /* ABR_PLUGIN_LOADER_H */

