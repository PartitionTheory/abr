/*
 * abr_synth_vm_trace_json.h — ABR v0.5
 *
 * JSON emitter for synthetic VM trace metadata.
 * Minimal in v0.5; expanded in v0.6+.
 *
 * Phoenix Annotation (scflder):
 *   f = front of JSON emission
 *   s = second / step in field printing
 *   l = last stage before closing brace
 *   c = clock domain (context clock may be printed)
 *   d = degree domain (window width may be printed)
 *   e = eternal set (invariants may be printed)
 *   r = residue domain (last result may be printed)
 */

#ifndef ABR_SYNTH_VM_TRACE_JSON_H
#define ABR_SYNTH_VM_TRACE_JSON_H

#include <stdio.h>
#include "abr_synth_vm_trace.h"

/* Emit a single trace event as JSON (f). */
static inline void abr_synth_vm_trace_event_json(
    const abr_synth_vm_trace_event* e
)
{
    printf("{");
    printf("\"plugin\": \"%s\", ", e->plugin_name);
    printf("\"clock\": %llu, ", (unsigned long long)e->clock);
    printf("\"residue\": %llu", (unsigned long long)e->residue);
    printf("}");
}

/* Emit entire trace as JSON array (l). */
static inline void abr_synth_vm_trace_json(
    const abr_synth_vm_trace* t
)
{
    printf("[");
    for (size_t i = 0; i < t->count; i++) {
        abr_synth_vm_trace_event_json(&t->events[i]);
        if (i + 1 < t->count) printf(", ");
    }
    printf("]");
}

#endif /* ABR_SYNTH_VM_TRACE_JSON_H */

