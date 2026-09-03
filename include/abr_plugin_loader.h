/*
 * abr_plugin_loader.h — ABR v0.5
 *
 * Plugin loader for ABR.
 * Provides lookup and enumeration of built-in plugins.
 * Dynamic loading is introduced in v0.6.
 *
 * Phoenix Annotation (scflder):
 *   f = front of loader entry
 *   s = second / step in plugin lookup
 *   l = last stage before returning plugin
 *   c = clock domain (context clock may advance)
 *   d = degree domain (window width may change)
 *   e = eternal set (invariants preserved)
 *   r = residue domain (last result stored)
 */

#ifndef ABR_PLUGIN_LOADER_H
#define ABR_PLUGIN_LOADER_H

#include "abr_plugin.h"

/* Built-in plugin table (v0.5 static). */
extern const abr_plugin* abr_builtin_plugins[];
extern const size_t abr_builtin_plugin_count;

/* -------------------------------------------------------------------------
 * abr_plugin_by_name
 *
 * Lookup a plugin by name.
 * ------------------------------------------------------------------------- */
static inline const abr_plugin* abr_plugin_by_name(const char* name)
{
    for (size_t i = 0; i < abr_builtin_plugin_count; i++) {
        const abr_plugin* p = abr_builtin_plugins[i];
        if (p && p->name && name && strcmp(p->name, name) == 0)
            return p;
    }
    return NULL;
}

/* -------------------------------------------------------------------------
 * abr_plugin_by_index
 *
 * Lookup a plugin by index.
 * ------------------------------------------------------------------------- */
static inline const abr_plugin* abr_plugin_by_index(size_t idx)
{
    if (idx >= abr_builtin_plugin_count)
        return NULL;
    return abr_builtin_plugins[idx];
}

#endif /* ABR_PLUGIN_LOADER_H */

