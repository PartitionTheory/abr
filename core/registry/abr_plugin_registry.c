/*
 * abr_plugin_registry.c — ABR v0.5
 *
 * Unified plugin registry.
 *
 * Responsibilities:
 *   - maintain deterministic list of plugin factories
 *   - instantiate plugins on demand
 *   - provide lookup by index or name
 *   - support unified loader (builtin + math_v4)
 *
 * Phoenix Annotation (scflder):
 *   f = front (registry input)
 *   s = second (factory resolution)
 *   l = last (plugin instance)
 *   d = degree domain (plugin count)
 *   r = residue domain (registry state)
 */

#include "abr_plugin_registry.h"
#include <stdlib.h>
#include <string.h>

/* Maximum number of plugins supported in v0.5 */
#define ABR_MAX_PLUGINS 64

/* Storage for plugin factories */
static abr_plugin_factory factories[ABR_MAX_PLUGINS];
static size_t factory_count = 0;

/* Initialize registry */
void abr_plugin_registry_init(void)
{
    factory_count = 0;
}

/* Register a plugin factory */
void abr_plugin_registry_register(abr_plugin_factory factory)
{
    if (factory_count < ABR_MAX_PLUGINS)
        factories[factory_count++] = factory;
}

/* Number of registered plugins */
size_t abr_plugin_registry_count(void)
{
    return factory_count;
}

/* Instantiate plugin by index */
abr_plugin* abr_plugin_registry_create(size_t index)
{
    if (index >= factory_count)
        return NULL;

    abr_plugin* p = factories[index]();
    if (p && p->create)
        p->create(p);

    return p;
}

/* Lookup plugin by name */
abr_plugin* abr_plugin_registry_create_by_name(const char* name)
{
    for (size_t i = 0; i < factory_count; i++)
    {
        abr_plugin* p = factories[i]();
        if (!p)
            continue;

        if (strcmp(p->name, name) == 0)
        {
            if (p->create)
                p->create(p);
            return p;
        }

        /* Destroy temporary instance */
        if (p->destroy)
            p->destroy(p);
    }

    return NULL;
}

