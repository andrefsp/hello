#include <assert.h>
#include "../src/hello.c"


void test_server_start_stop(void) {
    Server *s = NewServer(9100);
    assert(s != NULL);
    assert(((void)"port is set", s->port == 9100));
    assert(((void)"run server", s->Start(s, FALSE) == 0));
    assert(((void)"stop server", s->Stop(s) == 0));
}

void test_server_start_listen(void) {
    Server *s = NewServer(9200);
    
    assert(((void)"run server", s->Start(s, FALSE) == 0));
    assert(((void)"stop server", s->Stop(s) == 0));
}

void test_server_with_request(void) {
    HttpClient *client = NewHttpClient();

    Server *s = NewServer(9300);
    assert(((void)"run server", s->Start(s, FALSE) == 0));
    
    Request *req = NewRequest("GET", "http://localhost:9300");

    Response *res = client->Do(client, req);

    assert(((void)"status code", res->StatusCode == 200));
    assert(((void)"stop server", s->Stop(s) == 0));
}


void test_server(void) {
    test_server_start_stop();
    test_server_start_listen();
    test_server_with_request();
}
