#include "abr_context.h"
#include "abr_synth.h"
#include "abr_synth_operator.h"
#include "abr_synth_set.h"
#include <string.h>

/*
 * Phoenix v0.4-greenbuild:
 * Synthetic Operator #3 — Set-Activation Operator.
 *
 * This operator activates an entire synthetic operator set.
 * The JSON payload must contain:
 *   { "set": "<set-name>" }
 */

static abr_synth_operator_t synth_activate_op = {
    .operator_id = 1002,
    .name = "synth.activate",
    .class_tag = "synth.activate"
};

/*
 * Extract "set" from a simple JSON string.
 * This is intentionally minimal; full JSON parsing arrives in Step 41.
 */
static const char* extract_set_name(const char* json)
{
    if (!json) return NULL;

    const char* key = "\"set\":";
    const char* p = strstr(json, key);
    if (!p) return NULL;

    p += strlen(key);

    /* Skip whitespace and quotes */
    while (*p == ' ' || *p == '"' ) p++;

    const char* start = p;

    /* Read until quote or end */
    while (*p && *p != '"' && *p != '}') p++;

    static char buf[64];
    size_t len = p - start;
    if (len > 63) len = 63;

    memcpy(buf, start, len);
    buf[len] = '\0';

    return buf;
}

/*
 * Execute the set-activation operator.
 */
static int synth_activate_exec(abr_context_t* ctx, void* args)
{
    const char* json = (const char*)args;
    const char* set_name = extract_set_name(json);

    if (!set_name) {
        return -1;
    }

    abr_synth_set_register_all(ctx, set_name);
    return 0;
}

/*
 * Register Synthetic Operator #3.
 */
void abr_synth_activate_op_register(abr_context_t* ctx)
{
    abr_operator_t o = {
        .operator_id = synth_activate_op.operator_id,
        .name = synth_activate_op.name,
        .execute = synth_activate_exec
    };

    abr_register_operator(ctx, &o);
}

