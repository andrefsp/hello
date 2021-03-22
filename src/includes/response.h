#ifndef _HELLO_RESPONSE_H
#define _HELLO_RESPONSE_H

#include "hashmap.h"
#include "http_status_codes.h"


typedef struct Response Response;

struct Response {
    Hashmap *Headers;

    HttpStatusCode *HttpStatusCode;

    char *Body;

    void (*SetStatusCode)(Response *r, HttpStatusCode *status);
    void (*SetHeader)(Response *r, char *name, char *val);
    char * (*GetHeader)(Response *r, char *name);
    void (*WriteBody)(Response *r, char *contents);

    char * (*ToString)(Response *r);
};


void Response_SetStatusCode(Response *r, HttpStatusCode *status);

void Response_WriteBody(Response *r, char *contents);

void Response_SetHeader(Response *r, char *name, char *val);

char *Response_GetHeader(Response *r, char *name);

char *Response_ToString(Response *r);

// Constructor
Response *NewResponse();

#endif
