/*
 * ABR-Rebirth: Plugin ABI Loader
 *
 * Implements plugin initialization, shutdown, and operator registration.
 */

#include "abr_plugin.h"
#include "abr_core.h"
#include "abr_interface.h"

#include <stdlib.h>

/* ------------------------------------------------------------------------- */
/* Plugin loading (static for now; dynamic loading added later)              */
/* ------------------------------------------------------------------------- */

int abr_plugin_load(abr_runtime_t *rt, const abr_plugin_abi_t *abi)
{
    if (!rt || !rt->initialized || !abi) {
        return -1;
    }

    if (abi->abi_version != ABR_PLUGIN_ABI_VERSION) {
        return -2; /* ABI mismatch */
    }

    /* Register operators */
    for (size_t i = 0; i < abi->info.operator_count; ++i) {
        const abr_operator_info_t *op = &abi->info.operators[i];
        int rc = abr_register_operator(rt, op);
        if (rc != 0) {
            return -3;
        }
    }

    /* Call plugin init */
    if (abi->init) {
        int rc = abi->init(rt);
        if (rc != 0) {
            return -4;
        }
    }

    return 0;
}

int abr_plugin_unload(const abr_plugin_abi_t *abi)
{
    if (!abi) {
        return -1;
    }

    if (abi->shutdown) {
        abi->shutdown();
    }

    return 0;
}

/* ------------------------------------------------------------------------- */
/* v0.4 JSON carrier helpers                                                  */
/* ------------------------------------------------------------------------- */

abr_plugin_result abr_plugin_result_init(void)
{
    abr_plugin_result r;
    r.status = 0;
    r.message = NULL;
    r.json = NULL;
    return r;
}

abr_plugin_input abr_plugin_input_from_json(const char* json)
{
    abr_plugin_input in;
    in.json = json;
    return in;
}

