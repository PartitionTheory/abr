#ifndef ABR_JSON_MIN_H
#define ABR_JSON_MIN_H

#include <stddef.h>

/*
 * Phoenix v0.4-greenbuild:
 * Minimal JSON parser for synthetic operators.
 *
 * Supports:
 *   - flat objects
 *   - string values
 *   - integer values
 */

int abr_json_min_get_int(const char* json, const char* key);
const char* abr_json_min_get_string(const char* json, const char* key);

#endif

