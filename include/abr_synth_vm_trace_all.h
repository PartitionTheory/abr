/*
 * abr_synth_vm_trace_all.h — ABR v0.5
 *
 * Unified multi-format emitter for synthetic VM trace metadata.
 * Minimal in v0.5; expanded in v0.6+.
 *
 * Phoenix Annotation (scflder):
 *   f = front of unified emission
 *   s = second / step in dispatch
 *   l = last stage before returning
 *   c = clock domain (context clock may be printed)
 *   d = degree domain (window width may be printed)
 *   e = eternal set (invariants may be printed)
 *   r = residue domain (last result may be printed)
 */

#ifndef ABR_SYNTH_VM_TRACE_ALL_H
#define ABR_SYNTH_VM_TRACE_ALL_H

#include "abr_synth_vm_trace.h"
#include "abr_synth_vm_trace_json.h"
#include "abr_synth_vm_trace_pretty.h"
#include "abr_synth_vm_trace_pretty_json.h"
#include "abr_synth_vm_trace_csv.h"
#include "abr_synth_vm_trace_html.h"
#include "abr_synth_vm_trace_markdown.h"
#include "abr_synth_vm_trace_xml.h"
#include "abr_synth_vm_trace_yaml.h"
#include "abr_synth_vm_trace_hex.h"
#include "abr_synth_vm_trace_bin.h"
#include "abr_synth_vm_trace_binpack.h"
#include "abr_synth_vm_trace_text.h"
#include "abr_synth_vm_trace_dump.h"

/* Unified output format enum (f). */
typedef enum abr_synth_vm_trace_format {
    ABR_TRACE_JSON,
    ABR_TRACE_PRETTY,
    ABR_TRACE_PRETTY_JSON,
    ABR_TRACE_CSV,
    ABR_TRACE_HTML,
    ABR_TRACE_MARKDOWN,
    ABR_TRACE_XML,
    ABR_TRACE_YAML,
    ABR_TRACE_HEX,
    ABR_TRACE_BIN,
    ABR_TRACE_BINPACK,
    ABR_TRACE_TEXT,
    ABR_TRACE_DUMP
} abr_synth_vm_trace_format;

/* Unified dispatcher (l). */
static inline void abr_synth_vm_trace_emit(
    const abr_synth_vm_trace* t,
    abr_synth_vm_trace_format fmt,
    FILE* out /* only used for binary formats */
)
{
    switch (fmt) {
        case ABR_TRACE_JSON:        abr_synth_vm_trace_json(t); break;
        case ABR_TRACE_PRETTY:      abr_synth_vm_trace_pretty(t); break;
        case ABR_TRACE_PRETTY_JSON: abr_synth_vm_trace_pretty_json(t); break;
        case ABR_TRACE_CSV:         abr_synth_vm_trace_csv(t); break;
        case ABR_TRACE_HTML:        abr_synth_vm_trace_html(t); break;
        case ABR_TRACE_MARKDOWN:    abr_synth_vm_trace_markdown(t); break;
        case ABR_TRACE_XML:         abr_synth_vm_trace_xml(t); break;
        case ABR_TRACE_YAML:        abr_synth_vm_trace_yaml(t); break;
        case ABR_TRACE_HEX:         abr_synth_vm_trace_hex(t); break;
        case ABR_TRACE_BIN:         abr_synth_vm_trace_bin(t, out); break;
        case ABR_TRACE_BINPACK:     abr_synth_vm_trace_binpack(t, out); break;
        case ABR_TRACE_TEXT:        abr_synth_vm_trace_text(t); break;
        case ABR_TRACE_DUMP:        abr_synth_vm_trace_dump(t); break;
    }
}

#endif /* ABR_SYNTH_VM_TRACE_ALL_H */

