/*
Pour éviter un conflit d'affichage des deux sessions et un conflit de lecture de valeurs, on utilise deux variables globales entières pere_actif et fils_actif. L'échange de signaux entre processus père et fils doit garantir qu'à tout instant on a fils_actif=1 et pere_actif=0, ou bien fils_actif=0 et pere_actif=1.

On utilise les deux signaux réservés aux application SIGUSR1 et SIGUSR2. Le premier servira au fils à "donner la main" au père pour qu'il s'exécute, le second servira au père à "donner la main" à son fils .

Comment le processus père "donne la main" à son fils ? Il positionne la variable entière pere_actif à 0 pour ne plus effectuer son traitement, et envoie le signal SIGUSR2 à son fils dont il connaît le pid. Le fils doit disposer d'une fonction de traitement du signal SIGUSR2 qui va être appelée lors de la réception du signal et va basculer fils_actif à la valeur 1. Ceci permettant au fils de faire appel au traitement.

Le fils agit de même lors d'un nouveau basculement : fils_actif=0; envoi de SIGUSR1 au père, traitement du signal reçu par le père.

Utiliser les fonctions système signal() et kill(), et les variable globales fils_actif et pere_actif pour faire les basculements de sessions.

Pourrait-on avoir père_actif=1 fils_actif=0 pour le processus père, et père_actif=0 fils_actif=1 pour le processus fils, alors que ces variables sont des variables globales  au programme C ?
*/
#include <sys/types.h>
#include <unistd.h>
#include <signal.h>
#include <stdio.h>

int pere_actif,fils_actif;

void signal_USR1 (int sig) {
  printf("signal %d!\n",sig);
  printf("signal_USR1 !\n");
  pere_actif=1; 
}

void signal_USR2 (int sig) {
  printf("signal %d!\n",sig);
  printf("signal_USR2 !\n");
  fils_actif=1; 
}

int traitement (char *identite, char operation, char *correspondant) {
  int val1, val2;
  printf("%s=>Entrez 2 valeurs > 0 pour une ", identite);
  
    printf("multiplication;\n");
  printf("%s=>Entrez 0 pour passer a la session %s;\n", identite, correspondant);
  printf("%s=>Entrez une valeur negative pour terminer.\n", identite);if (operation == '+')
    printf("addition;\n");
  else
  scanf("%d",&val1);
  if (val1 == 0)
    return (0);
  if (val1 < 0)
    return (-1);
  scanf("%d",&val2);
  if (operation == '+')
    printf("%s=>Resultat : %d\n", identite, val1+val2);
  else
    printf("%s=>Resultat : %d\n", identite, val1*val2);
}

void main() {
  int val = 1;
  pid_t pere, fils;
  pere_actif=1;
  fils_actif=0;
  pere = getpid();
  signal(SIGUSR1,&signal_USR1);
  signal(SIGUSR2,&signal_USR2);
  printf("pere_actif main: %d\n",pere_actif);
  printf("fils_actif main: %d\n",fils_actif);
  fils = fork();
  if (fils != 0) {
    printf("PERE getpid=> :%d\n\n",getpid()); 
    do { 
      if (pere_actif==1) {
        val=traitement("PERE",'+',"FILS");
        if (val == 0) {
          kill(fils,SIGUSR2);
          pere_actif=0; 
          signal(SIGUSR1,&signal_USR1);
          signal(SIGUSR2,&signal_USR2);
        }
      }
    } while (val >= 0);
    kill(fils,SIGKILL);
  } 
  else {
    printf("FILS getpid=> :%d\n\n",getpid()); 
    do {
      if (fils_actif==1) {
        val=traitement("FILS",'*',"PERE");
        if (val == 0) {
          kill(pere,SIGUSR1);
          fils_actif=0;
          signal(SIGUSR1,&signal_USR1);
          signal(SIGUSR2,&signal_USR2);
        }
      }
    } while (val >= 0);
    kill (pere,SIGKILL);
  }
}
