#include "abr_json_min.h"
#include <string.h>
#include <stdlib.h>

/*
 * Find the value for a given key.
 * Returns pointer to the first character after the colon.
 */
static const char* find_key(const char* json, const char* key)
{
    char pattern[64];
    snprintf(pattern, sizeof(pattern), "\"%s\"", key);

    const char* p = strstr(json, pattern);
    if (!p) return NULL;

    p = strchr(p, ':');
    if (!p) return NULL;

    return p + 1;
}

int abr_json_min_get_int(const char* json, const char* key)
{
    const char* p = find_key(json, key);
    if (!p) return 0;

    while (*p == ' ' || *p == '\t') p++;

    return atoi(p);
}

const char* abr_json_min_get_string(const char* json, const char* key)
{
    const char* p = find_key(json, key);
    if (!p) return NULL;

    while (*p == ' ' || *p == '"' ) p++;

    const char* start = p;

    while (*p && *p != '"') p++;

    size_t len = p - start;
    char* out = (char*)malloc(len + 1);
    memcpy(out, start, len);
    out[len] = '\0';

    return out;
}

