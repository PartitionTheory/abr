#ifndef ABR_STREAM_H
#define ABR_STREAM_H

/*
 * ABR-Rebirth: Stream Subsystem
 * Internal header — not for external API use.
 *
 * The stream layer provides reversible structural I/O:
 *   - input streams feeding domains/windows
 *   - output streams emitting synthetic mathematics results
 *   - buffers for operator and plugin communication
 */

#include <stddef.h>

#ifdef __cplusplus
extern "C" {
#endif

/* Forward declarations */
typedef struct abr_context abr_context_t;

/*
 * Stream direction.
 */
typedef enum abr_stream_direction {
    ABR_STREAM_INPUT,
    ABR_STREAM_OUTPUT
} abr_stream_direction_t;
/*
 *
 */
typedef struct abr_stream_buffer abr_stream_buffer_t;

/*
 * Buffer structure
 */
typedef struct abr_stream {
    abr_stream_buffer_t *buffer;
} abr_stream_t;

/*
 * Stream buffer.
 * Represents a reversible buffer used by operators and plugins.
 */
typedef struct abr_stream_buffer {
    unsigned char *data;
    size_t size;
    size_t capacity;
    abr_stream_direction_t direction;
} abr_stream_buffer_t;

/*
 * Create a new stream buffer.
 * Returns pointer to buffer or NULL on failure.
 */
abr_stream_buffer_t *abr_stream_buffer_create(abr_stream_direction_t direction, size_t initial_capacity);

/*
 * Destroy a stream buffer and release its memory.
 */
void abr_stream_buffer_destroy(abr_stream_buffer_t *buf);

/*
 * Write data into a stream buffer.
 * Returns number of bytes written.
 */
size_t abr_stream_buffer_write(abr_stream_buffer_t *buf, const void *data, size_t len);

/*
 * Read data from a stream buffer.
 * Returns number of bytes read.
 */
size_t abr_stream_buffer_read(abr_stream_buffer_t *buf, void *data, size_t len);

/*
 * Bind a stream buffer to a computation context.
 * This allows operators to use the buffer during execution.
 */
int abr_stream_bind_context(abr_context_t *ctx, abr_stream_buffer_t *buf);

/*
 * Phase‑3 split/join API (stubbed in ABR‑Rebirth)
 */
int abr_stream_split(const char *path, int bitWidth);
int abr_stream_join(const char *hexPath, int bitWidth, int originalBits);

#ifdef __cplusplus
}
#endif

#endif /* ABR_STREAM_H */
