/*Ecrire un programme permettant de calculer la surface d’un rectangle.

Les données (en millimètres) sont des entiers. Elles sont passées en argument sur la ligne de commande.

Par exemple :

  vagrant@precise32:~$ ./surface 120 45
 */
 
 #include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {
  int hauteur=0, largeur=0;
  if (argc!=3 ) {
    printf("Erreur, nombre d'arguments incorrect...\n"); exit(1);
  }  
  hauteur = atoi(argv[1]);
  largeur = atoi(argv[2]);  
  if ((hauteur==0) || (largeur==0)) {
    printf("Erreur, une dimension est nulle...\n"); exit(1);    
  }
  printf("La surface vaut %d\n", hauteur*largeur);
  exit(0);
}