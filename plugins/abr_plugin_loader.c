/*
 * abr_plugin_loader.c — ABR v0.5
 *
 * Canonical plugin loader for ABR.
 * Implements:
 *   - static plugin loading
 *   - registry population
 *   - built‑in plugin initialization
 *
 * Phoenix Annotation (scflder):
 *   f = front (loader input)
 *   s = second (load step)
 *   l = last (loaded plugin)
 *   d = degree domain (window width)
 *   r = residue domain (plugin result)
 */

#include "abr_plugin_loader.h"
#include "abr_plugin_registry.h"

/* Forward declarations for built‑in plugin factories (v0.5 minimal). */
extern abr_plugin* abr_plugin_identity_factory(void);
extern abr_plugin* abr_plugin_not_factory(void);

/* Load a single plugin into the registry. */
void abr_plugin_loader_load(abr_plugin* plugin)
{
    if (!plugin) return;
    abr_plugin_registry_add(plugin);
}

/* Load all built‑in plugins (v0.5 minimal). */
void abr_plugin_loader_load_builtin(void)
{
    abr_plugin_registry_init();

    /* Identity plugin */
    abr_plugin* p_identity = abr_plugin_identity_factory();
    abr_plugin_loader_load(p_identity);

    /* NOT plugin */
    abr_plugin* p_not = abr_plugin_not_factory();
    abr_plugin_loader_load(p_not);
}

