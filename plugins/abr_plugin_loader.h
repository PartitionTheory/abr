/*
 * abr_plugin_loader.h — ABR v0.5
 *
 * Canonical plugin loader for ABR.
 * Provides:
 *   - static plugin loading
 *   - dynamic plugin loading (future extension)
 *   - registry population
 *
 * Phoenix Annotation (scflder):
 *   f = front (loader input)
 *   s = second (load step)
 *   l = last (loaded plugin)
 *   d = degree domain (window width)
 *   r = residue domain (plugin result)
 */

#ifndef ABR_PLUGIN_LOADER_H
#define ABR_PLUGIN_LOADER_H

#include "abr_plugin.h"

/* Load a single plugin into the registry. */
void abr_plugin_loader_load(abr_plugin* plugin);

/* Load all built‑in plugins (v0.5 minimal). */
void abr_plugin_loader_load_builtin(void);

#endif /* ABR_PLUGIN_LOADER_H */

