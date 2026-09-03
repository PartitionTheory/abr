/*
 * abr_json_min.h — ABR v0.5
 *
 * Minimal JSON emitter for CLI and SDK.
 * Not a parser. Not a full JSON library.
 * Only prints simple objects and arrays.
 *
 * Phoenix Annotation (scflder):
 *   f = front of JSON emission
 *   s = second / step in field printing
 *   l = last stage before closing brace
 *   c = clock domain (context clock may be printed)
 *   d = degree domain (window width may be printed)
 *   e = eternal set (invariants may be printed)
 *   r = residue domain (last result may be printed)
 */

#ifndef ABR_JSON_MIN_H
#define ABR_JSON_MIN_H

#include <stdio.h>
#include <stdint.h>
#include <stddef.h>

/* Print a JSON string field: "key": "value" */
static inline void abr_json_field_str(const char* key, const char* value)
{
    printf("\"%s\": \"%s\"", key, value);
}

/* Print a JSON numeric field: "key": number */
static inline void abr_json_field_num(const char* key, uint64_t value)
{
    printf("\"%s\": %llu", key, (unsigned long long)value);
}

/* Print a JSON array of numbers: "key": [a,b,c] */
static inline void abr_json_array_num(const char* key, const uint64_t* arr, size_t count)
{
    printf("\"%s\": [", key);
    for (size_t i = 0; i < count; i++) {
        printf("%llu", (unsigned long long)arr[i]);
        if (i + 1 < count) printf(",");
    }
    printf("]");
}

#endif /* ABR_JSON_MIN_H */

