#include "abr_context.h"
#include "abr_synth.h"
#include "abr_synth_operator.h"
#include "abr_json_min.h"

/*
 * Phoenix v0.4-greenbuild:
 * Synthetic VM Exec Operator.
 *
 * Executes a single instruction by name.
 */

static abr_synth_operator_t synth_vm_exec_op = {
    .operator_id = 3005,
    .name = "synth.vm.exec",
    .class_tag = "synth.vm.exec"
};

static int synth_vm_exec_exec(abr_context_t* ctx, void* args)
{
    const char* json = (const char*)args;

    const char* instr = abr_json_min_get_string(json, "instruction");

    int rc = abr_vm_exec(ctx, instr);

    char payload[256];
    snprintf(payload, sizeof(payload),
        "{ \"pc\": %d, \"status\": %d, \"instruction\": \"%s\" }",
        ctx->vm.pc,
        rc,
        instr
    );

    free((void*)instr);

    return abr_synth_execute(ctx, &synth_vm_exec_op, payload);
}

void abr_synth_vm_exec_op_register(abr_context_t* ctx)
{
    abr_operator_t o = {
        .operator_id = synth_vm_exec_op.operator_id,
        .name = synth_vm_exec_op.name,
        .execute = synth_vm_exec_exec
    };

    abr_register_operator(ctx, &o);
}

