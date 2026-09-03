/*
 * abr_plugin_loader.c — ABR v0.5
 *
 * Unified plugin loader entrypoint.
 *
 * Responsibilities:
 *   - initialize plugin registry
 *   - register builtin plugin family
 *   - register math_v4 plugin family
 *   - provide deterministic loader entrypoint for ABR runtime
 *
 * Phoenix Annotation (scflder):
 *   f = front (loader input)
 *   s = second (family resolution)
 *   l = last (plugin registry state)
 *   d = degree domain (plugin count)
 *   r = residue domain (loader result)
 */

#include "abr_plugin_loader.h"
#include "abr_plugin_loader_builtin.h"
#include "abr_plugin_loader_math_v4.h"
#include "abr_plugin_registry.h"

void abr_plugin_loader_init(void)
{
    /* Initialize registry */
    abr_plugin_registry_init();

    /* Register builtin plugins */
    abr_plugin_loader_builtin_register_all();

    /* Register math_v4 plugins */
    abr_plugin_loader_math_v4_register_all();
}

