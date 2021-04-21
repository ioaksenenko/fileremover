#include "erproc.h"
#include <sys/types.h>
#include <sys/socket.h>
<<<<<<< HEAD
#include <stdio.h> // для использования функции perror 
#include <stdlib.h> // для использования функции exit
=======
#include <stdio.h>
#include <stdlib.h>
>>>>>>> 2306faa2b66f33c07e01c02eb382dad1389bf5d4
#include <unistd.h>
#include <arpa/inet.h>

int Socket(int domain, int type, int protocol) {
    int res = socket(domain, type, protocol);
    if (res == -1) {
<<<<<<< HEAD
        perror("socked failed");
        exit(EXIT_FAILURE);
=======
    	perror("socked failed");
	exit(EXIT_FAILURE);
>>>>>>> 2306faa2b66f33c07e01c02eb382dad1389bf5d4
    }
    return res;
}

void Bind(int sockfd, const struct sockaddr *addr, socklen_t addrlen) {
    int res = bind(sockfd, addr, addrlen);
    if (res == -1) {
<<<<<<< HEAD
        perror("bind failed");
        exit(EXIT_FAILURE);
=======
    	perror("bind failed");
	exit(EXIT_FAILURE);
>>>>>>> 2306faa2b66f33c07e01c02eb382dad1389bf5d4
    }
}

void Listen(int sockfd, int backlog) {
    int res = listen(sockfd, backlog);
    if (res == -1) {
<<<<<<< HEAD
        perror("listen failed");
        exit(EXIT_FAILURE);
=======
    	perror("listen failed");
	exit(EXIT_FAILURE);
>>>>>>> 2306faa2b66f33c07e01c02eb382dad1389bf5d4
    }
}

int Accept(int sockfd, struct sockaddr *addr, socklen_t *addrlen) {
    int res = accept(sockfd, addr, addrlen);
    if (res == -1) {
<<<<<<< HEAD
        perror("accept failed");
        exit(EXIT_FAILURE);
=======
    	perror("accept failed");
	exit(EXIT_FAILURE);
>>>>>>> 2306faa2b66f33c07e01c02eb382dad1389bf5d4
    }
    return res;
}

void Connect(int sockfd, const struct sockaddr *addr, socklen_t addrlen) {
    int res = connect(sockfd, addr, addrlen);
    if (res == -1) {
<<<<<<< HEAD
        perror("connect failed");
        exit(EXIT_FAILURE);
=======
    	perror("connect failed");
	exit(EXIT_FAILURE);
>>>>>>> 2306faa2b66f33c07e01c02eb382dad1389bf5d4
    }
}

void Inet_pton(int af, const char *src, void *dst) {
    int res = inet_pton(af, src, dst);
    if (res == 0) {
<<<<<<< HEAD
        printf(
            "inet_pton failed: src does not contain a character "
            "string representing a valid network address in the specified address family\n"
        );
        exit(EXIT_FAILURE);
    }
    if (res == -1) {
        perror("inet_pton failed");
        exit(EXIT_FAILURE);
=======
    	printf(
	    "inet_pton failed: src does not contain a character "
	    "string representing a valid network address in the specified address family\n"
	);
	exit(EXIT_FAILURE);
    }
    if (res == -1) {
    	perror("inet_pton failed");
	exit(EXIT_FAILURE);
>>>>>>> 2306faa2b66f33c07e01c02eb382dad1389bf5d4
    }
}


void Remove(const char *file_name) {
    int res = remove(file_name);
    if (res == -1) {
<<<<<<< HEAD
        perror("remove faliled");
        exit(EXIT_FAILURE);
    }
}

void Setsockopt(int s, int level, int optname, const void *optval, socklen_t optlen) {
    int res = setsockopt(s, level, optname, optval, optlen);
    if (res == -1) {
        perror("setsockopt failed");
        exit(EXIT_FAILURE);
    }
}


int Read(int fd, void *buf, unsigned count) {
    int res = read(fd, buf, count);
    if (res == -1) {
        perror("reed failed");
        exit(EXIT_FAILURE);
    }
    return res;
}
=======
    	perror("remove faliled");
	exit(EXIT_FAILURE);
    }
}

>>>>>>> 2306faa2b66f33c07e01c02eb382dad1389bf5d4
