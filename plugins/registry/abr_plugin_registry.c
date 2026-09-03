#include "abr_plugin_registry.h"
#include "abr_plugin.h"
#include <string.h>

/* -------------------------------------------------------------------------
 * Phase‑4 Plugin Factory Declarations
 * Each plugin .c file defines a create function; we declare them here.
 * ------------------------------------------------------------------------- */

extern abr_plugin* abr_plugin_invariant_explorer_create(void);
extern abr_plugin* abr_plugin_manifold_dynamics_create(void);
extern abr_plugin* abr_plugin_recursion_engine_create(void);
extern abr_plugin* abr_plugin_domain_creation_create(void);
extern abr_plugin* abr_plugin_externalization_create(void);
extern abr_plugin* abr_plugin_phi_stability_create(void);
extern abr_plugin* abr_plugin_density_index_create(void);
extern abr_plugin* abr_plugin_operator_chain_create(void);
extern abr_plugin* abr_plugin_graph_classifier_create(void);
extern abr_plugin* abr_plugin_domain_seed_create(void);

/* -------------------------------------------------------------------------
 * Phase‑4 Static Plugin Registry Table
 * ------------------------------------------------------------------------- */

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

/* -------------------------------------------------------------------------
 * Registry Accessor
 * ------------------------------------------------------------------------- */

const abr_plugin_descriptor* abr_plugin_registry(size_t* count)
{
    *count = sizeof(plugin_table) / sizeof(plugin_table[0]);
    return plugin_table;
}

/* -------------------------------------------------------------------------
 * Lookup by Name
 * ------------------------------------------------------------------------- */

abr_plugin* abr_plugin_registry_find_by_name(const char* name)
{
    size_t count = 0;
    const abr_plugin_descriptor* tbl = abr_plugin_registry(&count);

    for (size_t i = 0; i < count; i++) {
        if (strcmp(tbl[i].name, name) == 0) {
            return tbl[i].create_fn();
        }
    }
    return NULL;
}

/* -------------------------------------------------------------------------
 * Lookup by Class Tag (same as name for v0.4)
 * ------------------------------------------------------------------------- */

abr_plugin* abr_plugin_registry_find_by_class(const char* class_tag)
{
    size_t count = 0;
    const abr_plugin_descriptor* tbl = abr_plugin_registry(&count);

    for (size_t i = 0; i < count; i++) {
        if (strcmp(tbl[i].name, class_tag) == 0) {
            return tbl[i].create_fn();
        }
    }
    return NULL;
}

