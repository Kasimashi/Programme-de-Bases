#include <stdio.h>
#include <stdlib.h>

struct temps {
    unsigned heures;
    unsigned minutes;
    double secondes;
};


int main(void)
{
    struct temps t1;
    struct temps t2;

    printf("Première mesure (hh:mm:ss.xxx) : ");

    if (scanf("%u:%u:%lf", &t1.heures, &t1.minutes, &t1.secondes) != 3)
    {
        printf("Mauvaise saisie\n");
        return EXIT_FAILURE;
    }

    printf("Deuxième mesure (hh:mm:ss.xxx) : ");

    if (scanf("%u:%u:%lf", &t2.heures, &t2.minutes, &t2.secondes) != 3)
    {
        printf("Mauvaise saisie\n");
        return EXIT_FAILURE;
    }

    t1.minutes += t1.heures * 60;
    t1.secondes += t1.minutes * 60;
    t2.minutes += t2.heures * 60;
    t2.secondes += t2.minutes * 60;

    printf("Il y a %.3f seconde(s) de différence.\n",
    t2.secondes - t1.secondes);
    return 0;
}
