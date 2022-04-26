#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <strings.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <netinet/in.h>
#include <netdb.h>

#include <factory_config.h>
#include <prod_data.h>

int main(int argc, char *argv[]) {
    printf("Hello factory!\n");
    printf("Factory version %d.%d\n", FACTORY_VERSION_MAJOR, FACTORY_VERSION_MINOR);
    
    if (argc < 3) {
        fprintf(stderr, "ERROR, usage %s hostname port\n", argv[0]);
        exit(1);
    }
    struct hostent *server = gethostbyname(argv[1]);
    if (server == NULL) {
        fprintf(stderr, "ERROR, host unknown\n");
        exit(1);
    }
    int portno = atoi(argv[2]);

    int socketfd = socket(AF_INET, SOCK_STREAM, 0);
    if (socketfd < 0) {
        fprintf(stderr, "ERROR, socket creation failed\n");
        exit(1);
    } 

    struct sockaddr_in server_addr;
    bzero((char *) &server_addr, sizeof(server_addr)); // zero possible padding
    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(portno);
    bcopy((char *)server->h_addr_list[0], (char *)&server_addr.sin_addr.s_addr, server->h_length);

    if (connect(socketfd, (struct sockaddr *)&server_addr, sizeof(server_addr)) < 0) {
        fprintf(stderr, "ERROR, connection to %s %s failed\n", argv[1], argv[2]);
        exit(1);
    }

    int val = create_data();
    printf("Factory created %d\n", val);

    char buffer[256];
    sprintf(buffer, "%d", val);
    if (send(socketfd, buffer, strlen(buffer), 0) < 0) {
        fprintf(stderr, "ERROR, send failed\n");
        exit(1);
    }

    return 0;
}