/*
 * abr_synth_vm_trace_bin.h — ABR v0.5
 *
 * Binary emitter for synthetic VM trace metadata.
 * Minimal in v0.5; expanded in v0.6+.
 *
 * Phoenix Annotation (scflder):
 *   f = front of binary emission
 *   s = second / step in field packing
 *   l = last stage before closing output
 *   c = clock domain (context clock may be packed)
 *   d = degree domain (window width may be packed)
 *   e = eternal set (invariants may be packed)
 *   r = residue domain (last result may be packed)
 */

#ifndef ABR_SYNTH_VM_TRACE_BIN_H
#define ABR_SYNTH_VM_TRACE_BIN_H

#include <stdio.h>
#include <stdint.h>
#include <string.h>
#include "abr_synth_vm_trace.h"

/* Emit a single trace event in binary (f). */
static inline void abr_synth_vm_trace_event_bin(
    const abr_synth_vm_trace_event* e,
    FILE* out
)
{
    uint64_t clock   = e->clock;
    uint64_t residue = e->residue;

    /* Write plugin name as fixed 32-byte field (zero-padded). */
    char namebuf[32];
    memset(namebuf, 0, sizeof(namebuf));
    strncpy(namebuf, e->plugin_name, sizeof(namebuf) - 1);
    fwrite(namebuf, 1, sizeof(namebuf), out);

    /* Write clock and residue as 64-bit fields. */
    fwrite(&clock,   sizeof(clock),   1, out);
    fwrite(&residue, sizeof(residue), 1, out);
}

/* Emit entire trace in binary (l). */
static inline void abr_synth_vm_trace_bin(
    const abr_synth_vm_trace* t,
    FILE* out
)
{
    for (size_t i = 0; i < t->count; i++) {
        abr_synth_vm_trace_event_bin(&t->events[i], out);
    }
}

#endif /* ABR_SYNTH_VM_TRACE_BIN_H */

