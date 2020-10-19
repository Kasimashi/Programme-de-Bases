/*
Ecrire un programme qui imprime le nom du répertoire courant.
*/

#include <stdio.h>
#include <stdlib.h>

main() {  
  char *chaine; int val;
  chaine = getenv("PWD");
  if (chaine != NULL) {
    printf("Dossier courant : %s\n",chaine);     
  } 
}

/*

#include <stdio.h>
#include <stdlib.h>

main() {  
  char *chaine; int val;
  chaine = getenv("PWD");
  if (chaine != NULL) {
    printf("Dossier courant : %s\n",chaine);     
  }
  setenv("PWD", "/vagrant", 1);  
  chaine = getenv("PWD");
  printf("Dossier courant : %s\n",chaine); 
}

/*
La valeur de la variable PWD est bien changée dans le programme.
Mais si on tape la commande « env » on retrouve la valeur initiale de PWD !
La modification n’est visible que dans le processus où elle a été faite…
*/