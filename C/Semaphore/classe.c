/*
On considère une classe de dix élèves en travaux dirigés de mathématiques. Chaque élève sera représenté par un thread.

On suppose que le TD comprend deux exercices. Chaque élève mettra un temps aléatoire (entre 1 et 10 secondes) pour effectuer chaque exercice.

On vous demande de synchroniser les threads à l'aide de sémaphores afin que chaque thread attende que tout le monde ait terminé l’exercice 1 pour passer à l’exercice 2.
*/

// Sémaphore N<=0 rien ne se passe sinon ça bouge !
#include <stdio.h>
#include <stdlib.h>
#include <semaphore.h>
#include <pthread.h>
#include <time.h>
#include <unistd.h>

#define TEMPS_MAX 10
#define N 10

sem_t MUTEX;
sem_t RDV;

volatile int CPT = 0;

void *eleve(void* arg){
	int i;
	int *p = (int*)arg;	
	int n = *p;	
	printf("Eleve %d commence exercice 1\n",n);
	sleep(rand()%(TEMPS_MAX+1));
	printf("Eleve %d termine exercice 1\n",n);
  	sem_wait(&MUTEX); //(P) Décrémentation de la valeur du sémaphore MUTEX : exclusion mutuelle
	sem_getvalue(&MUTEX,&i);
	printf("Valeur du sémaphore MUTEX : %d\n",i);
	CPT++;	 //Incrémentation du compteur CPT;
	if(CPT == N) { //Démarrage second exercice
		sem_post(&RDV);	//(V) Incrémentation Va y sur sémaphore 
	}
	sem_post(&MUTEX);//Incrémentation (on y retourne !)
	sem_getvalue(&MUTEX,&i);
	printf("Valeur du sémaphore MUTEX : %d\n",i);
	sem_wait(&RDV);//Décrémentation
	sem_post(&RDV); //Incrémentation
	printf("Eleve %d commence exercice 2\n",n);
  	sleep((rand()%TEMPS_MAX)+1);
	printf("Eleve %d termine exercice 2\n",n);
	
}

int main(){	
  int i = 0;
  pthread_t th[N];
  int tab[N];
  sem_init(&MUTEX, 0, 1); // Initialisation du sémaphore MUTEX à 1 (nombre de voie de circulation) (processus courant) Exclusion Mutuelle
  sem_init(&RDV, 0, 0); // initialisation du sémaphore RDV à 0 (processus courant)
  srand(time(NULL)); //initialisation de la fonction srand sur le temps actuel depuis 1970
  for(i=0; i<N; i++) {
    tab[i] = i+1;
    pthread_create(&th[i], NULL, eleve, (void*)&tab[i]);
  }
  for(i=0; i<N; i++) {
    pthread_join(th[i], NULL); //suspends l'execution du processus jusqu'à thread_exit();
  }
  return 0;
}
