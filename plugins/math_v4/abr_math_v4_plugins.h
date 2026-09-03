/*
 * abr_math_v4_plugins.h — ABR v0.5
 *
 * Canonical index for all math_v4 plugins.
 * Provides:
 *   - factory declarations
 *   - unified include point for loader and registry
 *   - deterministic ordering of plugin families
 *
 * Phoenix Annotation (scflder):
 *   f = front (plugin input)
 *   s = second (family resolution)
 *   l = last (plugin instance)
 *   d = degree domain (window width)
 *   r = residue domain (plugin result)
 */

#ifndef ABR_MATH_V4_PLUGINS_H
#define ABR_MATH_V4_PLUGINS_H

#include "abr_plugin.h"

/* Core math_v4 plugins */
abr_plugin* abr_plugin_manifold_dynamics_factory(void);
abr_plugin* abr_plugin_invariant_explorer_factory(void);
abr_plugin* abr_plugin_recursion_engine_factory(void);
abr_plugin* abr_plugin_density_index_factory(void);
abr_plugin* abr_plugin_phi_stability_factory(void);
abr_plugin* abr_plugin_domain_seed_factory(void);
abr_plugin* abr_plugin_operator_chain_factory(void);

/* Extended family */
abr_plugin* abr_plugin_manifold_dynamics_extension_factory(void);

#endif /* ABR_MATH_V4_PLUGINS_H */

