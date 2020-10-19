/*
En utilisant la fonction popen(), écrire un programme qui affiche la liste des fichiers d’un répertoire donné.
*/

#include <stdio.h>
#include <stdlib.h>
#define BUFSIZE 4096

main() {
	FILE *fp;
	char *buf;
	char *command = "ls";
	buf = (char*)( malloc(sizeof(BUFSIZE) ) );
	if ( ( fp = popen(command, "r") ) == NULL )  {
		printf("Erreur creation pipe\n");
		exit(-1);
	}
	while ( fgets(buf, sizeof(buf), fp ) != NULL ) {
		fprintf(stdout, "%s", buf);  
  }
	pclose(fp);
} 

