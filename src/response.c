#include "gc.h"
#include <strings.h>


#ifndef _HELLO_RESPONSE_C
#define _HELLO_RESPONSE_C

#include "response.h"

// Implementations
#include "hashmap.c"
#include "string_utils.c"


void Response_SetStatusCode(Response *r, HttpStatusCode *statusCode) {
    r->HttpStatusCode = statusCode; 
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

char *Response_ToString(Response *r) {
    char *statusLine = GC_MALLOC(100);
    sprintf(statusLine, "HTTP/1.1 %d %s\r\n", r->HttpStatusCode->Code, r->HttpStatusCode->Status);

    char *respString = str_concat("", statusLine); 
    for (int x = 0; x < r->Headers->Size; x++) {
        respString = str_concat(respString, (char *)r->Headers->Items[x]->key);
        respString = str_concat(respString, ": ");
        respString = str_concat(respString, (char *)r->Headers->Items[x]->data);
        respString = str_concat(respString, "\r\n");
    } 

    // Header termination
    respString = str_concat(respString, "\r\n");  
    respString = str_concat(respString, r->Body);
    return respString;
}

Response *NewResponse() {
    Response *res = GC_MALLOC(sizeof(Response));
    
    res->Headers = NewHashmap();
    
    res->SetStatusCode = Response_SetStatusCode;

    res->SetHeader = Response_SetHeader;
    res->GetHeader = Response_GetHeader;
    res->WriteBody = Response_WriteBody;

    res->ToString = Response_ToString;
    res->Body = GC_MALLOC(sizeof(char));
    return res;
}

#endif
