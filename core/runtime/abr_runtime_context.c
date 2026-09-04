/*
 * abr_runtime_context.c — ABR v0.5
 *
 * Implements the runtime context initialization and reset logic.
 * The context carries window, residue, plugin name, status, and flags.
 */

#include "abr_runtime_context.h"
#include <stdlib.h>
#include <string.h>

void abr_runtime_context_init(struct abr_context* ctx)
{
    ctx->window        = 0;
    ctx->residue       = 0;
    ctx->plugin_name   = NULL;
    ctx->status_code   = 0;
    ctx->error_message = NULL;
    ctx->flags         = 0;
}

void abr_runtime_context_set(struct abr_context* ctx,
                             uint64_t window,
                             uint64_t residue,
                             const char* plugin_name)
{
    ctx->window      = window;
    ctx->residue     = residue;
    ctx->plugin_name = plugin_name;
}

void abr_runtime_context_error(struct abr_context* ctx,
                               int status,
                               const char* message)
{
    ctx->status_code   = status;
    ctx->error_message = message;
}

void abr_runtime_context_reset(struct abr_context* ctx)
{
    ctx->window        = 0;
    ctx->residue       = 0;
    ctx->plugin_name   = NULL;
    ctx->status_code   = 0;
    ctx->error_message = NULL;
    ctx->flags         = 0;
}

