/*
 * abr_synth_vm_trace_pretty.h — ABR v0.5
 *
 * Human-readable pretty-printer for synthetic VM trace metadata.
 * Minimal in v0.5; expanded in v0.6+.
 *
 * Phoenix Annotation (scflder):
 *   f = front of pretty-print entry
 *   s = second / step in field printing
 *   l = last stage before closing output
 *   c = clock domain (context clock may be printed)
 *   d = degree domain (window width may be printed)
 *   e = eternal set (invariants may be printed)
 *   r = residue domain (last result may be printed)
 */

#ifndef ABR_SYNTH_VM_TRACE_PRETTY_H
#define ABR_SYNTH_VM_TRACE_PRETTY_H

#include <stdio.h>
#include "abr_synth_vm_trace.h"

/* Print a single trace event (f). */
static inline void abr_synth_vm_trace_event_pretty(
    const abr_synth_vm_trace_event* e
)
{
    printf("plugin=%s, clock=%llu, residue=%llu\n",
        e->plugin_name,
        (unsigned long long)e->clock,
        (unsigned long long)e->residue
    );
}

/* Print entire trace (l). */
static inline void abr_synth_vm_trace_pretty(
    const abr_synth_vm_trace* t
)
{
    for (size_t i = 0; i < t->count; i++) {
        abr_synth_vm_trace_event_pretty(&t->events[i]);
    }
}

#endif /* ABR_SYNTH_VM_TRACE_PRETTY_H */

