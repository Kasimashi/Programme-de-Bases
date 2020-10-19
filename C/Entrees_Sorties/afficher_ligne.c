/*
En utilisant les fonction fgets() et fputs(), écrire un programme qui affiche dans le terminal le contenu d’un fichier ligne par ligne, chaque ligne (sauf la dernière) ayant la même longueur. 

Le nom de fichier et la longueur sont passés en argument sur la ligne de commande.

Par exemple :

  vagrant@precise32:~$ ./ligne lorem.txt 20
  */
  
#include <stdio.h>
#include <stdlib.h>

main(int argc, char *argv[]) {
  FILE *fp;
  char *ligne;
  int longueur;
  if (argc!=3 ) {
    printf("Erreur, nombre d'arguments incorrect...\n"); exit(1);
  }  
  if ( (fp = fopen(argv[1], "r")) == NULL) {
    printf("Erreur avec le fichier source...\n"); exit(1);
  }  
  longueur = atoi(argv[2]);
  if ( longueur == 0) {
    printf("Longueur de ligne nulle !\n"); exit(1);
  }
  ligne = malloc(longueur);   
  while (fgets(ligne, longueur, fp) != NULL) {
    fputs(ligne, stdout);
    fputs("\n", stdout); 
  }
  fclose(fp);        
  exit(0);
}
