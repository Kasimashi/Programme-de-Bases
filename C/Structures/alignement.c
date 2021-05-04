#include <stdio.h>

struct no_align
{
    char c;
    double d;
    int i;
    char c2[3];
};

struct align
{
    double d;
    int i;
    char c2[3];
    char c;
};

/*
Les deux structures contiennent les mêmes membres. On pourrait donc en déduire qu'elles ont la même taille. Ainsi, en faisant l'hypothèse que :

le type char fait 1 octet ;
le type int fait 4 octets ;
le type double fait 8 octets.
la taille totale serait de 1 + 8 + 4 + 3 × 1 = 16 octets.
*/

int main(int argc, char **argv)
{
	printf("%zu %zu\n", sizeof(struct no_align), sizeof(struct align));
	return 0;
}

/*
Le résultat est 24 et 16 octets. En effet les membres de la structure align sont bien alignés (par multiple de word : 8 bits), mais pas ceux de no_align. Le compilateur rajoute des octets dits de padding pour respecter l'alignement. Une fois compilé, no_align ressemble à ceci :

struct no_align_compile
{
    char c;
    char __pad1[7];
    double d;
    int i;
    char c2[3];
    char __pad2;
};

Il y a deux padding pour notre cas.
```

