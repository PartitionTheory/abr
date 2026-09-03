/*
 * abr_vm.h — ABR v0.5
 *
 * Public interface for the ABR virtual machine.
 * Defines the VM lifecycle and execution API used by the core runtime,
 * dispatch layer, and plugin system.
 *
 * Phoenix Annotation (scflder):
 *   f = front of VM entry
 *   s = second / step in execution path selection
 *   l = last stage before returning residue
 *   c = clock domain incremented on execution
 *   d = degree domain may be adjusted by plugin metadata
 *   e = eternal set preserved across VM operations
 *   r = residue domain produced after execution
 */

#ifndef ABR_VM_H
#define ABR_VM_H

#include "abr_context.h"
#include "abr_plugin.h"

/* Initialize the VM (f). */
int abr_vm_init(abr_context_t* ctx);

/* Shut down the VM (l). */
void abr_vm_shutdown(abr_context_t* ctx);

/* Execute a plugin inside the VM (f → s → l sequence). */
int abr_vm_execute(abr_plugin_t* plugin, abr_context_t* ctx);

#endif /* ABR_VM_H */

