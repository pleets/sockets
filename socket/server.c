#include <stdio.h>
#include <stdlib.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <unistd.h>
#include "sockets.h"

int socket_serve(uint32_t _address, uint16_t port)
{
    int socket_descriptor = socket_create();

    // specity an address for the socket
    struct sockaddr_in server_address = socket_address(_address, port);

    // bind the socket to our specified IP and port
    int bind_status = bind(
        socket_descriptor,
        (struct sockaddr *) &server_address,
        sizeof(server_address)
    );

    if (bind_status == -1) {
        printf("There was an error binding the specified address\n");
        exit(EXIT_FAILURE);
    }

    printf("Preparing for listening...\n");

    int listen_status = listen(socket_descriptor, 5);

    if (listen_status == -1) {
        printf("There was an error listening the socket\n");
        exit(EXIT_FAILURE);
    }

    printf("Listening right now!...\n");

    int client_socket;

    client_socket = accept(
        socket_descriptor,
        // clint address and size
        NULL,
        NULL
    );

    if (client_socket == -1) {
        printf("There was an error accepting the incomming connection\n");
        exit(EXIT_FAILURE);
    }

    char server_message[256] = "You have reached the server!";

    send(
        client_socket,
        server_message,
        sizeof(server_message),
        0
    );

    // close the socket
    close(socket_descriptor);

    printf("Data sent!...\n");
}