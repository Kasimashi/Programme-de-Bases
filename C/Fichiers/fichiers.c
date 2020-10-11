/*

	Ce fichier donne des fonctions capables de lire et écrire dans un fichier

	Pour renommer un fichier :
	rename("Origin", "Destination");
	remove("Origin");

*/

/*
	fopen(<fichier>, <mode_ouverture>); : r(lecture seule qui doit exister)
										  w(écriture seule)
										  a (append : ajout en fin de fichier)
										  r+ (lecture, écriture, le fichier doit exister)
										  w+ (lecture, écriture, supprime le contenu)
										  a+ (ajout lecture écriture, fin de fichier)
	fclose(<fichier>) : fermer le fichier

	[LECTURE]
	fgetc(<fichier>) : Lire un caractère.
	fgets(<chaine>, <taille_chaine>, <fichier>) : lit une ligne
	fscanf(<fichier>, <format> , ...) : lit du texte formaté
	[ECRITURE]
	fputc(<caractère>,<fichier>)	: écrit un caractère
	fputs(<chaine>, <fichier>) 	: écrit une ligne de texte
	fprintf(<fichier>,<format>, ...) : écrit du texte formaté.
	[POSITIONNEMENT]
	ftell(<fichier>) : retourne la position du curseur dans le fichier.
	fseek(<fichier>, <deplacement> <origine>) : Déplacement du curseur
												SEEK_SET(début du fichier)
												SEEK_CUR(Position courante)
												SEEK_END(Fin de fichier)
	rewind(<fichier>) : réinitialise la position du curseur.
*/

#include <stdio.h> //Directives de préprocesseur.
#include <string.h>
#include <stdlib.h>

void LectureLettreParLettre1(FILE *fichier)
{
	char lettre;
	while(1) //Boucle infinie
	{
		lettre = fgetc(fichier);//lecture lettre par lettre

		if(feof(fichier)){
			break;
		}

		printf("%c", lettre);
	}
}

void LectureLettreParLettre2(FILE *fichier)
{
	char lettre;
	while((lettre = fgetc(fichier)) != EOF)
	{
		printf("%c", lettre);
	}
}
void LectureLigneParLigne(FILE *fichier)
{
	char texte[256]; //255 + \0
	while(fgets(texte,255,fichier) != NULL)
	{
		printf("%s\n", texte);
	}
}

void LectureElementParElement(FILE *fichier)
{
	/* Récupération élément par élément : */
	char mot1[20];
	char mot2[20];
	char mot3[20];
	fscanf(fichier,"%s %s %s", mot1, mot2, mot3);
	printf("mot1: %s mot2:%s mot3:%s\n",mot1, mot2, mot3);
}
int main(int argc, char **argv)
{

	FILE *fichier = fopen("Coucou.data","r");//File est une structure
	
	if (fichier == NULL)//Si le fichier n'existe pas alors quitter le programme
	{
		printf("Attention le fichier n'existe pas !\n");
		exit(1);
	}

	LectureLettreParLettre1(fichier);
	fseek(fichier,0, SEEK_SET); //déplacement de 0 à partir du début du fichier
	rewind(fichier); //Idem que la fonction d'avant

	LectureLettreParLettre2(fichier);
	fseek(fichier,0, SEEK_SET); //déplacement de 0 à partir du début du fichier

	LectureLigneParLigne(fichier);
	fseek(fichier,0, SEEK_SET); //déplacement de 0 à partir du début du fichier

	LectureElementParElement(fichier);
	printf("Position du curseur à la fin de la lecture : %d\n",ftell(fichier));

	fclose(fichier);
	return 0;
}
