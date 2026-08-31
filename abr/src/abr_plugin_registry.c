/*
 * ABR-Rebirth: Plugin Registry
 *
 * Manages loaded plugins and provides a central registry structure.
 */

#include "abr_plugin.h"
#include "abr_core.h"

#include <stdlib.h>
#include <string.h>

/* ------------------------------------------------------------------------- */
/* Registry structure                                                         */
/* ------------------------------------------------------------------------- */

typedef struct abr_plugin_registry {
    const abr_plugin_abi_t **plugins;
    size_t count;
    size_t capacity;
} abr_plugin_registry_t;

/* Internal helper to get or create registry */
static abr_plugin_registry_t *abr_get_registry(abr_runtime_t *rt)
{
    if (!rt || !rt->initialized) {
        return NULL;
    }

    if (!rt->plugin_registry) {
        abr_plugin_registry_t *reg =
            (abr_plugin_registry_t *)malloc(sizeof(abr_plugin_registry_t));
        if (!reg) {
            return NULL;
        }

        reg->plugins  = NULL;
        reg->count    = 0;
        reg->capacity = 0;

        rt->plugin_registry = reg;
    }

    return (abr_plugin_registry_t *)rt->plugin_registry;
}

/* ------------------------------------------------------------------------- */
/* Load plugin into registry                                                  */
/* ------------------------------------------------------------------------- */

int abr_plugin_registry_add(abr_runtime_t *rt, const abr_plugin_abi_t *abi)
{
    abr_plugin_registry_t *reg = abr_get_registry(rt);
    if (!reg) {
        return -1;
    }

    /* Grow registry if needed */
    if (reg->count == reg->capacity) {
        size_t new_cap = (reg->capacity == 0) ? 4 : reg->capacity * 2;
        const abr_plugin_abi_t **new_list =
            (const abr_plugin_abi_t **)realloc(reg->plugins,
                                               new_cap * sizeof(*new_list));
        if (!new_list) {
            return -2;
        }

        reg->plugins  = new_list;
        reg->capacity = new_cap;
    }

    reg->plugins[reg->count++] = abi;
    return 0;
}

/* ------------------------------------------------------------------------- */
/* Unload plugin from registry                                                */
/* ------------------------------------------------------------------------- */

int abr_plugin_registry_remove(abr_runtime_t *rt, const abr_plugin_abi_t *abi)
{
    abr_plugin_registry_t *reg = abr_get_registry(rt);
    if (!reg) {
        return -1;
    }

    for (size_t i = 0; i < reg->count; ++i) {
        if (reg->plugins[i] == abi) {

            /* Call plugin shutdown */
            abr_plugin_unload(abi);

            /* Compact list */
            memmove(&reg->plugins[i],
                    &reg->plugins[i + 1],
                    (reg->count - i - 1) * sizeof(*reg->plugins));

            reg->count--;
            return 0;
        }
    }

    return -2; /* Not found */
}

