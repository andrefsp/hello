#include <assert.h>
#include "../src/hello.c"


void test_request_properties() {
    char *url = "http://localhost:7777";
    Request *req = NewRequest("GET", url);
 
    assert(((void)"url", strcmp(req->Url, url) == 0));
    assert(((void)"method", strcmp(req->Method, "GET") == 0));

    req->SetTimeout(req, 2);
    req->SetHeader(req, "Content-Type", "application/json");
    req->SetBody(req, "{\"a\": 1}");

    char *ctypeh = req->GetHeader(req, "Content-Type");
    assert(((void)"ctype header not nil", ctypeh));
    assert(((void)"ctype header", strcmp(ctypeh, "application/json") == 0));

    assert(((void)"body not nil", req->Body));
    assert(((void)"body", strcmp(req->Body, "{\"a\": 1}") == 0));
}

void test_request_parse() {
   
    char *buff = "GET / HTTP/1.1\r\n\
Host: localhost:9300\r\n\
Accept: */*\r\n\
Content-Length: 9\r\n\
Content-Type: application/json\r\n\
\r\n\
{\"a\":123}\r\n";

    Request *req = NewRequestFromBuffer(buff); 
    assert(((void)"Request not null", req));
    assert(((void)"method", strcmp(req->Method, "GET") == 0));

    char *ctypeHeader = req->GetHeader(req, "Content-Type");
    assert(((void)"header not null", ctypeHeader));
    assert(((void)"method", strcmp(ctypeHeader, "application/json") == 0));
}

void test_request(void) {
    test_request_properties();
    test_request_parse();
}
