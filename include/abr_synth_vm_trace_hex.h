/*
 * abr_synth_vm_trace_hex.h — ABR v0.5
 *
 * Hexadecimal emitter for synthetic VM trace metadata.
 * Minimal in v0.5; expanded in v0.6+.
 *
 * Phoenix Annotation (scflder):
 *   f = front of hex emission
 *   s = second / step in field printing
 *   l = last stage before closing output
 *   c = clock domain (context clock may be printed)
 *   d = degree domain (window width may be printed)
 *   e = eternal set (invariants may be printed)
 *   r = residue domain (last result may be printed)
 */

#ifndef ABR_SYNTH_VM_TRACE_HEX_H
#define ABR_SYNTH_VM_TRACE_HEX_H

#include <stdio.h>
#include <stdint.h>
#include <string.h>
#include "abr_synth_vm_trace.h"

/* Emit a single trace event in hex (f). */
static inline void abr_synth_vm_trace_event_hex(
    const abr_synth_vm_trace_event* e
)
{
    printf("plugin=");
    for (const char* p = e->plugin_name; *p; p++) {
        printf("%02X", (unsigned char)*p);
    }

    printf(" clock=%016llX residue=%016llX\n",
        (unsigned long long)e->clock,
        (unsigned long long)e->residue
    );
}

/* Emit entire trace in hex (l). */
static inline void abr_synth_vm_trace_hex(
    const abr_synth_vm_trace* t
)
{
    for (size_t i = 0; i < t->count; i++) {
        abr_synth_vm_trace_event_hex(&t->events[i]);
    }
}

#endif /* ABR_SYNTH_VM_TRACE_HEX_H */

