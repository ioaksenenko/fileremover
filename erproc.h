#ifndef ERPROC_H
#define ERPROC_H

#include <sys/types.h>
#include <sys/socket.h>

int Socket(int domain, int type, int protocol);

void Bind(int sockfd, const struct sockaddr *addr, socklen_t addrlen);

void Listen(int sockfd, int backlog);

int Accept(int sockfd, struct sockaddr *addr, socklen_t *addrlen);

void Connect(int sockfd, const struct sockaddr *addr, socklen_t addrlen);

void Inet_pton(int af, const char *src, void *dst);

void Remove(const char *file_name);

void Setsockopt(int s, int level, int optname, const void *optval, socklen_t optlen);

int Read(int fd, void *buf, unsigned count);

#endif
