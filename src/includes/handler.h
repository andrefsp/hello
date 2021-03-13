#ifndef _HELLO_HANDLER_H
#define _HELLO_HANDLER_H

#include "response.h"
#include "request.h"


typedef struct Handler Handler;


struct Handler {
    char *method;

    Response * (*Get)(Handler *h, Request *req);
    Response * (*Post)(Handler *h, Request *req);
    Response * (*Put)(Handler *h, Request *req);
    Response * (*Patch)(Handler *h, Request *req);
    Response * (*Delete)(Handler *h, Request *req);
};

#endif
