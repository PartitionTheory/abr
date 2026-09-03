/*
 * abr_stream.h — ABR v0.5
 *
 * Stream subsystem interface.
 */

#ifndef ABR_STREAM_H
#define ABR_STREAM_H

#include <stdint.h>
#include <stddef.h>
#include "abr_plugin_result.h"

typedef struct abr_stream
{
    uint64_t current;
    size_t   count;

} abr_stream;

void     abr_stream_init(abr_stream* s, uint64_t initial);
void     abr_stream_push(abr_stream* s, uint64_t value);
void     abr_stream_apply_result(abr_stream* s, abr_plugin_result result);
uint64_t abr_stream_current(const abr_stream* s);
size_t   abr_stream_length(const abr_stream* s);

#endif /* ABR_STREAM_H */

