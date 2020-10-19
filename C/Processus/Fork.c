/*
Ecrire un programme qui crée deux processus à l'aide de l'appel système fork(). 

Le père affichera les entiers pairs compris entre 1 et 100, le fils affichera les entiers impairs compris dans le même intervalle. 
*/

#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>
#include <stdio.h>

int main() {
  int i;
  pid_t pidFork = fork();
  if( pidFork != 0 ) {
    printf("je suis le pere!\n");
    for(i=1;i<=19;i+=2) {
      printf("%d\n",i);
      sleep(1);
    }
    wait(NULL);
  } else {
  printf("je suis le fils!\n");
    for(i=0;i<=20;i+=2) {
      printf("%d\n",i);
      sleep(1);
    }
  }
}
