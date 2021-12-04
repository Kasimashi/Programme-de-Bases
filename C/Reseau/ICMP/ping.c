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

  /*
   * int socket(int domain, int type, int protocol)
   * On retrouve plus d'informations sur cette fonction en regardant le manuel de socket mais en clair :
   *
   * le domaine sélectionne la famille de protocole à employer. Chaque
	famille possède son adressage. Par exemple pour les protocoles
	Internet IPv4, on utilisera le domaine PF_INET ou AF_INET et
	AF_INET6 pour le protocole IPv6.

	le type de dialogue : Pour PF_INET, on aura par exemple le choix
	entre : SOCK_STREAM (qui correspond à un mode connecté donc TCP
	par défaut), SOCK_DGRAM (qui correspond à un mode non connecté
	donc UDP) ou SOCK_RAW (qui permet un accès direct aux protocoles
	de la couche Réseau comme IP, ICMP, ...)

	le numéro de protocole dépendra du domaine de communication et
	du type de socket. Normalement, il n’y a qu’un seul protocole par
	type de socket pour une famille donnée : la valeur 0 désignera le
	protocole par défaut (SOCK_STREAM −→ TCP et SOCK_DGRAM −→ UDP).
	Néanmoins, rien ne s’oppose à ce que plusieurs protocoles existent,
	auquel cas il est nécessaire de le spécifier (c’est la cas pour SOCK_RAW
	où il faudra préciser le protocole à utiliser : IPPROTO_IP,
	IPPROTO_ICMP, ...).
   */
  int sock = socket(PF_INET6, SOCK_RAW, IPPROTO_ICMP);
  
  /*La fonction renvoie un descripteur sur la socket créée en cas de réussite
ou -1 en cas d’échec.*/
  if ( sock < 0 ) {
    perror("socket");
    exit(1);

  } 
  if ( argc != 2 ) {
    fprintf(stderr,"Use the correct argument, dumbass. (ping IP-ADDR)\n");
    exit(1);
  }

  /* On récupère l'argument du programme sous le nom "host" */
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

