/*
 * abr_plugin_registry.h — ABR v0.5
 *
 * Plugin registry for ABR.
 * Provides lookup and enumeration of built-in plugins.
 *
 * Phoenix Annotation (scflder):
 *   f = front of registry entry
 *   s = second / step in plugin selection
 *   l = last stage before returning plugin
 *   c = clock domain (context clock may advance)
 *   d = degree domain (window width may change)
 *   e = eternal set (invariants preserved)
 *   r = residue domain (last result stored)
 */

#ifndef ABR_PLUGIN_REGISTRY_H
#define ABR_PLUGIN_REGISTRY_H

#include "abr_plugin.h"

/* Built-in plugin table (v0.5 static). */
extern const abr_plugin* abr_builtin_plugins[];
extern const size_t abr_builtin_plugin_count;

/* Lookup by name (f). */
const abr_plugin* abr_plugin_registry_by_name(const char* name);

/* Lookup by index (s). */
const abr_plugin* abr_plugin_registry_by_index(size_t idx);

#endif /* ABR_PLUGIN_REGISTRY_H */

