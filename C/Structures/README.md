# Les structures en C

## Les basiques
Une structure étant un regroupement d’objets, la première chose à réaliser est la description de celle-ci (techniquement, sa définition), c’est-à-dire préciser de quel(s) objet(s) cette dernière va se composer.

La syntaxe de toute définition est la suivante.
```
struct étiquette
{
    /* Objet(s) composant(s) la structure. */
};
```

Prenons un exemple concret : vous souhaitez demander à l’utilisateur deux mesures de temps sous la forme heure(s):minute(s):seconde(s).milliseconde(s) et lui donner la différence entre les deux en secondes. Vous pourriez utiliser six variables pour stocker ce que vous fournit l’utilisateur, toutefois cela reste assez lourd. À la place, nous pourrions représenter chaque mesure à l’aide d’une structure composée de trois objets : un pour les heures, un pour les minutes et un pour les secondes.

```
struct temps {
    unsigned heures;
    unsigned minutes;
    double secondes;
};
```

Comme vous le voyez, nous avons donné un nom (plus précisément, une étiquette) à notre structure : « temps ». Les règles à respecter sont les mêmes que pour les noms de variable et de fonction.

Pour le reste, la composition de la structure est décrite à l’aide d’une suite de déclarations de variables. Ces différentes déclarations constituent les membres ou champs de la structure. Notez bien qu’il s’agit de déclarations et non de définitions, l’utilisation d’initialisations est donc exclue.

Enfin, notez la présence d’un point-virgule obligatoire à la fin de la définition de la structure.

Attention une structure ne peux pas comporter plus de 20 membres !

## Initialisation

Comme pour n’importe quelle autre variable, il est possible d’initialiser une variable de type structure dès sa définition. Toutefois, à l’inverse des autres, l’initialisation s’effectue à l’aide d’une liste fournissant une valeur pour un ou plusieurs membres de la structure.

- Initialisation séquentielle :
```
struct temps t = { 1, 45, 30.560 };
```

- Initialisation sélective :
```
struct temps t = { .secondes = 30.560, .minutes =  45, .heures = 1 };
```

- Mixte :
```
struct temps t = { .minutes = 45, 30.560 };
```

Dans le cas où vous n’initialisez pas tous les membres de la structure, les autres seront initialisés à zéro ou, s’il s’agit de pointeurs, seront des pointeurs nuls.
```
struct temps t = { 1 };

Result : 1, 0, 0.000000
```

## Accéder à un membre de la structure :
L'accès à un membre de la structure se fait traditionnelement par un point l'appel de l'objet avec `.`
```
t.heures = 1;
t.minutes = 45;
t.secondes = 30.560;
```

### Accès via un pointeur

Il doit être possible de créer un pointeur vers un objet de ce type.

```
struct temps *p;
```

La définition ci-dessus crée un pointeur `p` vers un objet de type `struct temps`

L’utilisation d’un pointeur sur structure est un peu plus complexe que celle d’un pointeur vers un type de base. En effet, il y a deux choses à gérer : l’accès via le pointeur et l’accès à un membre. Intuitivement, vous combineriez sans doute les opérateurs * et . comme ceci.

`*p.heures = 1;`

Toutefois, cette syntaxe ne correspond pas à ce que nous voulons car l’opérateur . s’applique prioritairement à l’opérateur *. Autrement dit, le code ci-dessus accède au champ heures et tente de lui appliquer l’opérateur d’indirection, ce qui est incorrect puisque le membre heures est un entier non signé.

Pour résoudre ce problème, nous devons utiliser des parenthèses afin que l’opérateur . soit appliqué après le déréférencement, ce qui donne la syntaxe suivante.
`(*p).heures = 1;` qui peut se réécrire : `p->heures = 1;`

Un exemple concret est :
```
struct temps t;
struct temps *p = &t;

p->heures = 1;
p->minutes = 45;
p->secondes = 30.560;
```

## Déclaration et initialisation

Il est possible de déclarer la structure à l'aide d'une étiquette et d'associer directement une variable à celle ci :
```
int main(void)
{
    struct temps {
        unsigned heures;
        unsigned minutes;
        double secondes;
    } t1 = { 1, 45, 30.560 };
    struct temps t2;

    return 0;
}
```
Ici on a deux structures : t1 et t2 qui ont 3 objets.
Il est aussi possible de ne pas mettre d'étiquette à la structure.

```
int main(void)
{
    struct {
        unsigned heures;
        unsigned minutes;
        double secondes;
    } t;

    return 0;
}
```

Ici la structure ne porte pas d'étiquette : mais elle est déclaré sous le nom "t".

## Comment son représenté les structures en mémoire ?

Les membres d’une structure sont placés les uns après les autres en mémoire. Par exemple, prenons cette structure.

```
struct exemple
{
    double flottant;
    char lettre;
    unsigned entier;
};
```

Si nous supposons qu’un double a une taille de huit octets, un char d’un octet, et un unsigned int de quatre octets, voici ce que devrait donner cette structure en mémoire.

```
+---------+----------+
| Adresse |  Champ   |
+---------+----------+
|    0    |          |
+---------+          |
|    1    |          |
+---------+          |
|    2    |          |
+---------+          |
|    3    |          |
+---------+ double   |
|    4    |          |
+---------+          |
|    5    |          |
+---------+          |
|    6    |          |
+---------+          |
|    7    |          |
+---------+----------+
|    8    | char     |
+---------+----------+
|    9    |          |
+---------+          |
|    10   |          |
+---------+ unsigned |
|    11   |          |
+---------+          |
|    12   |          |
+---------+----------+
```

Voyons à présent comment déterminer cela de manière plus précise, en commençant par la taille des types. L’opérateur sizeof permet de connaître la taille en multiplets (bytes en anglais) de son opérande.

```
#include <stdio.h>


int main(void)
{
    double f;

    printf("_Bool : %zu\n", sizeof(_Bool));
    printf("char : %zu\n", sizeof(char));
    printf("short : %zu\n", sizeof(short));
    printf("int : %zu\n", sizeof(int));
    printf("long : %zu\n", sizeof(long));
    printf("float : %zu\n", sizeof(float));
    printf("double : %zu\n", sizeof(double));
    printf("long double : %zu\n", sizeof(long double));

    printf("int : %zu\n", sizeof 5);
    printf("double : %zu\n", sizeof f);
    return 0;
}
```

Résultat (dépend de la machine):
```
_Bool : 1
char : 1
short : 2
int : 4
long : 8
float : 4
double : 8
long double : 16
int : 4
double : 8
```

Voyons maintenant ce que donne la taille de la structure ci dessus :
En toute logique, elle devrait être égale à la somme des tailles de ses membres, chez nous : 13 (8 + 1 + 4).

```
#include <stddef.h>
#include <stdio.h>

struct exemple
{
    double flottant;
    char lettre;
    unsigned int entier;
};


int main(void)
{
    printf("struct exemple : %zu\n", sizeof(struct exemple));
    return 0;
}
```

Résultat :
```
struct exemple : 16
```

Ah ! Il semble que nous avons loupé quelque chose…
Pourquoi obtenons-nous 16 et non 13, comme attendu ? Pour répondre à cette question, nous allons devoir plonger un peu dans les entrailles de notre machine.

En fait, il faut savoir qu’il n’est dans les faits pas possible de lire ou modifier un multiplet spécifique de la mémoire vive. Techniquement, il est uniquement possible de lire ou écrire des blocs de données de taille fixe appelés mots mémoire. Dès lors, il est nécessaire que les données à lire ou à écrire soient contenues dans un de ces mots mémoires.

Quel rapport avec notre structure me direz-vous ? Supposons que notre RAM utilise des blocs de huit octets. Si notre structure faisait treize octets, voici comment elle serait vue en termes de blocs.

```
     +---------+----------+
      | Adresse |  Champ   |
  +-> +---------+----------+
  |   |    0    |          |
  |   +---------+          |
  |   |    1    |          |
  |   +---------+          |
  |   |    2    |          |
  |   +---------+          |
  |   |    3    |          |
1 |   +---------+ flottant |
  |   |    4    |          |
  |   +---------+          |
  |   |    5    |          |
  |   +---------+          |
  |   |    6    |          |
  |   +---------+          |
  |   |    7    |          |
  +-> +---------+----------+
  |   |    8    | lettre   |
  |   +---------+----------+
  |   |    9    |          |
  |   +---------+          |
  |   |    10   |          |
  |   +---------+ entier   |
  |   |    11   |          |
2 |   +---------+          |
  |   |    12   |          |
  |   +---------+----------+
  |
  |
  |
  .
  .
  .
```

Comme vous le voyez, le champ flottant remplit complètement le premier mot, alors que les champs lettre et entiers ne remplissent que partiellement le second. Dans le seul cas de notre structure, cela ne pose pas de problème, sauf que celle-ci n’est pas seule en mémoire. En effet, imaginons maintenant qu’un autre int suive cette structure, nous obtiendrions alors ceci.

```
  +---------+----------+
      | Adresse |  Champ   |
  +-> +---------+----------+
  |   |    0    |          |
  |   +---------+          |
  |   |    1    |          |
  |   +---------+          |
  |   |    2    |          |
  |   +---------+          |
  |   |    3    |          |
1 |   +---------+ flottant |
  |   |    4    |          |
  |   +---------+          |
  |   |    5    |          |
  |   +---------+          |
  |   |    6    |          |
  |   +---------+          |
  |   |    7    |          |
  +-> +---------+----------+
  |   |    8    | lettre   |
  |   +---------+----------+
  |   |    9    |          |
  |   +---------+          |
  |   |    10   |          |
  |   +---------+ entier   |
  |   |    11   |          |
2 |   +---------+          |
  |   |    12   |          |
  |   +---------+----------+
  |   |    13   |          |
  |   +---------+          |
  |   |    14   |          |
  |   +---------+ int      |
  |   |    15   |          |
  +-> +---------+          |
  |   |    16   |          |
  |   +---------+----------+
  |
  |
3 |
  .
  .
  .
```

Et là, c’est le drame, le second entier est à cheval sur le deuxième et le troisième mot. Pour éviter ces problèmes, les compilateurs ajoutent des multiplets dit « de bourrage » (padding en anglais), afin que les données ne soient jamais à cheval sur plusieurs mots. Dans le cas de notre structure, le compilateur a ajouté trois octets de bourrage juste après le membre lettre afin que les deux derniers champs occupent un mot complet.

```
      +---------+----------+
      | Adresse |  Champ   |
  +-> +---------+----------+
  |   |    0    |          |
  |   +---------+          |
  |   |    1    |          |
  |   +---------+          |
  |   |    2    |          |
  |   +---------+          |
  |   |    3    |          |
1 |   +---------+ flottant |
  |   |    4    |          |
  |   +---------+          |
  |   |    5    |          |
  |   +---------+          |
  |   |    6    |          |
  |   +---------+          |
  |   |    7    |          |
  +-> +---------+----------+
  |   |    8    | lettre   |
  |   +---------+----------+
  |   |    9    |          |
  |   +---------+          |
  |   |    10   | bourrage |
  |   +---------+          |
  |   |    11   |          |
2 |   +---------+----------+
  |   |    12   |          |
  |   +---------+          |
  |   |    13   |          |
  |   +---------+ entier   |
  |   |    14   |          |
  |   +---------+          |
  |   |    15   |          |
  +-> +---------+----------+
  |   |    16   |          |
  |   +---------+          |
  |   |    17   |          |
  |   +---------+ int      |
  |   |    18   |          |
  |   +---------+          |
  |   |    19   |          |
3 |   +---------+----------+
  |
  |
  |
  .
  .
  .
```

Ainsi, il n’y a plus de problèmes, l’entier suivant la structure n’est plus à cheval sur deux mots.

Cela est dû à la position du champ entier dans la structure. Dans notre exemple, il y a 9 multiplets qui précèdent le champ entier, or le compilateur sait que la taille d’un unsigned int est de quatre multiplets et que la RAM utilise des blocs de huit octets, il en déduit alors qu’il y aura un problème. En effet, pour qu’il n’y ait pas de soucis, il est nécessaire qu’un champ de type unsigned int soit précédé d’un nombre de multiplets qui soit multiple de quatre (d’où les trois multiplets de bourrage pour arriver à 12).

Cette contrainte est appelée une contrainte d’alignement (car il est nécessaire d’« aligner » les données en mémoire). Chaque type possède sa propre contrainte d’alignement, dans notre exemple le type unsigned int a une contrainte d’alignement (ou simplement un alignement) de 4.

## Opérateur _packed

```
struct debug_block {
          struct gelic_descr descr;
          u8 pkt[1520];
  }__packed;
```

Le __packed signifie que, en memoire, les champs de ta structures vont être les un a la suite des autres,
il n'y aura pas de bit de padding entre les champs.

## Opérateur _aligned

```
struct gelic_descr {
         __be32 buf_addr;
          __be32 buf_size;
          __be32 next_descr_addr;
          __be32 dmac_cmd_status;
          __be32 result_size;
          __be32 valid_size;      /* all zeroes for tx */
          __be32 data_status;
          __be32 data_error;      /* all zeroes for tx */
  } __attribute__((aligned(32)));
```
Le __attribute__((aligned(32))) sert a indiquer a GCC que tu veux que cette structure ait un alignement sur 32 bits,
ca veux dire que tout les offset des champs de ta structure vont etre des multiples de 32.

## Options de compilation :

Avec GCC, l'option `-Wpadded` permet de savoir si une structure nécessite du padding pour être alignée.

Le message de warning type d'un erreur d'alignement est :
```
Warning padding struct to align 'd' 
Warning padding struct size to alignment boundary
```

## Références :
https://zestedesavoir.com/tutoriels/755/le-langage-c-1/1043_aggregats-memoire-et-fichiers/4279_structures/#5-12830_un-peu-de-memoire



