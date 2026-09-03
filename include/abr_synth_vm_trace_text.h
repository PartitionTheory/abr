/*
 * abr_synth_vm_trace_text.h — ABR v0.5
 *
 * Plain-text emitter for synthetic VM trace metadata.
 * Minimal in v0.5; expanded in v0.6+.
 *
 * Phoenix Annotation (scflder):
 *   f = front of text emission
 *   s = second / step in field printing
 *   l = last stage before closing output
 *   c = clock domain (context clock may be printed)
 *   d = degree domain (window width may be printed)
 *   e = eternal set (invariants may be printed)
 *   r = residue domain (last result may be printed)
 */

#ifndef ABR_SYNTH_VM_TRACE_TEXT_H
#define ABR_SYNTH_VM_TRACE_TEXT_H

#include <stdio.h>
#include "abr_synth_vm_trace.h"

/* Emit a single trace event in plain text (f). */
static inline void abr_synth_vm_trace_event_text(
    const abr_synth_vm_trace_event* e
)
{
    printf("plugin=%s clock=%llu residue=%llu\n",
        e->plugin_name,
        (unsigned long long)e->clock,
        (unsigned long long)e->residue
    );
}

/* Emit entire trace in plain text (l). */
static inline void abr_synth_vm_trace_text(
    const abr_synth_vm_trace* t
)
{
    for (size_t i = 0; i < t->count; i++) {
        abr_synth_vm_trace_event_text(&t->events[i]);
    }
}

#endif /* ABR_SYNTH_VM_TRACE_TEXT_H */

