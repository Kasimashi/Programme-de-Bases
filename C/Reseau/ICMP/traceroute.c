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

int main(int argc, char* argv[]) {
  int opt = 31;

  int sock = socket(PF_INET, SOCK_RAW, IPPROTO_ICMP);

  if ( sock < 0 ) {
    perror("socket");
    exit(-1);
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

  // get destination by pinging normally
  ping(ai->ai_addr, sock, (uint16_t)0);
  struct sockaddr_in msg = pong(sock);
  char target[128];
  getnameinfo((struct sockaddr *)&msg, sizeof(msg), 
      target, sizeof(target), NULL, 0, 0); 

  printf("Trying up to 30 hops:\n");
  opt = 1;
  for (; opt <= 31; opt++ ) {

    setsockopt(sock, IPPROTO_IP, IP_TTL, &opt, sizeof(opt));
    ping(ai->ai_addr, sock, (uint16_t)0);
    struct sockaddr_in msg = pong(sock);
    char hostname[128];
    getnameinfo((struct sockaddr *)&msg, sizeof(msg), 
        hostname, sizeof(hostname), NULL, 0, 0); 
    printf("from=%s\n", hostname );
    if (strcmp(hostname, target) == 0) break;
  }

  return 0;
}
