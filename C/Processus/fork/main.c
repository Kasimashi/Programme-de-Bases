/*
Ecrire un programme où père et fils exécutent des codes différents en utilisant la fonction execl().

Le programme principal (main.c) utilise la fonction fork() pour créer deux processus.

Le processus père (pere.c) affiche son pid, se met en sommeil cinq secondes puis affiche le message « Père terminé !».

Le processus fils (fils.c) affiche son pid ; puis affiche cinq fois le message « Fils au travail !».
*/

/* Programme main.c */
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <errno.h>
 
int main() {
  int i;
  pid_t pidFork = fork();
  if( pidFork != 0 ) {
    execl("./pere", "pere", NULL);
    perror("pb avec pere\n");
    exit(-1);
  } else {
    execl("./fils", "fils", NULL);
    perror("pb avec fils\n");
    exit(-1);
  }
}

