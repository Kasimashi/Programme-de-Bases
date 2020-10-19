/*
Ecrire un programme utilisant la fonction fork() et les pipes réalisant le traitement suivant :

1 ⇒ Le processus fils calcule un nombre aléatoire
2 ⇒ Le fils envoie ce nombre au père
3 ⇒ Le père détermine si le nombre reçu est pair ou impair
4 ⇒ Le père envoie sa réponse au processus fils
*/


#include <sys/types.h>
#include <limits.h>
#include <string.h>
#include <stdio.h>
#include <stdlib.h>

int tubePereFils[2];
int tubeFilsPere[2];

void pere( ) {
  char *chaine = (char*)malloc(80);
  int *valRecue = (int*)malloc(sizeof(int)); 
  read( tubeFilsPere[0], valRecue, sizeof(int) );
  printf("(Père, reçu du fils) : %d\n", *valRecue);
  if( ( *valRecue % 2 ) == 0) {
      strcpy(chaine, "Le nombre est pair !");
  } else {
      strcpy(chaine, "Le nombre est impair !");
  } 
  write( tubePereFils[1], chaine, strlen(chaine) );
  close( tubeFilsPere[0] );
  close( tubePereFils[1] );
  wait(NULL);  
}

void fils( ) {
  char *chaine = (char*)malloc(80);
  int *valEnvoye = (int*)malloc(sizeof(int));
  srand(time(NULL));  
  *valEnvoye = rand();
  printf("nombre : %d\n", *valEnvoye);
  write( tubeFilsPere[1], valEnvoye, sizeof(int) );  
  read( tubePereFils[0], chaine, 21 );
  printf("(Fils, reçu du père) : %s\n", chaine);
  close( tubePereFils[0] );
  close( tubeFilsPere[1] );
  exit(0);
}

void main() {
  pid_t pid;
  int i;
  pipe(tubePereFils);
  pipe(tubeFilsPere);
  pid=fork();
  if (pid == 0) {
    fils();
  } else {
    pere();  
  }
} 
