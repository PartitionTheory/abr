#include "abr_context.h"
#include "abr_synth.h"
#include "abr_synth_operator.h"
#include "abr_json_min.h"

/*
 * Phoenix v0.4-greenbuild:
 * Synthetic VM Program Load Operator.
 *
 * Loads a program (array of instruction names) into the VM.
 */

static abr_synth_operator_t synth_vm_pload_op = {
    .operator_id = 3010,
    .name = "synth.vm.pload",
    .class_tag = "synth.vm.pload"
};

static int synth_vm_pload_exec(abr_context_t* ctx, void* args)
{
    const char* json = (const char*)args;

    int count = 0;
    char** list = abr_json_min_get_string_array(json, "program", &count);

    int rc = abr_vm_program_load(ctx, list, count);

    for (int i = 0; i < count; i++)
        free(list[i]);
    free(list);

    char payload[128];
    snprintf(payload, sizeof(payload),
        "{ \"program_loaded\": %s, \"length\": %d }",
        rc == 0 ? "true" : "false",
        count
    );

    return abr_synth_execute(ctx, &synth_vm_pload_op, payload);
}

void abr_synth_vm_pload_op_register(abr_context_t* ctx)
{
    abr_operator_t o = {
        .operator_id = synth_vm_pload_op.operator_id,
        .name = synth_vm_pload_op.name,
        .execute = synth_vm_pload_exec
    };

    abr_register_operator(ctx, &o);
}

