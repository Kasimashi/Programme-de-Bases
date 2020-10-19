/*
Ecrire un programme permettant de copier un fichier caractère par caractère.

Les noms des fichiers, source et destination, sont passés en argument sur la ligne de commande.

Par exemple :

  vagrant@precise32:~$ ./copie source.txt destination.txt

 

Penser à utilise la commande « ls –al » pour bien vérifier votre résultat !
*/


#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {
  FILE *fpIn, *fpOut;
  char c;
  if (argc!=3) {
    printf("Erreur, nombre d'arguments incorrect...\n"); exit(1);      
  }  
  if ( (fpIn = fopen(argv[1], "r")) == NULL) {
    printf("Erreur avec le fichier source...\n"); exit(1);    
  }  
  if ( (fpOut = fopen(argv[2], "w")) == NULL) {
    printf("Erreur avec le fichier destination...\n"); exit(1);
  }
  while (c != EOF) {
    c = getc(fpIn);          
    if (c != EOF) putc(c, fpOut);     
  } 
  fclose(fpOut);
  fclose(fpIn);   
  exit(0);
}

