#include <stdio.h>
#include <stdarg.h>
/*****************************************************************************/
/*                                                                           */
/*                              addn                                         */
/*                                                                           */
/*   But:                                                                    */
/*      réalise l'addition d'un nombre variable de paramètres                */
/*                                                                           */
/*****************************************************************************/
int addn(int nbopd, ...)         /*   nbopd = nombre d'opérandes du add      */
{
    int i, s = 0;
    va_list(ap);                     /*   déclaration de ap                      */

    va_start(ap,nbopd);              /*   initialisation de ap                   */
    for( i = 1; i <= nbopd; i++)
       s += va_arg(ap,int);       /*   va_arg() donne le paramètre courant    */
    va_end(ap);                      /*   on a fini                              */
    return(s);
}

/*****************************************************************************/
/*                              main                                         */
/*****************************************************************************/
int main()
{
    printf("resu = %d\n",addn(3,10,11,12));   /*   imprime 33                    */
}
