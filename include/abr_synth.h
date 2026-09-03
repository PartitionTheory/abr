/*
 * abr_synth.h — ABR v0.5
 *
 * Synthetic metadata layer for ABR.
 * Provides simple structured results for plugins, CLI, and SDK.
 *
 * Phoenix Annotation (scflder):
 *   f = front of synthetic entry
 *   s = second / step in metadata assembly
 *   l = last stage before returning result
 *   c = clock domain (context clock may be printed)
 *   d = degree domain (window width may be printed)
 *   e = eternal set (invariants may be printed)
 *   r = residue domain (last result may be printed)
 */

#ifndef ABR_SYNTH_H
#define ABR_SYNTH_H

#include <stddef.h>
#include <stdint.h>

/* Synthetic result object */
typedef struct abr_synth {
    const char* status;     /* "ok", "error", etc. */
    const char* message;    /* human-readable message */
    const char* json;       /* optional JSON payload */
} abr_synth;

/* Initialize synthetic result (f). */
static inline void abr_synth_init(abr_synth* s)
{
    if (!s) return;
    s->status  = "ok";
    s->message = "";
    s->json    = NULL;
}

/* Destroy synthetic result (l). */
static inline void abr_synth_destroy(abr_synth* s)
{
    (void)s;
    /* v0.5: no dynamic fields */
}

#endif /* ABR_SYNTH_H */

