/*
 * abr_plugin_loader_math_v4.c — ABR v0.5
 *
 * Deterministic loader for math_v4 plugin family.
 *
 * Responsibilities:
 *   - register all math_v4 plugin factories
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

#include "abr_plugin_loader_math_v4.h"
#include "abr_math_v4_plugins.h"
#include "abr_plugin_registry.h"

void abr_plugin_loader_math_v4_register_all(void)
{
    /* Core math_v4 plugins */
    abr_plugin_registry_register(abr_plugin_manifold_dynamics_factory);
    abr_plugin_registry_register(abr_plugin_invariant_explorer_factory);
    abr_plugin_registry_register(abr_plugin_recursion_engine_factory);
    abr_plugin_registry_register(abr_plugin_density_index_factory);
    abr_plugin_registry_register(abr_plugin_phi_stability_factory);
    abr_plugin_registry_register(abr_plugin_domain_seed_factory);
    abr_plugin_registry_register(abr_plugin_operator_chain_factory);

    /* Extended family */
    abr_plugin_registry_register(abr_plugin_manifold_dynamics_extension_factory);
}

