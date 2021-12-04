
/*
	
	Ecrire un programme en langage C qui lance deux threads, l'un affichant 50 fois le caractère 1, et l'autre 50 fois le caractère 2.

Vous pourrez utiliser la fonction sched_yield() pour répartir la CPU entre les threads.


*/
#include <stdio.h> 
#include <pthread.h>
#include <stdlib.h>

#define N 50

void *routine(void *arg) { 
  int i;
  int *p = (int*)arg;
  int val = *p;

  for(i=0;i<N;i++) {
    /* Un processus peut volontairement libérer le processeur sans se bloquer en appelant sched_yield() */
    if (sched_yield() == 0){
    	printf("%d",val);
    }
    else
    {
    	printf("Erreur sur le scheld_yield()");
    	exit(1);
    }
  }

  /* On arrête le thread courant */
  pthread_exit(NULL); 
} 

int main() {
  int ret;
  pthread_t thA, thB;
  int i=1,j=2;

  /* On créer la tâche A */
  ret = pthread_create(&thA,NULL,routine,(void*)&i);
  if ( ret!= 0){
	  printf("Error to create the thread (%d)\n",ret);
	  exit(1);
  }

  /* On créer la tâche B */
  ret = ret = pthread_create(&thB,NULL,routine,(void*)&j);
  if ( ret!=0){
	  printf("Error to create the thread (%d)\n",ret);
	  exit(1);;
  }

  /* Lorsque nous créons des threads puis nous laissons continuer par exemple
   * la fonction main, nous prenons le risque de terminer le programme complètement
   * sans avoir pu exécuter les threads. Nous devons en effet attendre que les différents
   * threads créés se terminent.
   * Pour cela, il existe la fonction pthread_join
   */
  pthread_join(thA,NULL);
  pthread_join(thB,NULL);

  printf("\n");  
  return(0); 
}
