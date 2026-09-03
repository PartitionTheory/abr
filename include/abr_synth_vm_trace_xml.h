/*
 * abr_synth_vm_trace_xml.h — ABR v0.5
 *
 * XML emitter for synthetic VM trace metadata.
 * Minimal in v0.5; expanded in v0.6+.
 *
 * Phoenix Annotation (scflder):
 *   f = front of XML emission
 *   s = second / step in field printing
 *   l = last stage before closing output
 *   c = clock domain (context clock may be printed)
 *   d = degree domain (window width may be printed)
 *   e = eternal set (invariants may be printed)
 *   r = residue domain (last result may be printed)
 */

#ifndef ABR_SYNTH_VM_TRACE_XML_H
#define ABR_SYNTH_VM_TRACE_XML_H

#include <stdio.h>
#include "abr_synth_vm_trace.h"

/* Emit XML header (f). */
static inline void abr_synth_vm_trace_xml_header(void)
{
    printf("<trace>\n");
}

/* Emit a single trace event as XML (s). */
static inline void abr_synth_vm_trace_event_xml(
    const abr_synth_vm_trace_event* e
)
{
    printf("  <event>\n");
    printf("    <plugin>%s</plugin>\n", e->plugin_name);
    printf("    <clock>%llu</clock>\n", (unsigned long long)e->clock);
    printf("    <residue>%llu</residue>\n", (unsigned long long)e->residue);
    printf("  </event>\n");
}

/* Emit entire trace as XML (l). */
static inline void abr_synth_vm_trace_xml(
    const abr_synth_vm_trace* t
)
{
    abr_synth_vm_trace_xml_header();
    for (size_t i = 0; i < t->count; i++) {
        abr_synth_vm_trace_event_xml(&t->events[i]);
    }
    printf("</trace>\n");
}

#endif /* ABR_SYNTH_VM_TRACE_XML_H */

