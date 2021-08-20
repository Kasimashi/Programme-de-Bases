#include <sys/socket.h>
#include <sys/types.h>
#include <netdb.h>
#include <stdlib.h>
#include <stdio.h>
#include <arpa/inet.h>
#include <netinet/ip_icmp.h>
#include <string.h>
#include <stdint.h>
#include <sys/time.h>


#include "icmp-utils.h"

struct sockaddr_in pong(int);

int main(int argc, char* argv[]) {

  int sock = socket(PF_INET, SOCK_RAW, IPPROTO_ICMP);
  
  if ( sock < 0 ) {
    perror("socket");
    exit(1);

  } 
  if ( argc != 2 ) {
    fprintf(stderr,"Use the correct argument, dumbass. (ping IP-ADDR)\n");
    exit(1);
  }

  char* host = argv[1];


  struct addrinfo *ai;
  if (getaddrinfo ( host, NULL, NULL, &ai ) < 0 ) { 
    perror("getaddrinfo");
    exit(1);
  }

  uint16_t seq = 0;
  struct timeval beg;
  struct timeval end;
  struct sockaddr_in msg;

  for (; seq < 10; seq++ ) {
    gettimeofday(&beg, NULL);
    ping(ai->ai_addr, sock, seq);
    msg = pong(sock);
    char hostname[128];
    gettimeofday(&end, NULL);
    printf("time=%f ms\t",
        (end.tv_sec-beg.tv_sec)*1000.0 + (end.tv_usec-beg.tv_usec)/1000.0);
    getnameinfo((struct sockaddr *)&msg, sizeof(msg), 
        hostname, sizeof(hostname), NULL, 0, 0); 
    printf("from=%s\n", hostname );
  }

  return 0;
}

