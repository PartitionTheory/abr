#include "abr_plugin.h"
#include "abr_synth.h"
#include "abr_core.h"

static const char* plugin_name = "operator_chain";

abr_plugin_result abr_plugin_execute(const abr_plugin_input* input) {
    abr_plugin_result result = {0};

    // v0.4: Operator chain stub
    result.status = 1;
    result.message = "Operator Chain: sequence of operators evaluated.";
    result.json =
    "{"
    "\"epoch\":\"phoenix\","
    "\"chain\":{\"length\":1,\"state\":\"linked\"}"
    "}";

    return result;
}

const char* abr_plugin_name() {
    return plugin_name;
}

abr_plugin* abr_plugin_operator_chain_create() {
    abr_plugin* p = malloc(sizeof(abr_plugin));
    if (!p) return NULL;

    p->name = plugin_name;
    p->execute = abr_plugin_execute;

    return p;
}
