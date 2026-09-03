/*
 * abr_plugin_registry_init.c — ABR v0.5
 *
 * Populates the ABR plugin registry with built-in plugins.
 * This file is intentionally minimal in v0.5; plugins are added here
 * when they are implemented.
 *
 * Phoenix Annotation (scflder):
 *   f = front of registry population
 *   s = second / step in plugin insertion
 *   l = last stage before registry freeze
 *   c = clock domain (plugin timing metadata)
 *   d = degree domain (plugin unary metadata)
 *   e = eternal set (plugin invariants)
 *   r = residue domain (last lookup result)
 */

#include "abr_plugin_registry.h"
#include "abr_plugin.h"

/* External registry table from abr_plugin_registry.c */
extern abr_plugin* registry[64];
extern size_t registry_count;

/* -------------------------------------------------------------------------
 * abr_plugin_registry_init_builtin
 *
 * Populates the registry with built-in plugins.
 * This is the 'f → s → l' sequence.
 * ------------------------------------------------------------------------- */
void abr_plugin_registry_init_builtin(void)
{
    /* f = front: begin population */
    registry_count = 0;

    /* s = second: insert plugins here when implemented
       Example:
       registry[registry_count++] = &reverse_plugin;
       registry[registry_count++] = &entropy_plugin;
    */

    /* l = last: registry is now frozen */
}

