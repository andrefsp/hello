#ifndef _HELLO_REQUEST_H
#define _HELLO_REQUEST_H

#include "hashmap.h"

typedef struct Request Request;

struct Request {
    Hashmap *Headers;

    char *Method;
    char *Url;
    char *Body;
    long Timeout;
    long ConnectTimeout;

    void (*SetHeader)(Request *r, char *name, char *val);
    char * (*GetHeader)(Request *r, char *name);
    void (*SetBody)(Request *r, char *body);
    void (*SetTimeout)(Request *r, long timeout);
    void (*SetConnectTimeout)(Request *r, long timeout);

    int (*Parse)(Request *r, char *buff);
};


void Request_SetBody(Request *r, char *body);

void Request_SetHeader(Request *r, char *name, char *val);

void Request_SetTimeout(Request *r, long timeout);

void Request_SetConnectTimeout(Request *r, long timeout);


// Constructor
Request *NewRequest();

Request *NewRequestFromBuffer(char *buff);


#endif
