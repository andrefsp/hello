#include "assert.h"
#include "strings.h"
#include "../src/hello.c"

void test_response_status_code() {
    Response *res = NewResponse();
    
    res->SetStatusCode(res, codes.HttpOK);
    assert(((void)"status code", res->HttpStatusCode->Code == 200));
    assert(((void)"status", strcmp(res->HttpStatusCode->Status, "OK") == 0));
}


void test_response_write_body() {
    Response *res = NewResponse();
    res->SetStatusCode(res, codes.HttpOK);
    assert(((void)"status code", res->HttpStatusCode->Code == 200));
    assert(((void)"status", strcmp(res->HttpStatusCode->Status, "OK") == 0));

    res->WriteBody(res, "this");
    res->WriteBody(res, "_is_\n"); 
    res->WriteBody(res, "data");
    assert(((void)"body", strcmp(res->Body, "this_is_\ndata") == 0));
}


void test_response_set_headers() {
    Response *res = NewResponse();
    res->SetHeader(res, "Content-Type", "text/json");
    res->SetHeader(res, "Etag", "thisisatag");

    char *etag = res->GetHeader(res, "Etag");
    char *ctype = res->GetHeader(res, "Content-Type");

    
    assert(((void)"header size", res->Headers->Size == 2));

    assert(((void)"etag header not nil", etag));
    assert(((void)"ctype header not nil", ctype));

    assert(((void)"etag check", strcmp(etag, "thisisatag") == 0));
    assert(((void)"ctype check", strcmp(ctype, "text/json") == 0));

}


void test_response() {
    for (int x = 0; x < 10000; x++) {
        test_response_status_code();
        test_response_write_body();
        test_response_set_headers();
    }
}
