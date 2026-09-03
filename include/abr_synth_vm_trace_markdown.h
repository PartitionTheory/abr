/*
 * abr_synth_vm_trace_markdown.h — ABR v0.5
 *
 * Markdown emitter for synthetic VM trace metadata.
 * Minimal in v0.5; expanded in v0.6+.
 *
 * Phoenix Annotation (scflder):
 *   f = front of Markdown emission
 *   s = second / step in field printing
 *   l = last stage before closing output
 *   c = clock domain (context clock may be printed)
 *   d = degree domain (window width may be printed)
 *   e = eternal set (invariants may be printed)
 *   r = residue domain (last result may be printed)
 */

#ifndef ABR_SYNTH_VM_TRACE_MARKDOWN_H
#define ABR_SYNTH_VM_TRACE_MARKDOWN_H

#include <stdio.h>
#include "abr_synth_vm_trace.h"

/* Emit Markdown header (f). */
static inline void abr_synth_vm_trace_markdown_header(void)
{
    printf("| Plugin | Clock | Residue |\n");
    printf("|--------|-------|---------|\n");
}

/* Emit a single trace event as Markdown row (s). */
static inline void abr_synth_vm_trace_event_markdown(
    const abr_synth_vm_trace_event* e
)
{
    printf("| %s | %llu | %llu |\n",
        e->plugin_name,
        (unsigned long long)e->clock,
        (unsigned long long)e->residue
    );
}

/* Emit entire trace as Markdown table (l). */
static inline void abr_synth_vm_trace_markdown(
    const abr_synth_vm_trace* t
)
{
    abr_synth_vm_trace_markdown_header();
    for (size_t i = 0; i < t->count; i++) {
        abr_synth_vm_trace_event_markdown(&t->events[i]);
    }
}

#endif /* ABR_SYNTH_VM_TRACE_MARKDOWN_H */

