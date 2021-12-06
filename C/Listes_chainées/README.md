# Les listes chainées

Kezako ?!
Pour stocker des données en mémoire, nous avons utilisé des variables simples (typeint,double…), des tableaux et des structures personnalisées. Si vous souhaitez stocker une série de données, le plus simple est en général d'utiliser des tableaux.
Les listes chaînées représentent une façon d'organiser les données en mémoire de manière beaucoup plus flexible qu'un tableau. Comme à la base le langage C ne propose pas ce système de stockage, nous allons devoir le créer nous-mêmes de toutes pièces. C'est un excellent exercice qui vous aidera à être plus à l'aise avec le langage.

Qu'est-ce qu'une liste chaînée ? Je vous propose de partir sur le modèle des tableaux. Un tableau peut être représenté en mémoire comme sur la fig. suivante. Il s'agit ici d'un tableau contenant des `int`.

![tab](https://user.oc-static.com/files/379001_380000/379542.png)

Comme je vous le disais en introduction, le problème des tableaux est qu'ils sont figés. Il n'est pas possible de les agrandir, à moins d'en créer de nouveaux, plus grands (fig. suivante). De même, il n'est pas possible d'y insérer une case au milieu, à moins de décaler tous les autres éléments.

![tab_not](https://user.oc-static.com/files/379001_380000/379543.png)

Le langage C ne propose pas d'autre système de stockage de données, mais il est possible de le créer soi-même de toutes pièces. Encore faut-il savoir comment s'y prendre : c'est justement ce que ce chapitre et les suivants vous proposent de découvrir.

Une liste chaînée est un moyen d'organiser une série de données en mémoire. Cela consiste à assembler des structures en les liant entre elles à l'aide de pointeurs. On pourrait les représenter comme ceci :

![liste_chainee](https://user.oc-static.com/files/379001_380000/379544.png)

Chaque élément peut contenir ce que l'on veut : un ou plusieursint,double… En plus de cela, chaque élément possède un pointeur vers l'élément suivant (fig. suivante).

![liste_chainee_next](https://user.oc-static.com/files/379001_380000/379545.png)

Je reconnais que tout cela est encore très théorique et doit vous paraître un peu flou pour le moment. Retenez simplement comment les éléments sont agencés entre eux : ils forment une chaîne de pointeurs, d'où le nom de « liste chaînée ».

Notes : Contrairement aux tableaux, les éléments d'une liste chaînée ne sont pas placés côte à côte dans la mémoire. Chaque case pointe vers une autre case en mémoire qui n'est pas nécessairement stockée juste à côté.

Il existe plusieurs types de listes chainées on peut trouver des listes doublement chainées c'est à dire des listes qui indique l'élément précédent et l'élément suivant ainsi que les listes circulaire qui n'ont pas de fin.

![liste_chainee_types](https://www.codeheroes.fr/wp-content/uploads/2020/12/linked_list-1024x982.png)
