#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>
#include <string.h>
#include <pthread.h>
#include <errno.h>
#include <semaphore.h>

#define NB_THREAD 4
#define LIMIT 2

// Création du sémaphore;
sem_t semaphore; //initialisation du sémaphore

void * job(void * args) {
	// Récupération de l'identifiant du thread
	int tid = pthread_self();
	int i = 0;
	while (i < LIMIT) {
		// On attend la disponibilité du sémaphore
		sem_wait(&semaphore); //Attention cette fonction est bloquante !
		/*
		semaphore → pointeur vers le sémaphore à bloquer ;
			le code retour varie entre:
			'0' si tout s'est bien passé
			'-1' si une erreur survient et errno est positionné
		*/
		// Section critique
		printf("Je suis le thread [%i] et je vais dormir 1 seconde\n", tid);
		sleep(1);
		printf("Je suis le thread [%i] et j'ai fini ma sieste\n", tid);
		// On relache le sémaphore
		sem_post(&semaphore);
		i++;
	}
	pthread_exit(EXIT_SUCCESS);
}

int main() {
	// Création d'un tableau de thread
	pthread_t threads[NB_THREAD];
	// Initialisation du sémaphore
	sem_init(&semaphore, PTHREAD_PROCESS_SHARED, 1);
	/*
	semaphore → pointeur vers le sémaphore à initialiser ;
		pshared → drapeau qui précise si le sémaphore est utilisé par des threads (valeur 0) ;
		valeur → valeur de départ du sémaphore.
		le code retour varie entre:
		'0' si tout s'est bien passé
		'1' si une erreur survient et errno est positionné
	*/
	for (int i = 0; i < NB_THREAD; i++) {
		int err;
		if ((err = pthread_create(&threads[i], NULL, job, NULL)) != 0) {
			printf("Echec de la création du thread: [%s]", strerror(err));
			return EXIT_FAILURE;;
		}
		printf("Création du thread numéro %i\n", i);
	}
	for (int i = 0; i < NB_THREAD; i++) {
		pthread_join(threads[i], NULL);
	}
	sem_destroy(&semaphore);
	return EXIT_SUCCESS;
}