/*
 * abr_cli.h — ABR v0.5
 *
 * CLI interface for ABR.
 * Defines the ABI boundary between command-line parsing and the
 * high-level ABR interface layer.
 *
 * Phoenix Annotation (scflder):
 *   f = front of CLI entry
 *   s = second / step in argument parsing
 *   l = last stage before execution
 *   c = clock domain (context clock may advance)
 *   d = degree domain (window width may change)
 *   e = eternal set (invariants preserved)
 *   r = residue domain (last result stored)
 */

#ifndef ABR_CLI_H
#define ABR_CLI_H

#include "abr_interface.h"
#include "abr_plugin.h"
#include "windowset.h"
#include "abr_context.h"
#include "abr_flags.h"

/* Parsed CLI arguments */
typedef struct abr_cli_args {
    const char* file_path;
    const char* plugin_name;
    const char* widths;
} abr_cli_args;

/* Parse CLI arguments (f). */
abr_cli_args abr_cli_parse(int argc, char** argv);

/* Execute ABR from CLI (l). */
int abr_cli_run(const abr_cli_args* args);

#endif /* ABR_CLI_H */

