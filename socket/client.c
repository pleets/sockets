#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <unistd.h>
#include "sockets.h"

int socket_connect(uint32_t address, uint16_t port)
{
    int socket_descriptor = socket_create();

    // specity an address for the socket
    struct sockaddr_in server_address = socket_address(address, port);

    printf("Stablishing connection...\n");

    int connection_status = connect(
        socket_descriptor,
        (struct sockaddr *) &server_address,
        sizeof(server_address)
    );

    if (connection_status == -1) {
        printf("There was an error making a connection to the remote server\n");
        exit(EXIT_FAILURE);
    }

    printf("Connected!\n");

    char server_response[256];

    // receive data from the server
    recv(socket_descriptor, server_response, sizeof(server_response), 0);

    printf("The server sent: %s\n", server_response);

    // close the socket
    close(socket_descriptor);

    return socket_descriptor;
}