/*
Un nombre premier est un nombre divisible par 1 et par lui-même (Particularités : 0 et 1 ne sont pas premiers)

Algorithme naïf : pour tester un nombre N, on vérifie s'il est divisible par l'un des entiers compris entre 2 et (bornes comprises) √N. Si la réponse est négative, alors N est premier, sinon il est composé.

int primeTest(int n) {

  int i = 0;

  int s = ceil(sqrt((float)n));

  if (n<=1) return(0); // gestion de l'exception pour 1 et 0

  else if (n==2) return(1); // gestion de l'exception pour 2

  else {

    for(i=2; i<=s; i++) {

      if ((n%i)==0) return(0); // test si i divise n   

    }

    return(1);

  } 

} 

"à compiler avec l’option –lm"

Afficher les nombres premiers inférieurs à 100 en parallélisant l’algorithme dans deux processus distincts.

Utiliser la fonction fork pour obtenir deux processus se déroulant en parallèle :

1) Le processus père recherche les nombres premiers entre 1 et N/2

2) Le processus fils recherche les nombres premiers entre N/2 et N

Utiliser un tube de communication (pipe) pour transmettre du fils au père le nombre de nombres premiers trouvé.

Afficher dans le père (une fois que le fils a terminé) le nombre total de nombre premiers.
*/


#include <unistd.h>
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#define N 100

int primeTest(int n) {
  int i = 0;
  int s = ceil(sqrt((float)n));
  if (n<=1) return(0); // gestion de l'exception pour 1 et 0
  else if (n==2) return(1); // gestion de l'exception pour 2
  else {
    for(i=2; i<=s; i++) {
      if ((n%i)==0) return(0); // test si i divise n
    
    }
    return(1);
  }  
} 

int main(){
  int i;
  pid_t pidFork;
  int cpt1 = 0,cpt2 = 0;
  int tub[2];
  pipe(tub);
  pidFork = fork();
  if (pidFork != 0) {
    for (i=1;i<N/2;i++) {
      if (primeTest(i)==1) {
        printf("%d\n",i);
        cpt1++;
      }
   }
   read(tub[0],&cpt2,sizeof(int));
   printf("%d nombre premiers trouvés\n",cpt1+cpt2);
   wait(NULL);
  } else {
    for (i=N/2;i<=N;i++) {
      if (primeTest(i)==1) {
        printf("%d\n",i);
        cpt2++;
      }
    }
    write(tub[1],&cpt2,sizeof(int));
  }
  exit(0);
}
