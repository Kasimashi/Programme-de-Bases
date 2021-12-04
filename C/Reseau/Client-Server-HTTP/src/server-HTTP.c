/*
 ============================================================================
 Name        : server-HTTP.c
 Author      :
 Version     :
 Copyright   : OpenSource
 Description : Web Server HTTP
 ============================================================================
 */

#include <sys/socket.h>
#include <sys/types.h>
#include <signal.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <stdarg.h>
#include <errno.h>
#include <sys/time.h>
#include <sys/ioctl.h>
#include <netdb.h>

#include "common.h"

/*
 * DEFINE DECLARATION
 */
/* Server port where we're connecting : standard HTTP port*/
#define SERVER_PORT 80

/* Buffer length where data goes*/
#define MAXLINE 4096

/*
 * PROTOTYPE DECLARATION
 */

int main(int argc, char **argv) {
	/* Local variables */
	int	listenfd,connfd,n;
	struct sockaddr_in	servaddr;
	char	buff[MAXLINE+1];
	char	recvline[MAXLINE+1];

	/* Create a socket
		 * AF_INET : Address Family - Internet
		 * SOCK_STREAM
		 * 0 stand for TCP connection
		 * */
	if ((listenfd = socket(AF_INET,SOCK_STREAM,0)) <0){
		err_n_die("Error while create the socket !");
	}

	/* Zero out the address*/
	bzero(&servaddr, sizeof(servaddr));
	servaddr.sin_family = AF_INET;
	servaddr.sin_addr.s_addr = htonl(INADDR_ANY);
	/* htons : host to network short : convert SERVER_PORT to little endian or big endian standard bytes order */
	servaddr.sin_port = htons(SERVER_PORT);

	/* Bind lie un socket avec une structure sockaddr. */
	if((bind(listenfd, (struct sockaddr *) &servaddr, sizeof(servaddr)))< 0){
		err_n_die("Bind error");
	}
	/* Cette fonction définit la taille de la file de connexions en attente pour votre socket s. */
	if ((listen(listenfd,10))<0){
		err_n_die("Listen Failed!");
	}

	/* Boucle infini */
	for (;;)
	{
		struct sockaddr_in addr;
		socklen_t addr_len;

		printf("Waiting for a connection on port%d\n", SERVER_PORT );
		fflush(stdout);
		connfd = accept(listenfd,(struct sockaddr *)NULL,NULL);

		memset(recvline,0,MAXLINE);
		/* Now read the client message */
		while ( (n = read(connfd,recvline,MAXLINE-1)) >0 ){
			fprintf(stdout, "\n%s\n\n%s", bin2hex(recvline,n),recvline);

			if(recvline[n-1] == '\n')
			{
				break;
			}
			memset(recvline,0,MAXLINE);
		}
		if (n < 0){
			err_n_die("Read error");
		}

		/* Now send a response */
		snprintf((char *)buff, sizeof(buff),"HTTP/1.0 200 OK\r\n\r\nHello");

		write (connfd,(char *)buff, strlen((char*)buff));
		close(connfd);
	}

	exit(0);
}



