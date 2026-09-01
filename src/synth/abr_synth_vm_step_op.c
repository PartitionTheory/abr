#include "abr_context.h"
#include "abr_synth.h"
#include "abr_synth_operator.h"
#include "abr_json_min.h"

/*
 * Phoenix v0.4-greenbuild:
 * Synthetic VM Step Operator.
 *
 * Payload:
 *   {
 *     "count": N
 *   }
 */

static abr_synth_operator_t synth_vm_step_op = {
    .operator_id = 3001,
    .name = "synth.vm.step",
    .class_tag = "synth.vm.step"
};

static int synth_vm_step_exec(abr_context_t* ctx, void* args)
{
    const char* json = (const char*)args;

    int count = abr_json_min_get_int(json, "count");
    if (count <= 0) count = 1;

    int rc = abr_vm_step(ctx, count);

    char payload[128];
    snprintf(payload, sizeof(payload),
        "{ \"pc\": %d, \"status\": %d }",
        ctx->vm.pc,
        rc
    );

    return abr_synth_execute(ctx, &synth_vm_step_op, payload);
}

void abr_synth_vm_step_op_register(abr_context_t* ctx)
{
    abr_operator_t o = {
        .operator_id = synth_vm_step_op.operator_id,
        .name = synth_vm_step_op.name,
        .execute = synth_vm_step_exec
    };

    abr_register_operator(ctx, &o);
}

