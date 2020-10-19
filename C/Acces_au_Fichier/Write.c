/*
Ecrire un programme qui affiche, en utilisant la fonction write(…) sur la sortie standard, le message : « exercice 1 accompli ! »
*/


#include <stdio.h>
#include <string.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <sys/uio.h>
#include <limits.h>
#include <unistd.h>

int main() {
  int fd = 1;
  char *message = "exercice 1 accompli !\n";
  write(fd, message, strlen(message));
}
