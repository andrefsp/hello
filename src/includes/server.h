#ifndef _HELLO_SERVER_H
#define _HELLO_SERVER_H

#include <sys/socket.h> 
#include <netinet/in.h> 
#include <unistd.h>
#include "uv.h"
#include "hashmap.h"
#include "handler.h"


typedef struct Server Server;


struct Server {
    uv_tcp_t *Server_uv_server;
    uv_loop_t *Server_uv_loop;

    // Key: url , val: Handler
    Hashmap *Handlers ;

    int port;
    struct sockaddr_in *address;

    int (*Start)(Server *s, int block);
    int (*Stop)(Server *s);
    void (*Listen)(void *s);
    int (*AddHandler)(Server *s, char *uri, Handler *hnd);
};

int Server_Start(Server *s, int block);

int Server_Stop(Server *s);

void Server_Listen(void *s);

int Server_AddHandler(Server *s, char *uri, Handler *hnd);

// Constructor
Server *NewServer(int port);

#endif
