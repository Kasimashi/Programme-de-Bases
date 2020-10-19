/*
Il est regrettable que le processus père inactif (pere_actif==0) fasse la boucle :

do { if (pere_actif ==1) { //session père
… }
while (val >= 0);  

et consomme inutilement du temps CPU.

Supprimez les variables pere_actif et fils_actif. Utilisez les fonctions systèmes sigpause() et sigignore() pour respectivement attendre la réception du signal souhaité et rester insensible à d'autres signaux.

*/


#include <sys/types.h>
#include <unistd.h>
#include <signal.h>
#include <stdio.h>

void signal_USR1 (int sig) {
  printf("signal %d!\n",sig); 
}

void signal_USR2 (int sig) {
  printf("signal %d!\n",sig);
}

int traitement (char *identite, char operation, char *correspondant) {
  int val1, val2;
  printf("%s=>Entrez 2 valeurs > 0 pour une ", identite);
  if (operation == '+')
    printf("addition;\n");
  else
    printf("multiplication;\n");
  printf("%s=>Entrez 0 pour passer a la session %s;\n", identite, correspondant);
  printf("%s=>Entrez une valeur negative pour terminer.\n", identite);
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
  int val = 0, premiere_fois=1;
  pid_t pere, fils;
  pere = getpid();
  signal(SIGUSR1,&signal_USR1);
  signal(SIGUSR2,&signal_USR2);
  fils = fork();
  if (fils != 0) {
    printf("PERE getpid=> :%d\n\n",getpid()); 
    do { 
      val=traitement("PERE",'+',"FILS");
      if (val == 0) {
        kill(fils,SIGUSR2);
        signal(SIGUSR1,&signal_USR1);
        sigignore(SIGUSR2);
        sigpause(SIGUSR1);
        }               
    } while (val >= 0);
    kill(fils,SIGKILL);
  } 
  else {
    printf("FILS getpid=> :%d\n\n",getpid()); 
    do {
      if (premiere_fois == 1) {
        premiere_fois=0;
        sigpause(SIGUSR2);
      }
      val=traitement("FILS",'*',"PERE");
      if (val == 0) {
        kill(pere,SIGUSR1);
        sigignore(SIGUSR1);
        signal(SIGUSR2,&signal_USR2);
        sigpause (SIGUSR2);
      } 
    } while (val >= 0);
    kill (pere,SIGKILL);
  }
}
