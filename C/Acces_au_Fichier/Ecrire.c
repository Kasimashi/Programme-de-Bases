#include <stdio.h>
#include <string.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <sys/uio.h>
#include <limits.h>
#include <unistd.h>

int main() {
  int fd;
  int cc;
  char *buf = "#file:DATA -date: Tues Sep 22 16/03.281 WET 19982 author:root \n";
  if ((fd = open("DATA", O_CREAT|O_WRONLY,S_IRWXU))!=-1){
    if((cc = write(fd,buf,strlen(buf)))!=strlen(buf)){
	printf("Erreur dans l'écriture du fichier\n");
	}
	printf("Nombre de caractères écrits : %d\n",cc);
	close(fd);
}
}
