#ifndef ABR_PLUGIN_REGISTRY_H
#define ABR_PLUGIN_REGISTRY_H

/*
 * ABR‑Rebirth: Plugin Registry (Phase 4)
 * --------------------------------------
 * Tracks loaded plugins and their ABIs.
 */

#include "abr_plugin_abi.h"
#include "abr_core.h"

#ifdef __cplusplus
extern "C" {
#endif

int abr_plugin_registry_add(abr_runtime_t *rt,
                            const char *path,
                            void *handle,
                            const abr_plugin_abi_t *abi);

int abr_plugin_registry_remove(abr_runtime_t *rt,
                               const char *path);

#ifdef __cplusplus
}
#endif

#endif /* ABR_PLUGIN_REGISTRY_H */

