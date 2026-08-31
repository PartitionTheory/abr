#ifndef ABR_PLUGIN_ABI_H
#define ABR_PLUGIN_ABI_H

/*
 * ABR‑Rebirth: Plugin ABI (Phase 4)
 * ---------------------------------
 * Defines the ABI exposed by dynamically loaded plugins.
 */

#include "abr_interface.h"

#ifdef __cplusplus
extern "C" {
#endif

typedef struct abr_plugin_abi {
    int abi_version;

    /* Operators exposed by the plugin */
    const abr_operator_info_t *operators;
    int operator_count;

} abr_plugin_abi_t;

#ifdef __cplusplus
}
#endif

#endif /* ABR_PLUGIN_ABI_H */

