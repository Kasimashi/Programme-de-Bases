/*
Ecrire un programme en langage C qui lance deux threads :

le premier remplit un tableau de dix cases  avec les nombres de 1 à 10 à raison d’une case toutes les secondes
le second tente de lire ce même tableau à raison de deux cases toutes les secondes
Au moyen de sémaphore(s), on vous demande de synchroniser les threads afin que le thread lecteur ne lise à aucun moment une case qui n'est pas écrite.

Vous pourrez utiliser la fonction sleep(int n) afin d'attendre n secondes.

On demande aussi que la section critique soit la plus courte possible…

*/
#include <stdio.h> 
#include <pthread.h>
#include <semaphore.h>

#define N 10

sem_t mutex;
volatile int TAB[N];

void *ecrire(){ 
  int i = 0;
  for(i=1; i<=N; i++) {
    TAB[i-1] = i;
    printf("Ecrire %d\n",TAB[i-1]);
    if( i % 2 == 0 ) {
      sem_post(&mutex);
    }
    sleep(1);
  }
}

void *lire() { 
  int nr = 0;
  while( nr < N) {
    sem_wait(&mutex);
    printf("Lire %d\n",TAB[nr]);
    printf("Lire %d\n",TAB[nr+1]);
    nr+=2;
    sleep(1);
  }
}


int main(){ 
  pthread_t thA, thB;
  sem_init(&mutex, 0, 0);
  pthread_create(&thA, NULL, lire, NULL);
  pthread_create(&thB, NULL, ecrire, NULL);
  pthread_join(thA, NULL);
  pthread_join(thB, NULL);
  return(0); 
}
