/*
 * abr_synth_vm_trace_yaml.h — ABR v0.5
 *
 * YAML emitter for synthetic VM trace metadata.
 * Minimal in v0.5; expanded in v0.6+.
 *
 * Phoenix Annotation (scflder):
 *   f = front of YAML emission
 *   s = second / step in field printing
 *   l = last stage before closing output
 *   c = clock domain (context clock may be printed)
 *   d = degree domain (window width may be printed)
 *   e = eternal set (invariants may be printed)
 *   r = residue domain (last result may be printed)
 */

#ifndef ABR_SYNTH_VM_TRACE_YAML_H
#define ABR_SYNTH_VM_TRACE_YAML_H

#include <stdio.h>
#include "abr_synth_vm_trace.h"

/* Emit YAML header (f). */
static inline void abr_synth_vm_trace_yaml_header(void)
{
    printf("trace:\n");
}

/* Emit a single trace event as YAML (s). */
static inline void abr_synth_vm_trace_event_yaml(
    const abr_synth_vm_trace_event* e
)
{
    printf("  - plugin: %s\n", e->plugin_name);
    printf("    clock: %llu\n", (unsigned long long)e->clock);
    printf("    residue: %llu\n", (unsigned long long)e->residue);
}

/* Emit entire trace as YAML (l). */
static inline void abr_synth_vm_trace_yaml(
    const abr_synth_vm_trace* t
)
{
    abr_synth_vm_trace_yaml_header();
    for (size_t i = 0; i < t->count; i++) {
        abr_synth_vm_trace_event_yaml(&t->events[i]);
    }
}

#endif /* ABR_SYNTH_VM_TRACE_YAML_H */

