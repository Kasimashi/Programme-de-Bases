/*
Ecrire un programme où père et fils exécutent des codes différents en utilisant la fonction execl().

Le programme principal (main.c) utilise la fonction fork() pour créer deux processus.

Le processus père (pere.c) affiche son pid, se met en sommeil cinq secondes puis affiche le message « Père terminé !».

Le processus fils (fils.c) affiche son pid ; puis affiche cinq fois le message « Fils au travail !».
*/



/* Programme pere.c */
#include <stdlib.h>
#include <stdio.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <stdio.h>
#include <string.h>
#include <fcntl.h>
#include <sys/uio.h>
#include <limits.h>
#include <unistd.h>

int main() {
  printf("PID pere : %d\n", getpid());
  sleep(5);
  printf("Pere termine !\n");
  exit(0);  
}


