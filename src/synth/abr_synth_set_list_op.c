#include "abr_context.h"
#include "abr_synth.h"
#include "abr_synth_operator.h"
#include "abr_synth_set.h"

/*
 * Phoenix v0.4-greenbuild:
 * Synthetic Operator Set Enumeration.
 */

static abr_synth_operator_t synth_set_list_op = {
    .operator_id = 2007,
    .name = "synth.set.list",
    .class_tag = "synth.set.list"
};

static int synth_set_list_exec(abr_context_t* ctx, void* args)
{
    (void)args;

    abr_synth_set_info_t* list = NULL;
    size_t count = abr_synth_set_list(ctx, &list);

    char payload[512];
    size_t offset = 0;

    offset += snprintf(payload + offset, sizeof(payload) - offset, "{ \"sets\": [");

    for (size_t i = 0; i < count; i++) {
        offset += snprintf(payload + offset, sizeof(payload) - offset,
            "{ \"name\": \"%s\", \"active\": %d, \"count\": %zu }%s",
            list[i].name,
            list[i].active,
            list[i].count,
            (i + 1 < count ? ", " : "")
        );
    }

    snprintf(payload + offset, sizeof(payload) - offset, "] }");

    free(list);

    return abr_synth_execute(ctx, &synth_set_list_op, payload);
}

void abr_synth_set_list_op_register(abr_context_t* ctx)
{
    abr_operator_t o = {
        .operator_id = synth_set_list_op.operator_id,
        .name = synth_set_list_op.name,
        .execute = synth_set_list_exec
    };

    abr_register_operator(ctx, &o);
}

