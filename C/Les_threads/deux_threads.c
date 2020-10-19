
/*
	
	Ecrire un programme en langage C qui lance deux threads, l'un affichant 50 fois le caractère 1, et l'autre 50 fois le caractère 2.

Vous pourrez utiliser la fonction sched_yield() pour répartir la CPU entre les threads.


*/
#include <stdio.h> 
#include <pthread.h>

#define N 50    

void *routine(void *arg) { 
  int i;
  int *p = (int*)arg;
  int val = *p;
  for(i=0;i<N;i++) {
    printf("%d",val);
    sched_yield();
  }
  pthread_exit(NULL); 
} 

main() { 
  pthread_t thA, thB;
  int i=1,j=2;
  pthread_create(&thA,NULL,routine,(void*)&i);
  pthread_create(&thB,NULL,routine,(void*)&j);
  pthread_join(thA,NULL);
  pthread_join(thB,NULL);
  printf("\n");  
  return(0); 
}
