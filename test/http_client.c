#include <assert.h>
#include <string.h>

#include "../src/hello.c"

void test_http_client_new_request(void) {
    char *url = "http://localhost:7777";
    Request *req = NewRequest("GET", url);
 
    assert(((void)"url", strcmp(req->Url, url) == 0));
    assert(((void)"method", strcmp(req->Method, "GET") == 0));

    req->SetTimeout(req, 2);
    req->SetHeader(req, "Authorization", "Bearer sometoken");
    req->SetHeader(req, "Content-Type", "application/json");
    req->SetBody(req, "{\"a\": 1}");

    HttpClient *client = NewHttpClient();

    Response *res = client->Do(client, req);
    
    assert(((void)"body size", strlen(res->Body) > 0));
}


void test_http_client_response_status_header_handler(void) {
    char *statusHeader = "HTTP/1.1 200 OK\r\n";
    char *lastHeader = "\r\n";

    Response *res = NewResponse();

    _responseHeaderHandler(statusHeader, 1, strlen(statusHeader), res);
    _responseHeaderHandler(lastHeader, 1, strlen(lastHeader), res);

    assert(((void)"status code", res->StatusCode == 200));
    assert(((void)"status", strcmp(res->Status, "OK") == 0));    
}


void test_http_client_response_header_handler(void) {
    char *statusHeader = "HTTP/1.1 200 OK\r\n";
    char *ctypeHeader = "Content-Type: text/html\r\n";
    char *etagHeader = "ETag: W/\"10-/VnJyQBB0+b7i4NY83P42KKVWsM\"\r\n";
    char *lastHeader = "\r\n";
    Response *res = NewResponse();

    _responseHeaderHandler(statusHeader, 1, strlen(statusHeader), res);
    _responseHeaderHandler(ctypeHeader, 1, strlen(ctypeHeader), res);
    _responseHeaderHandler(etagHeader, 1, strlen(etagHeader), res);
    _responseHeaderHandler(lastHeader, 1, strlen(lastHeader), res);

    assert(((void)"status code", res->StatusCode == 200));
    assert(((void)"status", strcmp(res->Status, "OK") == 0));
    
    char *ctypeh = res->GetHeader(res, "Content-Type");
    assert(((void)"ctype header not nil", ctypeh));
    assert(((void)"ctype header", strcmp(ctypeh, "text/html") == 0));

    char *etagh = res->GetHeader(res, "ETag");
    assert(((void)"custom header not nil", etagh));
    assert(((void)"custom header", strcmp(etagh, "W/\"10-/VnJyQBB0+b7i4NY83P42KKVWsM\"") == 0));
}


void test_http_client() {
    //test_http_client_new_request();
    test_http_client_response_header_handler(); 
    test_http_client_response_status_header_handler();
}
