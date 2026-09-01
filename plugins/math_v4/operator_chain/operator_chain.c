#include "abr_plugin.h"
#include "abr_synth.h"
#include "abr_core.h"

static const char* plugin_name = "operator_chain";

abr_plugin_result abr_plugin_execute(const abr_plugin_input* input) {
    abr_plugin_result result = {0};

    // v0.4: Operator chain stub
    result.status = 1;
    result.message = "Operator Chain: sequence of operators evaluated.";

    return result;
}

const char* abr_plugin_name() {
    return plugin_name;
}

