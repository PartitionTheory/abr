#include "abr_plugin_registry.h"
#include "abr_plugin.h"

// v0.4 plugin headers
#include "invariant_explorer.h"
#include "manifold_dynamics.h"
#include "recursion_engine.h"
#include "domain_creation.h"
#include "externalization.h"
#include "phi_stability.h"
#include "density_index.h"
#include "operator_chain.h"
#include "graph_classifier.h"
#include "domain_seed.h"

static const abr_plugin_descriptor plugin_table[] = {
    { "invariant_explorer",   abr_plugin_invariant_explorer_create },
    { "manifold_dynamics",    abr_plugin_manifold_dynamics_create },
    { "recursion_engine",     abr_plugin_recursion_engine_create },
    { "domain_creation",      abr_plugin_domain_creation_create },
    { "externalization",      abr_plugin_externalization_create },
    { "phi_stability",        abr_plugin_phi_stability_create },
    { "density_index",        abr_plugin_density_index_create },
    { "operator_chain",       abr_plugin_operator_chain_create },
    { "graph_classifier",     abr_plugin_graph_classifier_create },
    { "domain_seed",          abr_plugin_domain_seed_create }
};

const abr_plugin_descriptor* abr_plugin_registry(size_t* count) {
    *count = sizeof(plugin_table) / sizeof(plugin_table[0]);
    return plugin_table;
}

