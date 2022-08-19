#include <stdio.h>
#include <stdlib.h>
#include <netinet/in.h>
#include <unistd.h>

int socket_create()
{
    int socket_descriptor;

    printf("Creating socket...\n");

    // create the socket
    socket_descriptor = socket(PF_INET, SOCK_STREAM, 0); // 0 -> TCP

    if (socket_descriptor == -1)
    {
        printf("There was an error creating the socket!\n");
        exit(EXIT_FAILURE);
    }

    return socket_descriptor;
}

struct sockaddr_in socket_address(uint32_t _address, uint16_t port)
{
    struct sockaddr_in address;

    address.sin_family = AF_INET;
    address.sin_port = port;
    address.sin_addr.s_addr = _address;

    return address;
}