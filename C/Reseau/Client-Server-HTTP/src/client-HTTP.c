/*
 ============================================================================
 Name        : client-HTTP.c
 Author      : 
 Version     :
 Copyright   : OpenSource
 Description : Web Client HTTP
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
	int	sockfd,n;
	int sendbytes;
	struct sockaddr_in	servaddr;
	char	sendline[MAXLINE];
	char	recvline[MAXLINE];

	/* Check usage of the program */
	if (argc !=2){
		err_n_die("Usage : %s <server ip address>", argv[0]);
	}

	/* Create a socket
	 * AF_INET : Address Family - Internet
	 * SOCK_STREAM
	 * 0 stand for TCP connection
	 * */
	if ( (sockfd = socket(AF_INET, SOCK_STREAM, 0)) <0){
		err_n_die("Error while create the socket !");
	}

	/* Zero out the address*/
	bzero(&servaddr, sizeof(servaddr));
	servaddr.sin_family = AF_INET;
	/* htons : host to network short : convert SERVER_PORT to little endian or big endian standard bytes order */
	servaddr.sin_port = htons(SERVER_PORT);

	/* Translating addr : inet_pton convert "1.2.3.4" ip addr to [1,2,3,4] */
	if(inet_pton(AF_INET, argv[1], &servaddr.sin_addr) <=0){
		err_n_die("inet_pton error for %s", argv[1]);
	}
	/* Connect to the server */
	/* Cette fonction connecte votre socket à l'adresse spécifiée dans la structure sockaddr.
Il s'agit donc d'une fonction à utiliser dans un client.*/
	if (connect(sockfd,(struct sockaddr *) &servaddr, sizeof(servaddr))< 0){
		err_n_die("Connect Failed!");
	}

	/* We're connected. Prepare GET HTTP Request message : meaning give me a page \n\r\n\r meaning the end of the request*/
	sprintf(sendline, "GET / HTTP/1.1\r\n\r\n");
	sendbytes = strlen(sendline);

	/* Send the request : making sure you send it all */
	if (write(sockfd, sendline, sendbytes) != sendbytes){
		err_n_die("Write error");
	}

	memset(recvline,0,MAXLINE);
	/* Now read server response */
	while ( (n = read(sockfd,recvline,MAXLINE-1)) >0 ){
		printf("%s",recvline);
	}
	if (n < 0){
		err_n_die("Read error");
	}

	exit(0);
}
