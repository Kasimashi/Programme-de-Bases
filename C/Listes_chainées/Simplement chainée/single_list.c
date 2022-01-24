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
void insertHead(s_list *list, int nvNumber);
void insertTail(s_list *list, int nvNumber);
void insertNodeAtPos(s_list *list, int data, int position);
void deleteHead(s_list *list);
void deleteTail(s_list *list);
void bubbleSortList(s_list *list);
void deleteList(s_list *list);
void printList(s_list *list);
int findElement(s_list *list, int element);
int listLength(s_list *list);

/*Les fonctions qui vont manipuler la liste chaînée. En effet, on ne va pas modifier « à la main » le contenu des structures à chaque fois qu'on en a besoin ! Il est plus sage et plus propre de passer par des fonctions qui automatisent le travail. Encore faut-il les créer.

On pourrait créer d'autres fonctions (par exemple pour calculer la taille de la liste) mais elles sont moins indispensables. Nous allons ici nous concentrer sur celles que je viens de vous énumérer, ce qui nous fera déjà une bonne base. Je vous inviterai ensuite à réaliser d'autres fonctions pour vous entraîner une fois que vous aurez bien compris le principe.
*/

s_list *initList();

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


    insertTail(myList, temp=6);
    printf("Insert element in the list (Tail) : %d\n",temp);
    insertTail(myList, temp=10);
    printf("Insert element in the list (Tail): %d\n",temp);
    insertNodeAtPos(myList,temp=1,pos=1);
    printf("Insert element in the list : %d at pos %d\n",temp,pos);
    insertTail(myList, temp=8);
    printf("Insert element in the list (Tail) : %d\n",temp);
    insertTail(myList, temp=9);
    printf("Insert element in the list (Tail): %d\n",temp);
    insertTail(myList, temp=10);
    printf("Insert element in the list (Tail): %d\n",temp);
    insertHead(myList, temp=2);
    printf("Insert element in the list (Head): %d\n",temp);

    printList(myList);

    printf("Size of the list : %d elements\n",listLength(myList));

    deleteHead(myList);

    printList(myList);

    deleteTail(myList);

    printList(myList);

    /* print list before sorting */
   printf("Linked list before sorting ");
   printList(myList);

   /* sort the linked list */
   bubbleSortList(myList);

   /* print list after sorting */
   printf("Linked list after sorting ");
   printList(myList);

   int element = 6;
   int index = -1;
   index = findElement(myList,element);
   if ( index != -1){
	   printf("Element %d find at index %d (Start from 0)\n", element, index);
   }
   else
   {
	   printf("Element %d not found in the list\n", element);
   }


   deleteList(myList);
   printf("List deleted");
  
	return 0;
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
    element->next = NULL;

    /* Pointe le premier élément de la liste vers le premier élément */
    list->first = element;

    return list;
}

/*
 * Insère un élément en début de liste
 */
void insertHead(s_list *list, int nvNumber)
{
    /* Création du nouvel élément */
	s_elem *new = malloc(sizeof(*new));
    if (list == NULL || new == NULL)
    {
    	printf("Empty list or Unable to allocate memory.");
        exit(EXIT_FAILURE);
    }
    new->number = nvNumber;

    /* Insertion de l'élément au début de la liste */
    new->next = list->first;
    list->first = new;
}

/*
 * Insère un élément en fin de liste
 */
void insertTail(s_list *list, int nvNumber)
{
    /* Création du nouvel élément */
	s_elem *new = malloc(sizeof(*new));
    if (list == NULL || new == NULL)
    {
    	printf("Empty list or Unable to allocate memory.");
        exit(EXIT_FAILURE);
    }
    /* On met le nombre dans l'élément */
    new->number = nvNumber;

    new->next = NULL;
    {
    	s_elem *current = list->first;
    	while(current->next != NULL)
    	{
    		current = current->next;
    	}
    	current->next = new;
    }
}

/*
 * Creates a new node and inserts at middle of the linked list.
 */
void insertNodeAtPos(s_list *list, int data, int position)
{
    int i;
    s_elem *newElement, *temp;

    newElement = malloc(sizeof(*newElement));

    if(newElement == NULL)
    {
    	printf("Unable to allocate memory.");
    	exit(EXIT_FAILURE);
    }
    else
    {
    	newElement->number = data; // Link data part
    	newElement->next = NULL;

        temp = list->first;

        /*
         * Traverse to the n-1 position
         */
        for(i=2; i<=position-1; i++)
        {
            temp = temp->next;

            if(temp == NULL)
                break;
        }

        if(temp != NULL)
        {
            /* Link address part of new node */
        	newElement->next = temp->next;

            /* Link address part of n-1 node */
            temp->next = newElement;
        }
    }
}

/*
 * Supprime un élément en fin de liste
 */
void deleteTail(s_list *list)
{
	/* Vérification de la liste vide */
    if (list == NULL)
    {
    	printf("Empty list");
        exit(EXIT_FAILURE);
    }

    /* On vérifie que la liste a plus d'un élément */
    if (list->first != NULL)
    {
    	/* On met le pointeur sur le premier élément de la liste */
    	s_elem *todelete = list->first;
    	/* Tant qu'on atteint pas l'avant dernier élément */
    	while (todelete->next->next != NULL)
    	{
    		/* on passe à l'élément suivant*/
			todelete = todelete->next;
    	}

    	/* On est à l'avant dernier élément : le prochain élément devient NULL */
    	todelete->next = NULL;

    	/* On passe à l'élément suivant et on le supprime */
    	todelete = todelete->next;
        free(todelete);
    }
}

/*
 * Supprime un élément en début de liste
 */
void deleteHead(s_list *list)
{
    if (list == NULL)
    {
    	printf("Empty list");
        exit(EXIT_FAILURE);
    }

    if (list->first != NULL)
    {
    	s_elem *todelete = list->first;
        list->first = list->first->next;
        free(todelete);
    }
}

/* function to swap data of two nodes a and b*/
void swapElement(s_elem *a, s_elem *b)
{
    int temp = a->number;
    a->number = b->number;
    b->number = temp;
}

/*
 * Fonction pour inverser deux listes
 * */
void bubbleSortList(s_list *list)
{
	int swapped, i;
	s_elem *ptr1;
	s_elem *lptr = NULL;

	/* On vérifie que la liste n'est pas vide */
	if (list == NULL)
	{
		printf("Empty list");
		exit(EXIT_FAILURE);
	}

	do
	{
		swapped = 0;
		ptr1 = list->first;

		while (ptr1->next != lptr)
		{
			if ((ptr1->number) > (ptr1->next->number))
			{
				swapElement(ptr1, ptr1->next);
				swapped = 1;
			}
			ptr1 = ptr1->next;
		}
		lptr = ptr1;
	}
	while (swapped);
}

/*
 * Supprime toute la liste
 */
void deleteList(s_list *list)
{
	/* deref head_ref to get the real head */
	s_elem *current = list->first;
	s_elem *next;

   while (current != NULL)
   {
	   next = current->next;
	   free(current);
	   current = next;
   }

   /* deref head_ref to affect the real head back
	  in the caller. */
   list->first = NULL;
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

/**
 * @fn int findElement(s_list*, int)
 * @brief Cherche par dichotomie un élément dans la liste et renvoi l'index de l'élément : renvoi l'index ou -1 si non trouvé.
 *
 * @param list
 * @param element
 */
int findElement(s_list *list, int element)
{
	int i=0;
	s_elem *current = list->first;
	int a = 0;
	//Except NULL
	int b = listLength(list) - 1;
	int m = 0;

	while (a<=b)
	{
		m = (a+b)/2;

		/* Parcours de la liste par pointeur : la dichotomie n'est pas adapté au liste chainée mais c'est pour exemple : on pourrait simplement parcourir la liste à la recherche de l'élément */
		do{
			current = current->next;
			i++;
		}while(i<m);
		/* Remise à 0 du compteur */
		i=0;


		printf("Number %d at index %d\n",current->number,m);
		if (current->number == element){
			return m;
		}
		else if (current->number < element){
			a = m + 1;
		}
		else{
			b = m - 1;
		}

		/* Retour au premier élément */
		current = list->first;

	}
	/* Not found */
	return -1;
}
/*
 * Calcul la taille de la liste
*/
int listLength(s_list *list)
{
  s_elem* current = list->first;
  int size = 0;

  while (current != NULL)
  {
    ++size;
    current = current->next;
  }

  return size;
}
