#include "gc.h"
#include <string.h>

#ifndef _HELLO_BUFFER_UTILS_C
#define _HELLO_BUFFER_UTILS_C


// create a new UV buffer
uv_buf_t *new_uv_buffer(char *text) {
    uv_buf_t *buff = GC_MALLOC(0);
    buff->len = strlen(text);
    buff->base = GC_MALLOC(strlen(text)*sizeof(char));
    strcpy(buff->base, text);
    return buff;
}

void h_buffer_alloc(uv_handle_t *handle, size_t size, uv_buf_t *buf) {
    buf->base = GC_MALLOC(size);
    buf->len = size;
}

#endif
