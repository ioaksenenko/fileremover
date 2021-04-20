#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include "erproc.h"

int main() {
    int fd = Socket(AF_INET, SOCK_STREAM, 0);
    struct sockaddr_in addr = {0};
    addr.sin_family = AF_INET;
    addr.sin_port = htons(34543);
    Inet_pton(AF_INET, "192.168.98.100", (struct sockaddr *) &addr.sin_addr);
    Connect(fd, (struct sockaddr *) &addr, sizeof addr);
    char filename[256];
    printf("Enter the name of the file you want to delete: ");
    scanf("%s", filename);
    write(fd, filename, strlen(filename));
    char buf[256];
    int nread;
    nread = read(fd, buf, 256);
    if (nread == -1) {
    	perror("read failed");
	exit(EXIT_FAILURE);
    }
    if (nread == 0) {
    	printf("EOF occured\n");
    }
    write(STDOUT_FILENO, buf, nread);
    close(fd);
    return 0;
}
