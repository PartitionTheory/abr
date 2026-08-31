#include "../../include/abr_plugin_loader.h"
#include <dlfcn.h>
#include <stdio.h>

/*
 * ABR‑Rebirth: Plugin Operator Loader Implementation
 * --------------------------------------------------
 * Phase 4 Step 06
 *
 * This file provides the initial implementation for dynamically
 * loading plugin shared libraries and registering their operators
 * with the ABR runtime. Later Phase 4 steps will expand this with
 * safety checks, ABI validation, and reversible plugin behavior.
 */

int abr_plugin_loader_load(abr_runtime_t *rt, const char *path)
{
    if (!rt || !path) {
        return -1;
    }

    void *handle = dlopen(path, RTLD_NOW);
    if (!handle) {
        fprintf(stderr, "Failed to load plugin: %s\n", path);
        return -1;
    }

    /* Lookup the plugin ABI symbol. */
    const abr_plugin_abi_t *(*get_abi)(void) = dlsym(handle, "abr_get_plugin_abi");
    if (!get_abi) {
        fprintf(stderr, "Invalid plugin ABI: %s\n", path);
        dlclose(handle);
        return -1;
    }

    const abr_plugin_abi_t *abi = get_abi();
    if (!abi) {
        dlclose(handle);
        return -1;
    }

    /* Register plugin operators via existing Phase 3 loader. */
    int rc = abr_plugin_load(rt, abi);
    if (rc != 0) {
        dlclose(handle);
        return -1;
    }

    /* Add plugin to registry. */
    return abr_plugin_registry_add(rt, path, handle, abi);
}

int abr_plugin_loader_unload(abr_runtime_t *rt, const char *path)
{
    if (!rt || !path) {
        return -1;
    }

    /* Remove plugin from registry and unload. */
    return abr_plugin_registry_remove(rt, path);
}
int abr_plugin_load(abr_runtime_t *rt, const abr_plugin_abi_t *abi)
{
    /* Phase‑4 stub: real operator registration happens in registry_add */
    (void)rt;
    (void)abi;
    return 0;
}

