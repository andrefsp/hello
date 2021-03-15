#include "gc.h"


#ifndef _HELLO_RESPONSE_C
#define _HELLO_RESPONSE_C

#include "strings.h"
#include "response.h"

// Implementations
#include "hashmap.c"


void Response_SetStatusCode(Response *r, int statusCode) {
    r->StatusCode = statusCode; 
}

void Response_SetStatus(Response *r, char *status) {
    r->Status = GC_MALLOC(strlen(status)*sizeof(char));
    strcpy(r->Status, status);
}

void Response_WriteBody(Response *r, char *contents) {
    char *newBody = GC_MALLOC((strlen(contents)+strlen(r->Body))*sizeof(char));
    strcat(newBody, r->Body);
    strcat(newBody, contents);
     
    r->Body = newBody;
}

void Response_SetHeader(Response *r, char *name, char *val) {
    char *hname = GC_MALLOC((strlen(name))*sizeof(char));
    char *hval = GC_MALLOC((strlen(val))*sizeof(char));

    strcpy(hname, name);
    strcpy(hval, val);
    

    r->Headers->Set(r->Headers, hname, hval);
}

char *Response_GetHeader(Response *r, char *name) {
    return r->Headers->Get(r->Headers, name);
}


Response *NewResponse() {
    Response *res = GC_MALLOC(sizeof(Response));
    
    res->Headers = NewHashmap();
    
    res->StatusCode = 0;
    res->SetStatus = Response_SetStatus;
    res->SetStatusCode = Response_SetStatusCode;

    res->SetHeader = Response_SetHeader;
    res->GetHeader = Response_GetHeader;
    res->WriteBody = Response_WriteBody;

    res->Body = GC_MALLOC(sizeof(char));
    return res;
}

#endif
