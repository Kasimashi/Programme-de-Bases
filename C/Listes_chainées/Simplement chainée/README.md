Etape pour ajouter un noeud à une position donnée 'n' :
 - Créer un nouvelle élément
 
![newNode](https://codeforwin.org/wp-content/uploads/2015/09/insertion-of-node-at-middle-of-singly-linked-list1.png)

 - Traversez jusqu’à la n-1 ème position de la liste liée et connectez le nouveau nœud avec le n+1 ème nœud. Cela signifie que le nouveau nœud doit aussi pointer vers le même nœud que le nœud n-1th. (newNode->next = temp->next où temp est le nœud n-1th).
 
![InsertNewNode](https://codeforwin.org/wp-content/uploads/2015/09/insertion-of-node-at-middle-of-singly-linked-list2.png)
 
 - Enfin, connectez le nœud n-1 ème avec le nouveau nœud, c’est-à-dire que le nœud n-1 ème pointera maintenant vers le nouveau nœud. (temp->next = newNode où temp est le nœud n-1 ème).
 
![InsertNewNode](https://codeforwin.org/wp-content/uploads/2015/09/insertion-of-node-at-middle-of-singly-linked-list3.png)

Références :
https://www.codeheroes.fr/2021/01/04/reussir-son-entretien-technique-les-listes-chainees/
