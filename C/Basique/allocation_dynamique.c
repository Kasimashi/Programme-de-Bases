#include <stdio.h>
#include <stdlib.h>

/*
	sizeof(<donnee>) : retourne la taille en octets d'une donnée
	malloc(<taille_en_octets>) : allouer dynamiquement une zone mémoire
	free(<donnee_allouee>) : libére la moire à la fin du programme
	calloc(<donnee>, <taille_en_octets>) : alloue la mémoire en initialisant à 0
	realloc(<donnee>, <nouvelle taille>) : réalloue un espace mémoire
*/

int main(int argc, char **argv)
{
	int nombreJoueurs =0;
	int *p_liste_joueurs = NULL; //Pointeur vers la liste des joueurs.
	int i;

	printf("Combien de joueurs ?");
	scanf("%d",&nombreJoueurs);

	p_liste_joueurs = malloc(sizeof(int) * nombreJoueurs); //Créer le nombre d'emplacement mémoire demandé par l'utilisateur.
	//p_liste_joueurs = calloc(nombreJoueurs, sizeof(int)); // Idem que la ligne précédente mais initialise toute la zone mémoire à 0.
	
	printf("Adresse de la liste avec le malloc : %p\n", p_liste_joueurs);

	if(p_liste_joueurs == NULL)
	{
		exit(1); //Le programme n'a pas marché en cas d'erreur.
	}

	for(i = 0 ; i < nombreJoueurs ; i++)
	{
		printf("Joueur %d -> numéro %d\n", i+1, i*3);
		p_liste_joueurs[i] = i*3;
	}

	for(i = 0 ; i < nombreJoueurs ; i++)
	{
		printf("[%d]\n", p_liste_joueurs[i]);
	}

	nombreJoueurs = 6;

	p_liste_joueurs = realloc(p_liste_joueurs, nombreJoueurs * sizeof(int)); //Réalloue une nouvelle taille mémoire pour la liste à la même addresse (si possible).

	printf("Adresse de la liste avec le realloc : %p\n", p_liste_joueurs);

	if(p_liste_joueurs == NULL)
	{
		exit(1); //Le programme n'a pas marché en cas d'erreur.
	}

	for(i = 0 ; i < nombreJoueurs ; i++)
	{
		printf("Joueur %d -> numéro %d\n", i+1, i*3);
		p_liste_joueurs[i] = i*3;
	}

	for(i = 0 ; i < nombreJoueurs ; i++)
	{
		printf("[%d]\n", p_liste_joueurs[i]);
	}

	free(p_liste_joueurs); //Libération de la mémoire VIVE RAM
	
	return 0;
}
