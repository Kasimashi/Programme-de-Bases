/*
LLORENTE ALEXIS M1

CE PROGRAMME SIMULE LA TRAVERSE DE DEUX BABOUIN : SON PERE ET SON FILS SUR UN NOMBRE DE LIANE DONNEE EN ARGUMENT EN UTILISANT LES PROCESSUS ET SIGNAUX
*/

#include <sys/types.h>
#include <unistd.h>
#include <signal.h>
#include <stdio.h>
#include <stdlib.h>
int ATTENTE_FILS; //Si la valeur est à 1 le fils patiente. CECI EST UNE VARIABLE GLOBALE
int ATTENTE_PERE; //Si la valeur est à 1 le fils patiente. CECI EST UNE VARIABLE GLOBALE
int nb_liane=2; // Indique le nombre de liane à parcourir (ici déclaré en globale mais peut être mis dans le main sans aucun problème)


void signal_USR1 (int sig) {
  ATTENTE_PERE = 1; //C'est au tour du père de traverser
}

void signal_USR2 (int sig) {
  ATTENTE_FILS = 1; //C'est au tour du fils de traverser
  
}

int traverser (char *identite,int i) {	
	printf("Babouin %s commence a traverser liane %d\n\n", identite,i); //Affichage pour l'utilisateur
	if (identite == "pere")
	{
		sleep(1); //Temps de traversé du père
	}
	else{
		sleep(2); //Temps de traversé du fils
	}
	printf("Babouin %s a fini de traverser liane %d\n\n", identite,i); //Affichage pour l'utilisateur
	
	return(0); //La traversée s'est bien effectuée
}

void main() {
  int exe = 0; //Valeur par défaut de la traversée
  int i=1; //Numéro de la liane à traverser
  pid_t pere, fils; //Déclaration des processus père et fils
  ATTENTE_PERE=1;//C'est au père de commencer
  ATTENTE_FILS=0;
  pere = getpid(); //On récupère le PID du père
  signal(SIGUSR1,&signal_USR1); //On déclare les signaux et les programmes qui vont s'effectuer suivant les signaux
  signal(SIGUSR2,&signal_USR2); //On déclare les signaux et les programmes qui vont s'effectuer suivant les signaux
  fils = fork(); //Déclaration du processus fils
  if (fils != 0) { //Si le PID du fils !=0 c'est au père d'agir.
    do { 
      if (ATTENTE_PERE==1) { //C'est au père de s'engager sur la liane
        exe=traverser("pere",i); //Le père traverse la liane numéro i
        if (exe == 0) { //Si la traversé s'est bien effectué
          kill(fils,SIGUSR2); //On envoi un signal au fils disant que c'est à lui de traverser
          ATTENTE_PERE=0; //On met en attente le père
		  i++;
          signal(SIGUSR1,&signal_USR1); //On déclare les signaux et les programmes qui vont s'effectuer suivant les signaux 
          signal(SIGUSR2,&signal_USR2); //On déclare les signaux et les programmes qui vont s'effectuer suivant les signaux
        }
      }               
    } while (i <= nb_liane); //On parcours toute les lianes
    kill(fils,SIGKILL); //Une fois que on a tout traversé on tue le processus fils
  } 
  else {
	
    do  {
      if (ATTENTE_FILS==1) {
        exe=traverser("fils",i);
        if (exe == 0) {
          kill(pere,SIGUSR1);
          ATTENTE_FILS=0;
		  i++;
          signal(SIGUSR1,&signal_USR1);
          signal(SIGUSR2,&signal_USR2); 
        }
      }
    } while (i <= nb_liane);
    kill (pere,SIGKILL);
  }
}
