#ifndef _HELLO_HTTP_CLIENT_H
#define _HELLO_HTTP_CLIENT_H

#include "curl/curl.h"

#include "request.h"
#include "response.h"

typedef struct HttpClient HttpClient;

struct HttpClient {
    CURL *curl;
    struct curl_slist *chunk;

    Response *(*Do)(HttpClient *c, Request *req);
};

Response *HttpClient_Do(HttpClient *c, Request *req);

HttpClient *NewHttpClient();

#endif
