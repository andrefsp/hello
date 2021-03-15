#include "gc.h"

#ifndef _HELLO_HANDLER_C
#define _HELLO_HANDLER_C

#include "handler.h"

Handler *NewHandler() {
    Handler *hnd = GC_MALLOC(sizeof(Handler));
    return hnd;
}

#endif
