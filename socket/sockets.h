#include <unistd.h>

// common.c
int socket_create();
struct sockaddr_in socket_address(uint32_t _address, uint16_t port);

// client.c
int socket_connect(uint32_t address, uint16_t port);

// server.c
int socket_serve(uint32_t _address, uint16_t port);
