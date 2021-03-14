#include "gc.h"
#include "hello.h"
#include "hello.c"


Response *get_fn(Handler *h, Request *req) {
    Response *res = NewResponse();
    res->SetStatus(res, "OK");
    res->SetStatusCode(res, 200);
    res->SetHeader(res, "Content-Type", "text/plain");
    res->WriteBody(res, "helloworld");
    return res;
}


int main() {

    Server *s = NewServer(9300);
    Handler *hnd = GC_MALLOC(sizeof(Handler));  // TODO:  Should have a constructor!

    hnd->Get = get_fn; // Assign HTTP method to handler function
    s->AddHandler(s, "/", hnd);

    return s->Start(s, TRUE) ;
}
