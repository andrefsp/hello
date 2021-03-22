#include "hello.h"


Response *get_fn(Handler *h, Request *req) {
    Response *res = NewResponse();
    res->SetStatusCode(res, codes.HttpOK);
    res->SetHeader(res, "Content-Type", "text/plain");
    res->WriteBody(res, "helloworld");
    return res;
}


int main() {
    Server *s = NewServer(9300);
    Handler *hnd = NewHandler();

    hnd->Get = get_fn; // Assign HTTP method to handler function
    s->AddHandler(s, "/", hnd);

    return s->Start(s, TRUE) ;
}
