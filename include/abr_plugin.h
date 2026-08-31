#ifndef ABR_PLUGIN_H
#define ABR_PLUGIN_H

/*
 * ABR-Rebirth: Plugin ABI Definition
 * Internal header — used by dynamic plugins and the plugin registry.
 *
 * Every plugin must expose:
 *   - metadata (name, version, description)
 *   - operator registration table
 *   - initialization and shutdown functions
 *
 * This header defines the stable ABI boundary for all dynamic modules.
 */

#include <stddef.h>

#ifdef __cplusplus
extern "C" {
#endif

/* Forward declarations */
typedef struct abr_runtime abr_runtime_t;
typedef struct abr_operator_info abr_operator_info_t;

/*
 * Plugin metadata structure.
 * Every plugin must define one instance of this and export it.
 */
typedef struct abr_plugin_info {
    const char *name;          /* Human-readable plugin name */
    const char *version;       /* Plugin version string */
    const char *description;   /* Short description of plugin functionality */

    /* Number of operators provided by this plugin */
    size_t operator_count;

    /* Pointer to an array of operator metadata */
    const abr_operator_info_t *operators;
} abr_plugin_info_t;

/*
 * Plugin initialization function.
 * Called when the plugin is loaded by the registry.
 * Returns 0 on success, non-zero on failure.
 */
typedef int (*abr_plugin_init_fn)(abr_runtime_t *rt);

/*
 * Plugin shutdown function.
 * Called when the plugin is unloaded.
 */
typedef void (*abr_plugin_shutdown_fn)(void);

/*
 * Plugin ABI structure.
 * Every plugin must export a symbol named "abr_plugin_abi".
 */
typedef struct abr_plugin_abi {
    int abi_version;                   /* ABI version for compatibility */
    abr_plugin_info_t info;            /* Plugin metadata */
    abr_plugin_init_fn init;           /* Initialization callback */
    abr_plugin_shutdown_fn shutdown;   /* Shutdown callback */
} abr_plugin_abi_t;

/* Current ABI version for ABR-Rebirth */
#define ABR_PLUGIN_ABI_VERSION 1

int abr_plugin_load(abr_runtime_t *rt, const abr_plugin_abi_t *abi);
int abr_plugin_unload(const abr_plugin_abi_t *abi);


#ifdef __cplusplus
}
#endif

#endif /* ABR_PLUGIN_H */

