
#include <sys/types.h>
#include <unistd.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <sys/uio.h>
#include <limits.h>
/*
Ecrire un programme qui crée un fichier contenant la chaine de caractère « oui oui » puis remplace chaque occurrence du caractère o par le caractère l.
*/

#include <stdio.h> 
#include <string.h>
#include <stdlib.h>

int main() {

  int fd;
  char *buf  = "oui oui";
  char *cherche = "o";
  char *remplace = "l";
  char *tmp = malloc(1);
  int i = 0;

  if ( (fd=open("DATA", O_CREAT|O_RDWR, 0700) ) != -1) {
    write( fd, buf, strlen(buf) );
    lseek(fd, i, 0);
    while (read(fd, tmp, 1)) {
      i++;     
      lseek(fd, i, 0);
      printf("Caractere lu : %s\n", tmp);
      if (strcmp(tmp, cherche)==0) {
        printf("Remplacer %s par %s\n", tmp, remplace);
        lseek(fd, -1, 1);
        write( fd, remplace, 1);
      }  
    }
    close(fd);
  }
}

