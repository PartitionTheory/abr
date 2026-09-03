/*
 * abr_flags.h — ABR v0.5
 *
 * Flags for ABR execution.
 * Minimal in v0.5; expanded in v0.6+.
 *
 * Phoenix Annotation (scflder):
 *   f = front of flag entry
 *   s = second / step in flag selection
 *   l = last stage before execution
 *   c = clock domain (context clock may advance)
 *   d = degree domain (window width may change)
 *   e = eternal set (invariants preserved)
 *   r = residue domain (last result stored)
 */

#ifndef ABR_FLAGS_H
#define ABR_FLAGS_H

#include <stddef.h>
#include <stdint.h>

/* Minimal flag object for v0.5. */
typedef struct abr_flags_t {
    uint32_t mode;     /* plugin-specific mode */
    uint32_t options;  /* plugin-specific options */
} abr_flags_t;

/* Initialize flags (f). */
static inline void abr_flags_init(abr_flags_t* fl)
{
    if (!fl) return;
    fl->mode    = 0;
    fl->options = 0;
}

#endif /* ABR_FLAGS_H */

