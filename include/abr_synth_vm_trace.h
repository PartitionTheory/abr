/*
 * abr_synth_vm_trace.h — ABR v0.5
 *
 * Synthetic trace metadata for the VM layer.
 * Minimal in v0.5; expanded in v0.6+.
 *
 * Phoenix Annotation (scflder):
 *   f = front of trace entry
 *   s = second / step in trace assembly
 *   l = last stage before returning trace
 *   c = clock domain (context clock may advance)
 *   d = degree domain (window width may change)
 *   e = eternal set (invariants preserved)
 *   r = residue domain (last result stored)
 */

#ifndef ABR_SYNTH_VM_TRACE_H
#define ABR_SYNTH_VM_TRACE_H

#include <stddef.h>
#include <stdint.h>
#include "abr_vm.h"

/* Synthetic VM trace event. */
typedef struct abr_synth_vm_trace_event {
    const char* plugin_name;
    uint64_t    clock;
    uint64_t    residue;
} abr_synth_vm_trace_event;

/* Synthetic VM trace object. */
typedef struct abr_synth_vm_trace {
    abr_synth_vm_trace_event events[64]; /* v0.5 fixed-size buffer */
    size_t count;
} abr_synth_vm_trace;

/* Initialize trace (f). */
static inline void abr_synth_vm_trace_init(abr_synth_vm_trace* t)
{
    if (!t) return;
    t->count = 0;
}

/* Destroy trace (l). */
static inline void abr_synth_vm_trace_destroy(abr_synth_vm_trace* t)
{
    (void)t;
    /* v0.5: no dynamic fields */
}

/* Append event (s). */
static inline void abr_synth_vm_trace_append(
    abr_synth_vm_trace* t,
    const abr_vm* vm,
    const char* plugin_name
)
{
    if (!t || t->count >= 64) return;

    abr_synth_vm_trace_event* e = &t->events[t->count++];
    e->plugin_name = plugin_name;
    e->clock       = vm->ctx.clock;
    e->residue     = vm->ctx.residue;
}

#endif /* ABR_SYNTH_VM_TRACE_H */

