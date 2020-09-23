#include <stdio.h> //Directive de préprocesseur

/*
	Déclaration d'une variable utilisateur (variable globale)
*/
#define MAVARIABLE 0 

/* 
	Définition des codes d'erreurs de retour
*/

#define ERREUR_PARAMETRE 0x01

#define PROJET_CR_OK	0x00
#define PROJET_CR_ERREUR_PARAMETRE	(PROJET_CR_OK || ERREUR_PARAMETRE)

/* 
	Déclaration des types de variables personalisées 
*/
typedef unsigned int error_t;  // Variable de code retour d'une fonction
typedef unsigned char uint8; // Variable d'un octet de type char
typedef unsigned short uint16; //Variable de deux octet de type short
typedef unsigned int uint32; //Variable de quatres octets de type int
typedef unsigned long uint64; //Variable de huit octet de type long


/*
	Déclaration d'une structure permettant de déclarer le type bool : Non implémenté de base dans le langage C
*/
typedef enum
{
	FALSE=0,
	TRUE
}Bool;

/* Le langage C n'est pas un langage orienté objet ! en échange on peut utiliser des structures pour les données ! */

typedef struct
{
	uint8 age;
	char Prenom[20];
	uint8 Sexe;
}Personne;


/* Cette fonction ne sert à rien elle permet juste de montrer comment déclarer une variable suivant son type en langage C */
void variable(void)
{
	/*
	 * Ceci est un commentaire
	 */
	char int8_mavariable;//sur 1 octet
	short int16_mavariable;//sur 2 octet
	int int32_mavariable; // sur 4 octets
	long int64_mavariable;// sur 8 octet

	/* Pour les variables non signées (positive)*/

	unsigned char uint8_mavariable;// sur 1 octet
	unsigned short uint16_mavariable;// sur 2 octet
	unsigned int uint32_mavariable;// sur 4 octet
	unsigned long uint64_mavariable;// sur 8 octet

	/* Variable à virgule */
	float f_mavariable; // sur 4 octet
	double d_mavariable; //sur 8 octet
}

/*
	Cette fonction permet de vérifier si une personne est majeure ou mineurs
*/
int estMajeur(int majeur)
{
	Bool estMajeur;
	if (majeur <18)
	{
		printf("L'individu est mineur !\r\n");
		estMajeur = FALSE;
	}
	else
	{
		printf("L'individu est majeur !\r\n");
		estMajeur = TRUE;
	}
	return estMajeur;
}

error_t maFonction(int majeur)
{

	error_t u32_cr = PROJET_CR_OK;

	if (estMajeur(majeur))
	{
		u32_cr = PROJET_CR_ERREUR_PARAMETRE;
	}

	if (u32_cr != PROJET_CR_OK)
	{
		goto traitement_erreur;
	}

	goto fin_fct;

	traitement_erreur:
		printf("Une erreur est survenue ! cr = 0x%08x\n", u32_cr);

	fin_fct:
	return u32_cr;

}

int main(int argc, char **argv)
{
	Personne P1;

	P1.age = 18;
	P1.Sexe = 'M';

	printf("La personne se nomme : %s\r\n",P1.Prenom);
	printf("La personne a %d ans.\r\n",P1.age);

	printf("Give him a bottle of rum!\n");

	maFonction(19);

	return 0; //Retour de la fonction
}


