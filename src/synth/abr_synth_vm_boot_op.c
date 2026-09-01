#include "abr_context.h"
#include "abr_synth.h"
#include "abr_synth_operator.h"

/*
 * Phoenix v0.4-greenbuild:
 * Synthetic VM Boot Operator.
 *
 * Initializes VM state inside the ABR context.
 */

static abr_synth_operator_t synth_vm_boot_op = {
    .operator_id = 3000,
    .name = "synth.vm.boot",
    .class_tag = "synth.vm.boot"
};

static int synth_vm_boot_exec(abr_context_t* ctx, void* args)
{
    (void)args;

    abr_vm_boot(ctx);

    const char* payload = "{ \"vm\": \"booted\" }";

    return abr_synth_execute(ctx, &synth_vm_boot_op, payload);
}

void abr_synth_vm_boot_op_register(abr_context_t* ctx)
{
    abr_operator_t o = {
        .operator_id = synth_vm_boot_op.operator_id,
        .name = synth_vm_boot_op.name,
        .execute = synth_vm_boot_exec
    };

    abr_register_operator(ctx, &o);
}

