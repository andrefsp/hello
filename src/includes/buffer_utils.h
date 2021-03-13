#ifndef _HELLO_BUFFER_UTILS_H
#define _HELLO_BUFFER_UTILS_H

#include "uv.h"


// create a new UV buffer
uv_buf_t *new_uv_buffer(char *text);

// Allocate memory for buffer
void h_buffer_alloc(uv_handle_t *handle, size_t size, uv_buf_t *buf);


#endif
