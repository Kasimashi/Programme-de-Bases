/*
LLORENTE ALEXIS M1

CE PROGRAMME SIMULE LA TRAVERSEE DE DEUX FAMILLES DE BABOUINS A L'AIDE DE SEMAPHORE ET DE THREADS (CHAQUES THREADS SIMULANT 1 SEUL ET UNIQUE BABOUIN)
A compiler avec l'option -lpthread !!
*/

// Sémaphore N<=0 rien ne se passe sinon ça bouge !
#include <stdio.h>
#include <stdlib.h>
#include <semaphore.h>
#include <pthread.h>
#include <time.h>
#include <unistd.h>

// On défini les variables globales
#define N_A 5
#define N_B 5

//On déclare les différents sémaphore utilisé
sem_t MUX_A;
sem_t MUX_B;
sem_t LIBRE;
sem_t VERROU_A;
sem_t VERROU_B;

//On déclare les compteurs en variables globales.
volatile int CPT_A = 0;
volatile int CPT_B = 0;
volatile int CPT_en_cours = 0;

//Déclaration de la routine A
void *babouinA(void* arg){
	int *p = (int*)arg;	 //On récupère les arguments de la route A : correspond au numéro du babouin concerné
	int n = *p;	 //On récupère les arguments de la route A : correspond au numéro du babouin concerné
	sem_wait(&MUX_A); //(P) Décrémentation de la valeur du sémaphore MUX_A : Semblable au feu rouge
	CPT_en_cours++; //Compteur du nombre de babouin sur la liane
	printf("Babouin %d famille A commence a traverser canyon (%d sur la liane)\n",n,CPT_en_cours); //Affichage
	sleep(1); //Temps de traversé
	CPT_en_cours--; //Décrémentation du compteur
	printf("Babouin %d famille A a fini de traverser canyon (%d sur la liane)\n",n,CPT_en_cours); //Affichage
	sem_post(&VERROU_A); //Incrémentation du verrou : permet d'écrire dans CPT_A
	CPT_A++;	 //Incrémentation du compteur CPT;
	sem_wait(&VERROU_A); //Décrémentation du verrou : bloque CPT_A
	sem_post(&MUX_A);//Incrémentation (on y retourne !)
  	if(CPT_A == N_A) { //Démarrage de la seconde famille
		sem_post(&LIBRE);	//(V) Incrémentation Va y sur sémaphore LIBRE 
	}
	
	
}

void *babouinB(void* arg){ //Routine de BabouinB
	int libre; //Variable indiquant si la voie est libre ou non
	int *p = (int*)arg;	
	int n = *p;	
	sem_getvalue(&LIBRE,&libre); //On récupère la valeur du sémaphore LIBRE
	if (libre==1){ //Si la voie est libre la famille B s'élance
		sem_wait(&MUX_B);//Décrémentation
		CPT_en_cours++; //Compteur du nombre de Babouin sur la liane
		printf("Babouin %d famille B commence a traverser canyon (%d sur la liane)\n",n,CPT_en_cours); //Affichage
		sleep(1); //Temps de traversé
		CPT_en_cours--; //décrémentation du compteur
		printf("Babouin %d famille B a fini de traverser canyon (%d sur la liane)\n",n,CPT_en_cours); //Affichage
		sem_post(&VERROU_B); //Déactivation du verrou
		CPT_B++;
		sem_wait(&VERROU_B); //Activation du verrou
		sem_post(&MUX_B); //Incrémentation
		
	}
	
	
}

int main(){ //Programme Principal
  int i = 0;
  pthread_t thA[N_A];
  pthread_t thB[N_B];
  int tabA[N_A];
  int tabB[N_B];
  sem_init(&MUX_A, 0, 1); // Initialisation du sémaphore MUX_A à 1 (nombre de voie de circulation) (processus courant)
  sem_init(&MUX_B, 0, 1); // initialisation du sémaphore MUX_B à 1 (processus courant)
  sem_init(&LIBRE, 0, 0);  //Initialisation du sémaphore LIBRE à 0 : chemin initialement occcupé par la famille A
  sem_init(&VERROU_A, 0, 0); //Activation de base du vérrou A
  sem_init(&VERROU_B, 0, 0); //Activation de base du vérrou B
  for(i=0; i<N_A; i++) { //CREATION DE LA FAMILLE DE BABOUIN A
    tabA[i] = i+1;
    pthread_create(&thA[i], NULL, babouinA, (void*)&tabA[i]); //APPEL DE LA ROUTINE
  }
  for(i=0; i<N_A; i++) {
    pthread_join(thA[i], NULL); //suspends l'execution du processus jusqu'à thread_exit();
  }
  for(i=0; i<N_B; i++) { //CREATION DE LA FAMILLE DE BABOUIN B
    tabB[i] = i+1;
    pthread_create(&thB[i], NULL, babouinB, (void*)&tabB[i]); //APPEL DE LA ROUTINE
  }
  for(i=0; i<N_B; i++) {
    pthread_join(thB[i], NULL); //suspends l'execution du processus jusqu'à thread_exit();
  }
  return 0;
}
