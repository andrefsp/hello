#ifndef _HELLO_SERVER_C
#define _HELLO_SERVER_C

#include "uv.h"
#include "gc.h"
#define GC_THREADS

#include "server.h"
#include "hello.h"

#include "string_utils.c"
#include "buffer_utils.c"


void Server_Handler(uv_stream_t *stream, ssize_t nread, const uv_buf_t *buf) {
    Server *s = stream->data;
    // TODO: (andrefsp) :: User server for handlers at this point.
    // 
    uv_write_t *req = GC_MALLOC(sizeof(uv_write_t));
    if (nread == -1) {
        /* if (uv_last_error(loop).code != UV_EOF) { */
        /* } */
        uv_close((uv_handle_t *)stream, NULL);
        return;
    }

    // Create request
    Request *hreq = NewRequestFromBuffer(buf->base);
   
    // TODO(andrefsp): Handlers must be a router. 
    Handler *hnd = s->Handlers->Get(s->Handlers, hreq->Url);

    Response *hresp; 
    if (hnd) { 
        hresp = hnd->Get(hnd, hreq);
    } else {
        // Not found!
        hresp = NewResponse();
        hresp->SetStatus(hresp, "Not Found");
        hresp->SetStatusCode(hresp, 404);
    }
    
    uv_buf_t *resp = new_uv_buffer(hresp->ToString(hresp));

    int err = uv_write(req, stream, resp, 1, NULL);
    if (err) {
        fprintf(stderr, "Write error: %s\n", uv_strerror(err));
        /* error */
    }
    
    uv_close((uv_handle_t *)stream, NULL);
}


void Server_onConnection(uv_stream_t *server, int status) {
    if (status < 0) {
        fprintf(stderr, "New connection error %s\n", uv_strerror(status));
        return;
    }

    Server *s = server->data;

    uv_tcp_t *client = GC_MALLOC(sizeof(uv_tcp_t));
    client->data = server->data; // data is a pointer to the `Server` object


    uv_tcp_init(s->Server_uv_loop, client);

    if (uv_accept(server, (uv_stream_t*) client) == 0) {
        uv_read_start((uv_stream_t*) client, h_buffer_alloc, Server_Handler);
    } else {
        uv_close((uv_handle_t *)client, NULL);
    }
}

void Server_Listen(void *arg) {
    Server *s = arg;
    uv_run(s->Server_uv_loop, UV_RUN_DEFAULT);
}

int Server_Start(Server *s, int block) {
    s->address = GC_MALLOC(sizeof(*(s->address)));
    s->address->sin_family = AF_INET;
    s->address->sin_addr.s_addr = INADDR_ANY;
    s->address->sin_port = htons(s->port);

    uv_loop_init(s->Server_uv_loop); 

    uv_ip4_addr("0.0.0.0", s->port, s->address); // Assign address
    uv_tcp_init(s->Server_uv_loop, s->Server_uv_server);
    uv_tcp_bind(s->Server_uv_server, (const struct sockaddr*)s->address, 0);

    int err = uv_listen((uv_stream_t *)s->Server_uv_server, 128, Server_onConnection);
    if (err) {
        fprintf(stderr, "Error when listening: %s\n", uv_strerror(err));
        return err;
    }
  
    if (block) { 
        s->Listen(s);
    } else {
        uv_thread_t t_id;
        uv_thread_create(&t_id, s->Listen, s);
    }

    return 0;
}

void Server_close_handler(uv_handle_t *handler, void *arg) {
    if (!uv_is_closing(handler)) {
        uv_close(handler, NULL);
    }
}

int Server_Stop(Server *s) {
    uv_stop(s->Server_uv_loop);
    uv_loop_close(s->Server_uv_loop);
    uv_walk(s->Server_uv_loop, Server_close_handler, s);
    return 0;
}

int Server_AddHandler(Server *s, char *uri, Handler *hnd) {
    char *muri = GC_MALLOC(strlen(uri)*sizeof(char));
    strcpy(muri, uri);

    s->Handlers->Set(s->Handlers, muri, hnd);
    return 0;
}

Server *NewServer(int port) {
    Server *s = GC_MALLOC(sizeof(Server));
    s->Handlers = NewHashmap();

    s->port = port;
    s->Start = Server_Start;
    s->Stop = Server_Stop;
    s->Listen = Server_Listen;
    s->AddHandler = Server_AddHandler;

    s->Server_uv_loop = GC_MALLOC(sizeof(uv_loop_t));
    s->Server_uv_server = GC_MALLOC(sizeof(uv_tcp_t));
    s->Server_uv_server->data = s; // Pass server pointer to uv_loop handlers

    return s;
}

#endif
