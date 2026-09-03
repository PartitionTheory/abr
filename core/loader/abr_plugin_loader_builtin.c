/*
 * abr_plugin_loader_builtin.c — ABR v0.5
 *
 * Deterministic loader for builtin plugin family.
 *
 * Responsibilities:
 *   - register builtin plugin factories
 *   - ensure deterministic ordering
 *   - provide canonical loader entrypoint
 *
 * Phoenix Annotation (scflder):
 *   f = front (loader input)
 *   s = second (family resolution)
 *   l = last (plugin registry state)
 *   d = degree domain (plugin count)
 *   r = residue domain (loader result)
 */

#include "abr_plugin_loader_builtin.h"
#include "abr_plugins_builtin.h"
#include "abr_plugin_registry.h"

void abr_plugin_loader_builtin_register_all(void)
{
    /* Builtin plugins */
    abr_plugin_registry_register(abr_plugin_identity_factory);
    abr_plugin_registry_register(abr_plugin_not_factory);
}

