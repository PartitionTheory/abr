/*
 * abr_cli_commands.h — ABR v0.5
 *
 * Defines the CLI command table for ABR.
 * This is the ABI boundary between command-line parsing and
 * the high-level ABR interface layer.
 *
 * Phoenix Annotation (scflder):
 *   f = front of command entry
 *   s = second / step in command selection
 *   l = last stage before execution
 *   c = clock domain (context clock may advance)
 *   d = degree domain (window width may change)
 *   e = eternal set (invariants preserved)
 *   r = residue domain (last result stored)
 */

#ifndef ABR_CLI_COMMANDS_H
#define ABR_CLI_COMMANDS_H

#include "abr_interface.h"
#include "abr_plugin.h"
#include "windowset.h"
#include "abr_context.h"
#include "abr_flags.h"

/* CLI command entry */
typedef struct abr_cli_command {
    const char* name;
    const char* description;

    int (*run)(
        const abr_plugin* p,
        const WindowSet* in,
        const abr_flags_t* fl,
        abr_context_t* ctx
    );
} abr_cli_command;

/* Run a non-branching plugin (f). */
static inline int abr_cli_cmd_run_set(
    const abr_plugin* p,
    const WindowSet* in,
    const abr_flags_t* fl,
    abr_context_t* ctx
)
{
    WindowSet out = abr_interface_run_set(p, in, fl, ctx);
    (void)out; /* v0.5: CLI prints elsewhere */
    return 0;
}

/* Run a branching plugin (l). */
static inline int abr_cli_cmd_run_branch(
    const abr_plugin* p,
    const WindowSet* in,
    const abr_flags_t* fl,
    abr_context_t* ctx
)
{
    size_t count = 0;
    WindowSet* out = abr_interface_run_branch(p, in, fl, ctx, &count);
    (void)out; /* v0.5: CLI prints elsewhere */
    return 0;
}

#endif /* ABR_CLI_COMMANDS_H */

