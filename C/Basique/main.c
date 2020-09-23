#include <stdio.h> //Directive de préprocesseur

/*
	Déclaration d'une variable utilisateur (variable globale)
*/
#define MAVARIABLE 0 
#define HOMME 'M'
#define FEMME 'F'

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
	uint8 Genre;
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
		printf("Give him a bottle of rum!\n");
		estMajeur = TRUE;
	}
	return estMajeur;
}
/* Cette fonction permet de connaitre le sexe de la personne */

error_t AfficherGenre(Personne p)
{
	error_t u32_cr = PROJET_CR_OK;
	switch (p.Genre)
	{
		case HOMME:
			printf("C'est un homme !\r\n");
			break;
		case FEMME:
			printf("C'est une femme !\r\n");
			break;
		default:
			printf("C'est un OVNI ... le genre donnée est incorrect\r\n");
			u32_cr = PROJET_CR_ERREUR_PARAMETRE;
			break;
	}
	return u32_cr;
}

/* Cette fonction permet d'avoir des informations sur la personne */
error_t Informations(Personne p)
{

	error_t u32_cr = PROJET_CR_OK;

	u32_cr = estMajeur(p.age);
	u32_cr = AfficherGenre(p);


	/* Vérification des erreurs */

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

/* Fonction principale du programme ... */

int main(int argc, char **argv)
{
	Personne P1; //Déclaration de la structure Personne 1

	//Information à propos de cette personne.
	P1.age = 15;
	P1.Genre = 'P';

	printf("La personne se nomme : %s\r\n",P1.Prenom);
	printf("La personne a %d ans.\r\n",P1.age);

	Informations(P1);

	return 0; //Retour de la fonction
}


