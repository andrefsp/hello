// Test includes files
#define GC_DEBUG
#include "gc.h"
#include <stdlib.h>

#include "point.c"
#include "server.c"
#include "request.c"
#include "response.c"
#include "hashmap.c"
#include "string_utils.c"
#include "http_client.c"


int main(void) {
    GC_INIT();

    test_hashmap();
    test_string_utils();
    test_point();

    test_server();
    test_response();

    test_request();

    test_http_client();

    GC_gcollect();

    return 0;
}
