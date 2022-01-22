#include <stdio.h>


static int triple(int a)
{
    return a * 3;
}


static int quadruple(int a)
{
    return a * 4;
}


static void affiche(int a, int (*pf)(int))
{
    printf("%d\n", (*pf)(a));
}


int main(void)
{
    affiche(3, triple);
    affiche(3, quadruple);
    return 0;
}
