#ifndef _HELLO_REQUEST_C
#define _HELLO_REQUEST_C

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>

#include "gc.h"
#include "request.h"


void Request_SetTimeout(Request *r, long timeout) {
    r->Timeout = timeout;
}

void Request_SetConnectTimeout(Request *r, long timeout) {
    r->ConnectTimeout = timeout;
}

void Request_SetBody(Request *r, char *body) {
    r->body = GC_MALLOC(strlen(body)*sizeof(char));
    strcpy(r->body, body);
}

void Request_SetHeader(Request *r, char *name, char *val) {
    char *hname = GC_MALLOC((strlen(name)+1)*sizeof(char));
    char *hval = GC_MALLOC((strlen(val)+1)*sizeof(char));

    strcpy(hname, name);
    strcpy(hval, val);

    r->Headers->Set(r->Headers, hname, hval);
}

char *Request_GetHeader(Request *r, char *name) {
    return r->Headers->Get(r->Headers, name);
}


Request *NewRequest(char *method, char *url) {
    Request *r = GC_MALLOC(sizeof(Request));
    
    r->Headers = NewHashmap();

    // Method
    r->method = method;

    // Url
    r->url = url;

    r->SetTimeout = Request_SetTimeout;
    r->SetConnectTimeout = Request_SetConnectTimeout;
    r->SetBody = Request_SetBody;
    r->SetHeader = Request_SetHeader;
    r->GetHeader = Request_GetHeader;


    return r;
}


#endif
