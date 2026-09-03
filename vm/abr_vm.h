/*
 * abr_vm.h — ABR v0.5
 *
 * VM interface.
 */

#ifndef ABR_VM_H
#define ABR_VM_H

#include "abr_system.h"
#include "abr_plugin_result.h"

typedef struct abr_vm
{
    int running;
    abr_system sys;

} abr_vm;

void abr_vm_init(abr_vm* vm);
void abr_vm_destroy(abr_vm* vm);

abr_plugin_result abr_vm_execute_instruction(
    abr_vm* vm,
    const char* instr
);

abr_plugin_result abr_vm_execute_pipeline(
    abr_vm* vm,
    const char** names,
    size_t count
);

void abr_vm_repl(abr_vm* vm);

#endif /* ABR_VM_H */

