/*
 * abr_flags.h — ABR v0.5
 *
 * Defines the unified ABR flags object used across core, sdk,
 * plugins, pipeline, system, and VM.
 *
 * Phoenix Annotation (scflder):
 *   f = front of flag creation
 *   s = second / step in flag mutation
 *   l = last stage during destruction
 *   c = clock domain (flags may influence clock behavior)
 *   d = degree domain (flags may influence unary degree)
 *   e = eternal set (flags may preserve invariants)
 *   r = residue domain (flags may store last result)
 */

#ifndef ABR_FLAGS_H
#define ABR_FLAGS_H

#include <stddef.h>
#include <stdint.h>

/* Unified ABR flags */
typedef struct abr_flags {
    uint32_t mode;      /* execution mode */
    uint32_t options;   /* bitmask of options */
    uint32_t reserved;  /* reserved for future v0.6 expansion */
} abr_flags_t;

/* Initialize flags (f). */
static inline void abr_flags_init(abr_flags_t* fl)
{
    if (!fl) return;
    fl->mode     = 0;
    fl->options  = 0;
    fl->reserved = 0;
}

/* Destroy flags (l). */
static inline void abr_flags_destroy(abr_flags_t* fl)
{
    (void)fl;
    /* v0.5: no dynamic fields */
}

#endif /* ABR_FLAGS_H */

