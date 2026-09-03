/*
 * abr_plugin_registry.c — ABR v0.5
 *
 * Canonical plugin registry for ABR.
 * Implements:
 *   - plugin registration
 *   - plugin lookup by name
 *   - global registry instance
 *
 * Phoenix Annotation (scflder):
 *   f = front (registry input)
 *   s = second (lookup step)
 *   l = last (resolved plugin)
 *   d = degree domain (window width)
 *   r = residue domain (plugin result)
 */

#include "abr_plugin_registry.h"
#include <string.h>

/* Global registry instance. */
abr_plugin_registry abr_registry;

/* Initialize registry. */
void abr_plugin_registry_init(void)
{
    abr_registry.count = 0;
}

/* Register plugin. */
void abr_plugin_registry_add(abr_plugin* plugin)
{
    if (!plugin) return;
    if (abr_registry.count >= ABR_MAX_PLUGINS) return;

    abr_registry.entries[abr_registry.count].name   = plugin->name;
    abr_registry.entries[abr_registry.count].plugin = plugin;
    abr_registry.count++;
}

/* Lookup plugin by name. */
abr_plugin* abr_plugin_registry_get(const char* name)
{
    if (!name) return NULL;

    for (size_t i = 0; i < abr_registry.count; i++) {
        if (strcmp(abr_registry.entries[i].name, name) == 0) {
            return abr_registry.entries[i].plugin;
        }
    }

    return NULL;
}

