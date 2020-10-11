#include <stdio.h>
#include <math.h>
#define SIZEOFTAB 5

int number_length(char b[], int lb);
char addition(unsigned char a[], int la, unsigned char b[], int lb);

typedef enum
{
	FALSE=0,
	TRUE
}Bool;

int main(int argc, char **argv)
{
	unsigned int nombre = 0;
	unsigned int *pnombre = &nombre;

	char tableau_test[3] = {23,44,11};
	char tableau[SIZEOFTAB] = {0};

	//int *tableau = NULL; //Pointeur vers la liste des joueurs.
	printf("Entrer le nombre : ");
	scanf("%d", &nombre);

	//tableau = calloc(nombreJoueurs, sizeof(int)); // Idem que la ligne précédente mais initialise toute la zone mémoire à 0.
	int i=SIZEOFTAB;
	printf("Le nombre est stocké à l'addresse : %p et sa valeur est : %02d\n", &nombre, *pnombre);

	/*
		Lecture de chaques dizaines du chiffre rentré
	*/
	while(nombre > 0)
	{	
		int temp = nombre % 100;
		//printf("%02d\n",temp);
		tableau[i-1] = temp;
		nombre = nombre / 100; 
		i--;
	}

	for (int i=0;i<SIZEOFTAB;i++)
	{
		printf(" %02d ",tableau[i]);
	}

	printf("\n");

	for (int i=0;i<3;i++)
	{
		printf(" %02d ",tableau_test[i]);
	}

	printf("\n");

	int number_l = number_length(tableau,SIZEOFTAB);

	printf("Number length : %d\n",number_l);

	char retenue = addition(tableau,SIZEOFTAB, tableau_test,3);

	printf("Retenue : %d\n",retenue);

	printf("\n");

	for (int i=0;i<SIZEOFTAB;i++)
	{
		printf(" %02d ",tableau[i]);
	}

	printf("\n");


	return 0;
}

int number_length(char b[], int lb)
{
	int i=0;
	while(b[i]==0)
	{
		printf("Un paquet de deux !\n");
		i++;
	}
	return lb-i;
}

char addition(unsigned char a[], int la, unsigned char b[], int lb)
{
	Bool retenue = FALSE;
	/*
		On vérifie que le tableau a est plus grand que b
	*/
	if (la < number_length(b,lb))
	{
		return -1;
	}

	for (int i=la;i>0;i--)
	{
		char resultat=0;

		resultat = (a[i] + b[i]);

		if (retenue)
		{
			resultat++;
		}

		if (resultat>100)
		{
			retenue = TRUE;
		}
		else
		{
			retenue = FALSE;
		}

		a[i]= resultat;
		printf("Résulat addition pour %d :%d\n",i,a[i]);
	}

	return retenue;
}