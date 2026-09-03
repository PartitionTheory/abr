/*
 * abr_synth_vm_trace_html.h — ABR v0.5
 *
 * HTML emitter for synthetic VM trace metadata.
 * Minimal in v0.5; expanded in v0.6+.
 *
 * Phoenix Annotation (scflder):
 *   f = front of HTML emission
 *   s = second / step in field printing
 *   l = last stage before closing output
 *   c = clock domain (context clock may be printed)
 *   d = degree domain (window width may be printed)
 *   e = eternal set (invariants may be printed)
 *   r = residue domain (last result may be printed)
 */

#ifndef ABR_SYNTH_VM_TRACE_HTML_H
#define ABR_SYNTH_VM_TRACE_HTML_H

#include <stdio.h>
#include "abr_synth_vm_trace.h"

/* Emit HTML header (f). */
static inline void abr_synth_vm_trace_html_header(void)
{
    printf("<table>\n");
    printf("<tr><th>Plugin</th><th>Clock</th><th>Residue</th></tr>\n");
}

/* Emit a single trace event as HTML row (s). */
static inline void abr_synth_vm_trace_event_html(
    const abr_synth_vm_trace_event* e
)
{
    printf("<tr>");
    printf("<td>%s</td>", e->plugin_name);
    printf("<td>%llu</td>", (unsigned long long)e->clock);
    printf("<td>%llu</td>", (unsigned long long)e->residue);
    printf("</tr>\n");
}

/* Emit entire trace as HTML table (l). */
static inline void abr_synth_vm_trace_html(
    const abr_synth_vm_trace* t
)
{
    abr_synth_vm_trace_html_header();
    for (size_t i = 0; i < t->count; i++) {
        abr_synth_vm_trace_event_html(&t->events[i]);
    }
    printf("</table>\n");
}

#endif /* ABR_SYNTH_VM_TRACE_HTML_H */

