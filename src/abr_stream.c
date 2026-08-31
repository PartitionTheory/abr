/*
 * ABR-Rebirth: Stream Subsystem Implementation
 *
 * Implements reversible stream buffers and context binding.
 */

#include "abr_stream.h"
#include "abr_core.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* ------------------------------------------------------------------------- */
/* Buffer lifecycle                                                          */
/* ------------------------------------------------------------------------- */

abr_stream_buffer_t *abr_stream_buffer_create(abr_stream_direction_t direction,
                                              size_t initial_capacity)
{
    abr_stream_buffer_t *buf =
        (abr_stream_buffer_t *)malloc(sizeof(abr_stream_buffer_t));
    if (!buf) {
        return NULL;
    }

    buf->data = NULL;
    buf->size = 0;
    buf->capacity = 0;
    buf->direction = direction;

    if (initial_capacity > 0) {
        buf->data = (unsigned char *)malloc(initial_capacity);
        if (!buf->data) {
            free(buf);
            return NULL;
        }
        buf->capacity = initial_capacity;
    }

    return buf;
}

void abr_stream_buffer_destroy(abr_stream_buffer_t *buf)
{
    if (!buf) {
        return;
    }

    free(buf->data);
    free(buf);
}

/* ------------------------------------------------------------------------- */
/* Buffer I/O                                                                */
/* ------------------------------------------------------------------------- */

size_t abr_stream_buffer_write(abr_stream_buffer_t *buf,
                               const void *data,
                               size_t len)
{
    if (!buf || !data || len == 0) {
        return 0;
    }

    /* Grow capacity if needed */
    if (buf->size + len > buf->capacity) {
        size_t new_cap = (buf->capacity == 0) ? len : buf->capacity * 2;
        while (new_cap < buf->size + len) {
            new_cap *= 2;
        }

        unsigned char *new_data =
            (unsigned char *)realloc(buf->data, new_cap);
        if (!new_data) {
            return 0;
        }

        buf->data = new_data;
        buf->capacity = new_cap;
    }

    memcpy(buf->data + buf->size, data, len);
    buf->size += len;

    return len;
}

size_t abr_stream_buffer_read(abr_stream_buffer_t *buf,
                              void *data,
                              size_t len)
{
    if (!buf || !data || len == 0) {
        return 0;
    }

    if (len > buf->size) {
        len = buf->size;
    }

    memcpy(data, buf->data, len);

    /* Simple forward-only read; reversible semantics will be added later. */
    memmove(buf->data, buf->data + len, buf->size - len);
    buf->size -= len;

    return len;
}

/* ------------------------------------------------------------------------- */
/* Context binding                                                           */
/* ------------------------------------------------------------------------- */

int abr_stream_bind_context(abr_context_t *ctx, abr_stream_buffer_t *buf)
{
    (void)ctx;
    (void)buf;

    /* Binding logic will be implemented when context/VM wiring for streams
     * is defined. For now, this is a stub that succeeds. */
    return 0;
}

int abr_stream_split(const char *path, int bitWidth)
{
    fprintf(stderr,
        "abr_stream_split: stub invoked (path=%s, bitWidth=%d)\n",
        path, bitWidth
    );
    return 0;
}

int abr_stream_join(const char *hexPath, int bitWidth, int originalBits)
{
    fprintf(stderr,
        "abr_stream_join: stub invoked (hexPath=%s, bitWidth=%d, originalBits=%d)\n",
        hexPath, bitWidth, originalBits
    );
    return 0;
}
