#ifndef H_LISTE_CHAINEE
#define H_LISTE_CHAINEE

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

#endif

