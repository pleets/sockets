#include <stdio.h>
#include <string.h>
#include <netinet/in.h>
#include "socket/sockets.h"

int main(int argc, char *argv[])
{
    if (strcmp(argv[1], "--serve") == 0) {
        printf("Starting server...\n");
        socket_serve(htonl(INADDR_ANY), htons(9000));
    } else if (strcmp(argv[1], "--connect") == 0) {
        printf("Starting connection...\n");
        socket_connect(htonl(INADDR_ANY), htons(9000));
    } else {
        printf("Invalid option!\n");
    }

    return 0;
}
