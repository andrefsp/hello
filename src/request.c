#include "gc.h"
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>

#ifndef _HELLO_REQUEST_C
#define _HELLO_REQUEST_C

#include "request.h"

#include "picohttpparser/picohttpparser.h"
#include "picohttpparser/picohttpparser.c"


void Request_SetTimeout(Request *r, long timeout) {
    r->Timeout = timeout;
}

void Request_SetConnectTimeout(Request *r, long timeout) {
    r->ConnectTimeout = timeout;
}

void Request_SetBody(Request *r, char *body) {
    r->Body = GC_MALLOC((strlen(body)+1)*sizeof(char));
    strcpy(r->Body, body);
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
    r->Method = GC_MALLOC(strlen(method)*sizeof(char));
    strcpy(r->Method, method);

    // Url
    r->Url = GC_MALLOC(strlen(url)*sizeof(char));
    strcpy(r->Url, url);

    r->SetTimeout = Request_SetTimeout;
    r->SetConnectTimeout = Request_SetConnectTimeout;
    r->SetBody = Request_SetBody;
    r->SetHeader = Request_SetHeader;
    r->GetHeader = Request_GetHeader;

    return r;
}


Request *NewRequestFromBuffer(char *buff) {
    int minor_version;

    const char *method = GC_MALLOC(0);
    size_t method_len;
    const char *path = GC_MALLOC(0);
    size_t path_len;

    size_t num_headers = 32;
    struct phr_header headers[num_headers];

    char *reqbuff = GC_MALLOC(strlen(buff)*sizeof(char));
    strcpy(reqbuff, buff);

    phr_parse_request(
        reqbuff, strlen(reqbuff),
        &method, &method_len,
        &path, &path_len,
        &minor_version,
        headers, &num_headers, 0);

    char *reqmethod = GC_MALLOC(method_len*sizeof(char));
    strncpy(reqmethod, method, method_len);
     
    char *reqpath = GC_MALLOC(path_len*sizeof(char));
    strncpy(reqpath, path, path_len);
 
    Request *req = NewRequest(reqmethod, reqpath);

    for (int i = 0; i < num_headers; ++i) {
        char *headname = GC_MALLOC(headers[i].name_len*sizeof(char));
        char *headval = GC_MALLOC(headers[i].value_len*sizeof(char));
        
        strncpy(headname, headers[i].name, headers[i].name_len);
        headname[headers[i].name_len] = '\0';

        strncpy(headval, headers[i].value, headers[i].value_len);
        headval[headers[i].value_len] = '\0';

        req->SetHeader(req, headname, headval);
    }

    return req;
}

#endif
