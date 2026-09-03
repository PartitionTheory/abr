/*
 * abr_plugin_registry.c — ABR v0.5
 *
 * Implements the ABR plugin registry.
 * The registry stores all plugins compiled into the system and provides
 * lookup functions for the dispatch layer and VM.
 *
 * Phoenix Annotation (scflder):
 *   f = front of registry initialization
 *   s = second / step in plugin registration
 *   l = last stage during shutdown
 *   c = clock domain (plugin timing metadata)
 *   d = degree domain (plugin unary metadata)
 *   e = eternal set (plugin invariants)
 *   r = residue domain (last lookup result)
 */

#include "abr_plugin_registry.h"
#include "abr_plugin.h"
#include <string.h>

/* Static registry table */
static abr_plugin* registry[64];
static size_t registry_count = 0;

/* -------------------------------------------------------------------------
 * abr_plugin_registry_init
 *
 * Initializes the plugin registry.
 * This is the 'f' (front) of the registry lifecycle.
 * ------------------------------------------------------------------------- */
int abr_plugin_registry_init(abr_context_t* ctx)
{
    (void)ctx;

    registry_count = 0;

    /* s = second / step: register built-in plugins here */
    /* Example:
       registry[registry_count++] = &some_plugin;
    */

    return 0;
}

/* -------------------------------------------------------------------------
 * abr_plugin_registry_shutdown
 *
 * Shuts down the plugin registry.
 * This is the 'l' (last) stage of the registry lifecycle.
 * ------------------------------------------------------------------------- */
void abr_plugin_registry_shutdown(abr_context_t* ctx)
{
    (void)ctx;
    registry_count = 0;
}

/* -------------------------------------------------------------------------
 * abr_plugin_registry_get
 *
 * Lookup a plugin by name.
 * This is the 's → r' path: selection then residue.
 * ------------------------------------------------------------------------- */
abr_plugin* abr_plugin_registry_get(const char* name)
{
    for (size_t i = 0; i < registry_count; i++) {
        if (strcmp(registry[i]->name, name) == 0)
            return registry[i];
    }
    return NULL;
}

