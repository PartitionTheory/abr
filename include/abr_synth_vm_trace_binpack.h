/*
 * abr_synth_vm_trace_binpack.h — ABR v0.5
 *
 * Packed-binary emitter for synthetic VM trace metadata.
 * Minimal in v0.5; expanded in v0.6+.
 *
 * Phoenix Annotation (scflder):
 *   f = front of binpack emission
 *   s = second / step in field packing
 *   l = last stage before closing output
 *   c = clock domain (context clock may be packed)
 *   d = degree domain (window width may be packed)
 *   e = eternal set (invariants may be packed)
 *   r = residue domain (last result may be packed)
 */

#ifndef ABR_SYNTH_VM_TRACE_BINPACK_H
#define ABR_SYNTH_VM_TRACE_BINPACK_H

#include <stdio.h>
#include <stdint.h>
#include <string.h>
#include "abr_synth_vm_trace.h"

/* Emit a single trace event in packed binary (f). */
static inline void abr_synth_vm_trace_event_binpack(
    const abr_synth_vm_trace_event* e,
    FILE* out
)
{
    uint64_t clock   = e->clock;
    uint64_t residue = e->residue;

    /* Plugin name: 16-byte fixed field (zero-padded). */
    char namebuf[16];
    memset(namebuf, 0, sizeof(namebuf));
    strncpy(namebuf, e->plugin_name, sizeof(namebuf) - 1);
    fwrite(namebuf, 1, sizeof(namebuf), out);

    /* Pack clock and residue as 64-bit fields. */
    fwrite(&clock,   sizeof(clock),   1, out);
    fwrite(&residue, sizeof(residue), 1, out);
}

/* Emit entire trace in packed binary (l). */
static inline void abr_synth_vm_trace_binpack(
    const abr_synth_vm_trace* t,
    FILE* out
)
{
    for (size_t i = 0; i < t->count; i++) {
        abr_synth_vm_trace_event_binpack(&t->events[i], out);
    }
}

#endif /* ABR_SYNTH_VM_TRACE_BINPACK_H */

