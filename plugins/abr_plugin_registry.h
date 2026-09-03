/*
 * abr_plugin_registry.h — ABR v0.5
 *
 * Canonical plugin registry for ABR.
 * Provides:
 *   - plugin registration
 *   - plugin lookup by name
 *   - unified metadata for all plugin families
 *
 * Phoenix Annotation (scflder):
 *   f = front (registry input)
 *   s = second (lookup step)
 *   l = last (resolved plugin)
 *   d = degree domain (window width)
 *   r = residue domain (plugin result)
 */

#ifndef ABR_PLUGIN_REGISTRY_H
#define ABR_PLUGIN_REGISTRY_H

#include <stddef.h>
#include "abr_plugin.h"

/* Maximum number of plugins that can be registered. */
#define ABR_MAX_PLUGINS 64

/* Plugin registry entry. */
typedef struct abr_plugin_registry_entry {
    const char* name;
    abr_plugin* plugin;
} abr_plugin_registry_entry;

/* Registry object. */
typedef struct abr_plugin_registry {
    abr_plugin_registry_entry entries[ABR_MAX_PLUGINS];
    size_t count;
} abr_plugin_registry;

/* Global registry instance (defined in abr_plugin_registry.c). */
extern abr_plugin_registry abr_registry;

/* Initialize registry. */
void abr_plugin_registry_init(void);

/* Register plugin. */
void abr_plugin_registry_add(abr_plugin* plugin);

/* Lookup plugin by name. */
abr_plugin* abr_plugin_registry_get(const char* name);

#endif /* ABR_PLUGIN_REGISTRY_H */

