/*
 * abr_synth_vm_trace_dump.h — ABR v0.5
 *
 * Raw dump emitter for synthetic VM trace metadata.
 * Minimal in v0.5; expanded in v0.6+.
 *
 * Phoenix Annotation (scflder):
 *   f = front of dump emission
 *   s = second / step in field dumping
 *   l = last stage before closing output
 *   c = clock domain (context clock may be dumped)
 *   d = degree domain (window width may be dumped)
 *   e = eternal set (invariants may be dumped)
 *   r = residue domain (last result may be dumped)
 */

#ifndef ABR_SYNTH_VM_TRACE_DUMP_H
#define ABR_SYNTH_VM_TRACE_DUMP_H

#include <stdio.h>
#include <stdint.h>
#include "abr_synth_vm_trace.h"

/* Dump a single trace event (f). */
static inline void abr_synth_vm_trace_event_dump(
    const abr_synth_vm_trace_event* e
)
{
    printf("EVENT\n");
    printf("PLUGIN: %s\n", e->plugin_name);
    printf("CLOCK: %llu\n", (unsigned long long)e->clock);
    printf("RESIDUE: %llu\n", (unsigned long long)e->residue);
    printf("\n");
}

/* Dump entire trace (l). */
static inline void abr_synth_vm_trace_dump(
    const abr_synth_vm_trace* t
)
{
    printf("TRACE DUMP BEGIN\n\n");
    for (size_t i = 0; i < t->count; i++) {
        abr_synth_vm_trace_event_dump(&t->events[i]);
    }
    printf("TRACE DUMP END\n");
}

#endif /* ABR_SYNTH_VM_TRACE_DUMP_H */

