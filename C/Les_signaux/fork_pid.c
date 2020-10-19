/*
L'objectif est d'avoir deux processus, père et fils, exécutant chacun une session particulière.

La session consiste ici à entrer deux valeurs entières et à obtenir un résultat : addition ou multiplication des deux valeurs entrées selon que c'est la session père ou fille qui est active.

Le passage d'une session à l'autre s'effectue ici en donnant la valeur 0 comme première valeur. Les deux sessions prennent fin lorsqu'on fournit une valeur négative comme première donnée.

 On considère la fonction de traitement ci-dessous :

int traitement (char *identite, char operation, char *correspondant) {

int val1,val2;

  printf("%s=>Entrez 2 valeurs > 0 pour une ",identite);

  if (operation == '+') printf("addition;\n");

  else printf("multiplication;\n");

  printf("%s=>Entrez 0 pour passer a la session %s;\n",identite,correspondant);

  printf("%s=>Entrez une valeur negative pour terminer.\n",identite);

  scanf("%d",&val1);

  if (val1 == 0) return (0);

  if (val1 < 0) return (-1);

  scanf("%d",&val2);

  if (operation == '+')

     printf("%s=>Resultat : %d\n",identite,val1+val2);

  else

     printf("%s=>Resultat : %d\n",identite,val1*val2);

  return(val1);

 }

En utilisant fork() et getpid(), écrire le programme principal pour qu'il se divise en deux processus :

le père fera appel au traitement ci-dessus avec val=traitement("PERE",'+',"FILS");
et le fils avec val=traitement("FILS",'*',"PERE");
*/
#include <sys/types.h>
#include <unistd.h>
#include <signal.h>
#include <stdio.h>

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
  int val = 1;
  pid_t pere, fils;
  pere = getpid();
  fils = fork();
  if (fils != 0) {
    printf("PERE getpid=> :%d\n\n",getpid());
    val=traitement("PERE",'+',"FILS"); 
  } 
  else {
    printf("FILS getpid=> :%d\n\n",getpid());
    val=traitement("FILS",'*',"PERE");
  }
}
