#include <sys/types.h>
#include <sys/socket.h>
#include <stdio.h>
#include <stdlib.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <string.h>
#include "erproc.h"

int main() {
    int server = Socket(AF_INET, SOCK_STREAM, 0);
    if (setsockopt(server, SOL_SOCKET, SO_REUSEADDR, &(int){1}, sizeof(int)) < 0) {
        perror("setsockopt failed");
        exit(EXIT_FAILURE);
    }
    struct sockaddr_in addr = {0};
    addr.sin_family = AF_INET;
    addr.sin_port = htons(34543);
    Bind(server, (struct sockaddr *) &addr, sizeof addr);
    Listen(server, 5);
    socklen_t addrlen = sizeof addr;
    int client = Accept(server, (struct sockaddr *) &addr, &addrlen);
    int nread;
    char filename[256];
    nread = read(client, filename, 256);
    if (nread == -1) {
    	perror("reed failed");
	exit(EXIT_FAILURE);
    }
    if (nread == 0) {
    	printf("END OF FILE occured\n");
    }
    Remove(filename);
    char response[512];
    sprintf(response, "File '%s' deleted successfully.\n", filename);
    write(client, response, strlen(response));
    sleep(1);
    close(client);
    close(server);
    return 0;
}
