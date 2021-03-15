#ifndef _HELLO_RESPONSE_H
#define _HELLO_RESPONSE_H

#include "hashmap.h"

typedef struct Response Response;

struct Response {
    Hashmap *Headers;

    int StatusCode;
    char *Status;

    char *Body;

    void (*SetStatus)(Response *r, char *rstatus);
    void (*SetStatusCode)(Response *r, int statusCode);
    void (*SetHeader)(Response *r, char *name, char *val);
    char * (*GetHeader)(Response *r, char *name);
    void (*WriteBody)(Response *r, char *contents);

    char * (*ToString)(Response *r);
};

void Response_SetStatus(Response *r, char *rstatus);

void Response_SetStatusCode(Response *r, int statusCode);

void Response_WriteBody(Response *r, char *contents);

void Response_SetHeader(Response *r, char *name, char *val);

char *Response_GetHeader(Response *r, char *name);

char *Response_ToString(Response *r);

// Constructor
Response *NewResponse();

#endif
