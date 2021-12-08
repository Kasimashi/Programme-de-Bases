#include <stdio.h>
#include <stdlib.h>

/* Un élément de la liste chainée*/
typedef struct Element s_elem;
struct Element
{
/*
    Une donnée, ici un nombre de typeint: on pourrait remplacer cela par n'importe quelle autre donnée (undouble, un tableau…). Cela correspond à ce que vous voulez stocker, c'est à v vous de l'adapter en fonction des besoins de votre programme.
Si on veut travailler de manière générique, l'idéal est de faire un pointeur sur void :void*. Cela permet de faire pointer vers n'importe quel type de données.
    */
    int number;
    /*
    Un pointeur vers un élément du même type appelé suivant. C'est ce qui permet de lier les éléments les uns aux autres : chaque élément « sait » où se trouve l'élément suivant en mémoire. Comme je vous le disais plus tôt, les cases ne sont pas côte à côte en mémoire. C'est la grosse différence par rapport aux tableaux. Cela offre davantage de souplesse car on peut plus facilement ajouter de nouvelles cases par la suite au besoin.
    En revanche, il ne sait pas quel est l'élément précédent, il est donc impossible de revenir en arrière à partir d'un élément avec ce type de liste. On parle de liste « simplement chaînée », alors que les listes « doublement chaînées » ont des pointeurs dans les deux sens et n'ont pas ce défaut. Elles sont néanmoins plus complexes.
    Pour le dernier élement de la liste indiquer la valeur "NULL"
    */
    s_elem *next;
};

/* La structure de contrôle : qui contrôle l'ensemble de la liste. Nous n'en aurons besoin qu'en un seul exemplaire.
En plus de la structure qu'on vient de créer (que l'on dupliquera autant de fois qu'il y a d'éléments), nous allons avoir besoin d'une autre structure pour contrôler l'ensemble de la liste chaînée. Elle aura la forme suivante :
*/
typedef struct
{
/* indique ou commence la liste */
	s_elem *first;
} s_list;

s_list *initList();

/*Les fonctions qui vont manipuler la liste chaînée. En effet, on ne va pas modifier « à la main » le contenu des structures à chaque fois qu'on en a besoin ! Il est plus sage et plus propre de passer par des fonctions qui automatisent le travail. Encore faut-il les créer.

On pourrait créer d'autres fonctions (par exemple pour calculer la taille de la liste) mais elles sont moins indispensables. Nous allons ici nous concentrer sur celles que je viens de vous énumérer, ce qui nous fera déjà une bonne base. Je vous inviterai ensuite à réaliser d'autres fonctions pour vous entraîner une fois que vous aurez bien compris le principe.
*/

s_list *initList();
void printList(s_list *list);

/*
 * Ce programme manipule une liste chainée mais rajoute/supprime à chaques fois l'élément en début de liste
 */
int main(int argc, char **argv)
{
    int temp,pos,sizeList;

	printf("Creating of the list : ");
	/* Constructor */
	s_list *myList = initList();

	printList(myList);
}

/*
 * Initialisation de la liste
 * */
s_list *initList()
{
	/* Création de la liste chainée */
	s_list *list = malloc(sizeof(*list));

    /*Création du premier élément qui vaut 0*/
	s_elem *element = malloc(sizeof(*element));

    if (list == NULL || element == NULL)
    {
    	printf("Empty list or Unable to allocate memory.");
        exit(EXIT_FAILURE);
    }

    element->number = 0;
    /* Pointe vers le dernier élément de la liste */
    element->next = element;

    /* Pointe le premier élément de la liste vers le premier élément */
    list->first = element;

    return list;
}

/*
 * Affiche sa liste en intégralité
 */
void printList(s_list *list)
{
    if (list == NULL)
    {
    	printf("Empty list");
        exit(EXIT_FAILURE);
    }

    s_elem *current = list->first;

    while (current != NULL)
    {
        printf("%d -> ", current->number);
        current = current->next;
    }
    printf("NULL\n");
}
