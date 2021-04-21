/* Directive de préprocesseur */

#include <stdio.h>
#include <stdlib.h>

/* Fin des Directive de préprocesseur */


/* Fonction principale */
int main(int argc, char *argv[])
{

	int argent = 2;
	unsigned char autorisation = 0;
    const int NOMBRE_CONSTANT = 5; //Déclaration d'une constante cette valeure est fixe et ne peut être modifié.
    printf("Valeur de la constance avant : %d\n", NOMBRE_CONSTANT);
    int int32_a = 3; //Déclaration d'un nombre sur 32 bits
    printf("Déclaration d'une variable sur 32 bits : %d\n",int32_a);
    
    int age = 0;
    printf("Quel age avez-vous ? ");
	scanf("%d", &age); // On demande d'entrer l'âge avec scanf
	printf("Ah ! Vous avez donc %d ans et votre variable habite ici : %X!\n\n", age,&age);

	if (age >= 18) // Si l'âge est supérieur ou égal à 18
	{
	  printf ("Vous etes majeur !");
	}
	else // Sinon...
	{
	  printf ("Ah c'est bete, vous etes mineur !");
	}

	if (age > 30 || argent > 100000)
	{
	    printf("Bienvenue chez PicsouBanque !");
	}
	else
	{
	    printf("Hors de ma vue, miserable !");
	}

	switch (age)
	{
	case 2:
	  printf("Salut bebe !");
	  break;
	case 6:
	  printf("Salut gamin !");
	  break;
	default:
	  printf("Je n'ai aucune phrase de prete pour ton age  ");
	  break;
	}

	autorisation = (age >= 18) ? 1 : 0;

	int nombreEntre = 0;

	while (nombreEntre != 47)
	{
	    printf("Tapez le nombre 47 ! ");
	    scanf("%d", &nombreEntre);
	}

	int compteur = 0;

	while (compteur < 10)
	{
	    printf("Salut les Zeros !\n");
	    compteur++;
	}

	compteur = 0;

	do
	{
	    printf("Salut les Zeros !\n");
	    compteur++;
	} while (compteur < 10);

	return 0;
}

int addition(int a, int b)
{
    return a + b;
}

int triple(int nombre)
{
    return nombre * 3;       // On retourne la variable resultat qui vaut le triple de nombre
}
