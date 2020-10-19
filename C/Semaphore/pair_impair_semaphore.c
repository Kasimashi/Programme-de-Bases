/*

Ecrire un programme C qui affiche les nombres entres 1 et 20 au moyen de deux threads.

Le premier thread affichera les entiers pairs compris entre 1 et 20, le second affichera les entiers impairs compris dans le même intervalle.

Synchroniser les threads à l'aide de sémaphores pour que l'affichage soit ordonné : 1 2 3 ... 20

*/


#include <stdio.h> 
#include <pthread.h>
#include <semaphore.h>

#define N 20    

sem_t mutex;

void *func1( ) { 
  int i;
  for(i=0; i<=N; i++) {
    sem_wait(&mutex);
    if( (i % 2) == 0) {      
      printf("Thread #1 : %d\n", i);
    }
    sched_yield();
    sem_post(&mutex);
    sleep(1);
  }
  pthread_exit(NULL); 
}
 
void *func2( ) { 
  int i;
  for(i=0; i<=N; i++) {
    sem_wait(&mutex);
    if( (i % 2) != 0) {      
      printf("Thread #2 : %d\n",i);
    }
    sched_yield();
    sem_post(&mutex);
    sleep(1);
  }
  pthread_exit(NULL); 
}

main() { 
  pthread_t th1, th2;
  sem_init(&mutex, 0, 1);
  pthread_create(&th1, NULL, func1, NULL);
  pthread_create(&th2, NULL, func2, NULL);
  pthread_join(th1, NULL);
  pthread_join(th2, NULL);
  return(0); 
}
