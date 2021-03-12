#include <stdio.h>

void triplePointeur(int *pointeurSurNombre);

int main(int argc, char *argv[])
{
    int nombre = 5;
    triplePointeur(&nombre); // On envoie l'adresse de nombre à la fonction
    printf("nombre *3 = %d\n", nombre); // On affiche la variable nombre. La fonction a directement modifié la valeur de la variable car elle connaissait son adresse

    int *pointeur = &nombre; // pointeur prend l'adresse de nombre
    triplePointeur(pointeur); // On envoie pointeur (l'adresse de nombre) à la fonction
    printf("nombre *3 = %d\n", *pointeur); // On affiche la valeur de nombre avec *pointeur

    return 0;
}

void triplePointeur(int *pointeurSurNombre)
{
    *pointeurSurNombre *= 3; // On multiplie par 3 la valeur de nombre
}
