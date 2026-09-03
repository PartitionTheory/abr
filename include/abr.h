/*
 * abr.h — ABR v0.5
 *
 * Top-level ABR include.
 * Aggregates all public ABR headers into a single entry point.
 *
 * Phoenix Annotation (scflder):
 *   f = front of ABR entry
 *   s = second / step in subsystem selection
 *   l = last stage before execution
 *   c = clock domain (context clock may advance)
 *   d = degree domain (window width may change)
 *   e = eternal set (invariants preserved)
 *   r = residue domain (last result stored)
 */

#ifndef ABR_H
#define ABR_H

/* Core ABI */
#include "abr_core.h"

/* Execution ABI */
#include "abr_exec.h"

/* Dispatch ABI */
#include "abr_dispatch.h"

/* Interface ABI */
#include "abr_interface.h"

/* CLI ABI */
#include "abr_cli.h"
#include "abr_cli_commands.h"

/* Plugin ABI */
#include "abr_plugin.h"

/* Flags, Context, WindowSet */
#include "abr_flags.h"
#include "abr_context.h"
#include "windowset.h"

/* Synthetic metadata */
#include "abr_synth.h"

/* Minimal JSON emitter */
#include "abr_json_min.h"

#endif /* ABR_H */

