/* Tutoriel de référence : https://openclassrooms.com/fr/courses/19980-apprenez-a-programmer-en-c/19733-les-listes-chainees */

#include <stdio.h>
#include <stdlib.h>

/* Un élément de la liste chainée*/
typedef struct Element Element;
struct Element
{
/*
    Une donnée, ici un nombre de typeint: on pourrait remplacer cela par n'importe quelle autre donnée (undouble, un tableau…). Cela correspond à ce que vous voulez stocker, c'est à v vous de l'adapter en fonction des besoins de votre programme.
Si on veut travailler de manière générique, l'idéal est de faire un pointeur sur void :void*. Cela permet de faire pointer vers n'importe quel type de données.
    */
    int nombre;
    /*
    Un pointeur vers un élément du même type appelé suivant. C'est ce qui permet de lier les éléments les uns aux autres : chaque élément « sait » où se trouve l'élément suivant en mémoire. Comme je vous le disais plus tôt, les cases ne sont pas côte à côte en mémoire. C'est la grosse différence par rapport aux tableaux. Cela offre davantage de souplesse car on peut plus facilement ajouter de nouvelles cases par la suite au besoin.
    En revanche, il ne sait pas quel est l'élément précédent, il est donc impossible de revenir en arrière à partir d'un élément avec ce type de liste. On parle de liste « simplement chaînée », alors que les listes « doublement chaînées » ont des pointeurs dans les deux sens et n'ont pas ce défaut. Elles sont néanmoins plus complexes.
    Pour le dernier élement de la liste indiquer la valeur "NULL"
    */
    Element *suivant;
};

/* La structure de contrôle : qui contrôle l'ensemble de la liste. Nous n'en aurons besoin qu'en un seul exemplaire.
En plus de la structure qu'on vient de créer (que l'on dupliquera autant de fois qu'il y a d'éléments), nous allons avoir besoin d'une autre structure pour contrôler l'ensemble de la liste chaînée. Elle aura la forme suivante :
*/
typedef struct Liste Liste;
struct Liste
{
/* indique ou commence la liste */
    Element *premier;
};

Liste *initialisation();
void insertion(Liste *liste, int nvNombre);
void suppression(Liste *liste);
void afficherListe(Liste *liste);

/*Les fonctions qui vont manipuler la liste chaînée. En effet, on ne va pas modifier « à la main » le contenu des structures à chaque fois qu'on en a besoin ! Il est plus sage et plus propre de passer par des fonctions qui automatisent le travail. Encore faut-il les créer.

À première vue, je dirais qu'on aura besoin de fonctions pour :

- initialiser la liste ;

- ajouter un élément ;

- supprimer un élément ;

- afficher le contenu de la liste ;

- supprimer la liste entière.

On pourrait créer d'autres fonctions (par exemple pour calculer la taille de la liste) mais elles sont moins indispensables. Nous allons ici nous concentrer sur celles que je viens de vous énumérer, ce qui nous fera déjà une bonne base. Je vous inviterai ensuite à réaliser d'autres fonctions pour vous entraîner une fois que vous aurez bien compris le principe.
*/

Liste *initialisation();

/*
 * Ce programme manipule une liste chainée mais rajoute/supprime à chaques fois l'élément en début de liste
 */
int main(int argc, char **argv)
{
    
    Liste *maListe = initialisation();

    insertion(maListe, 4);
    insertion(maListe, 8);
    insertion(maListe, 15);
    suppression(maListe);

    afficherListe(maListe);

    
    
	return 0;
}

/* Initialisation de la liste */
Liste *initialisation()
{
    Liste *liste = malloc(sizeof(*liste));
    Element *element = malloc(sizeof(*element));

    if (liste == NULL || element == NULL)
    {
        exit(EXIT_FAILURE);
    }

    element->nombre = 0;
    element->suivant = NULL;
    liste->premier = element;

    return liste;
}

void insertion(Liste *liste, int nvNombre)
{
    /* Création du nouvel élément */
    Element *nouveau = malloc(sizeof(*nouveau));
    if (liste == NULL || nouveau == NULL)
    {
        exit(EXIT_FAILURE);
    }
    nouveau->nombre = nvNombre;

    /* Insertion de l'élément au début de la liste */
    nouveau->suivant = liste->premier;
    liste->premier = nouveau;
}

void suppression(Liste *liste)
{
    if (liste == NULL)
    {
        exit(EXIT_FAILURE);
    }

    if (liste->premier != NULL)
    {
        Element *aSupprimer = liste->premier;
        liste->premier = liste->premier->suivant;
        free(aSupprimer);
    }
}

void afficherListe(Liste *liste)
{
    if (liste == NULL)
    {
        exit(EXIT_FAILURE);
    }

    Element *actuel = liste->premier;

    while (actuel != NULL)
    {
        printf("%d -> ", actuel->nombre);
        actuel = actuel->suivant;
    }
    printf("NULL\n");
}
