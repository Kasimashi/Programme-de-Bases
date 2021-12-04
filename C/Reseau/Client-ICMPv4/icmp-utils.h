#ifndef ICMP_UTILS_H

#define ICMP_UTILS_H

#include <sys/socket.h>

void ping(struct sockaddr*, int, uint16_t);
struct sockaddr_in pong(int sock);

#endif // ICMP_UTILS_H
