#ifndef ABR_PLUGIN_H
#define ABR_PLUGIN_H

/*
 * ABR‑Rebirth: Unified Plugin Interface (v0.4‑greenbuild)
 *
 * This header merges:
 *   - Phase 4 ABI plugin system (dynamic .so loading)
 *   - v0.4 constructor‑based plugin system (static registry)
 *   - v0.4 JSON carriers for plugin input/output
 *
 * ABI loading remains supported but will be deprecated in v0.5.
 */

#include <stddef.h>

#ifdef __cplusplus
extern "C" {
#endif

/* Forward declarations */
typedef struct abr_runtime abr_runtime_t;
typedef struct abr_operator_info abr_operator_info_t;

/* ------------------------------------------------------------------------- */
/* v0.4 JSON carriers                                                         */
/* ------------------------------------------------------------------------- */

/* JSON carrier for plugin input */
typedef struct abr_plugin_input {
    const char* json;     /* raw JSON input string */
} abr_plugin_input;

/* JSON carrier for plugin output */
typedef struct abr_plugin_result {
    int status;           /* 0 = failure, 1 = success */
    const char* message;  /* human-readable message */
    const char* json;     /* raw JSON output string */
} abr_plugin_result;

/* ------------------------------------------------------------------------- */
/* v0.4 constructor‑based plugin interface                                    */
/* ------------------------------------------------------------------------- */

typedef struct abr_plugin {
    const char* name;     /* plugin name */
    abr_plugin_result (*execute)(const abr_plugin_input* input);
} abr_plugin;

/* Factory constructor signature */
typedef abr_plugin* (*abr_plugin_create_fn)(void);

/* ------------------------------------------------------------------------- */
/* Phase 4 ABI plugin interface (unchanged)                                   */
/* ------------------------------------------------------------------------- */

/*
 * Plugin metadata structure.
 * Every ABI plugin must define one instance of this and export it.
 */
typedef struct abr_plugin_info {
    const char *name;
    const char *version;
    const char *description;
    size_t operator_count;
    const abr_operator_info_t *operators;
} abr_plugin_info_t;

/* ABI init/shutdown callbacks */
typedef int  (*abr_plugin_init_fn)(abr_runtime_t *rt);
typedef void (*abr_plugin_shutdown_fn)(void);

/*
 * ABI structure exported as "abr_plugin_abi"
 */
typedef struct abr_plugin_abi {
    int abi_version;
    abr_plugin_info_t info;
    abr_plugin_init_fn init;
    abr_plugin_shutdown_fn shutdown;
} abr_plugin_abi_t;

/* ABI version */
#define ABR_PLUGIN_ABI_VERSION 1

/* ABI loader functions */
int abr_plugin_load(abr_runtime_t *rt, const abr_plugin_abi_t *abi);
int abr_plugin_unload(const abr_plugin_abi_t *abi);

#ifdef __cplusplus
}
#endif

#endif /* ABR_PLUGIN_H */

