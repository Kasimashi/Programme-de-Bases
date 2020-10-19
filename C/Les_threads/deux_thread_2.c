/*
Ecrire un programme en langage C qui affiche les nombres entres 1 et 100 au moyen de deux threads.

Le premier thread affichera les entiers pairs compris entre 1 et 100, le second affichera les entiers impairs compris dans le même intervalle. 

*/


#include <stdio.h> 
#include <pthread.h>

#define N 100    

void *func1( ) { 
  int i;
  for(i=0;i<=N;i++) {
    if( (i % 2) == 0) {
      printf("Thread #1 : %d\n",i);
    }
    sched_yield();
  }
  pthread_exit(NULL); 
}
 
void *func2( ) { 
  int i;
  for(i=0;i<=N;i++) {
    if( (i % 2) != 0) {
      printf("Thread #2 : %d\n",i);
    }
    sched_yield();
  }
  pthread_exit(NULL); 
}

int main() { 
  pthread_t th1, th2;
  pthread_create(&th1,NULL,func1,NULL);
  pthread_create(&th2,NULL,func2,NULL);
  pthread_join(th1,NULL);
  pthread_join(th2,NULL);
  return(0); 
}
