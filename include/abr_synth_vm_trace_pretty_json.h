/*
 * abr_synth_vm_trace_pretty_json.h — ABR v0.5
 *
 * Hybrid pretty+JSON emitter for synthetic VM trace metadata.
 * Minimal in v0.5; expanded in v0.6+.
 *
 * Phoenix Annotation (scflder):
 *   f = front of hybrid emission
 *   s = second / step in field printing
 *   l = last stage before closing output
 *   c = clock domain (context clock may be printed)
 *   d = degree domain (window width may be printed)
 *   e = eternal set (invariants may be printed)
 *   r = residue domain (last result may be printed)
 */

#ifndef ABR_SYNTH_VM_TRACE_PRETTY_JSON_H
#define ABR_SYNTH_VM_TRACE_PRETTY_JSON_H

#include <stdio.h>
#include "abr_synth_vm_trace.h"

/* Emit a single trace event in hybrid format (f). */
static inline void abr_synth_vm_trace_event_pretty_json(
    const abr_synth_vm_trace_event* e
)
{
    printf("event: plugin=%s, clock=%llu, residue=%llu ",
        e->plugin_name,
        (unsigned long long)e->clock,
        (unsigned long long)e->residue
    );

    printf("{\"plugin\": \"%s\", \"clock\": %llu, \"residue\": %llu}\n",
        e->plugin_name,
        (unsigned long long)e->clock,
        (unsigned long long)e->residue
    );
}

/* Emit entire trace in hybrid format (l). */
static inline void abr_synth_vm_trace_pretty_json(
    const abr_synth_vm_trace* t
)
{
    printf("[\n");
    for (size_t i = 0; i < t->count; i++) {
        abr_synth_vm_trace_event_pretty_json(&t->events[i]);
    }
    printf("]\n");
}

#endif /* ABR_SYNTH_VM_TRACE_PRETTY_JSON_H */

