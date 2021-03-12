#include <stdio.h>
#include <stdlib.h>


int main(int argc, char *argv[])
{
    int age = 10;
	printf("La variable age vaut : %d\n", age);
	printf("L'adresse de la variable age est : %p\n", &age);

	int *pointeurSurAge = &age; //signifie "pointeurSurAge contient l'adresse de la variable age"
	
	printf("pointeurSurAge montre l'addresse : %p\n", pointeurSurAge);
	printf("La valeur pointé par pointeurSurAge vaut : %d\n", *pointeurSurAge);
	printf("L'addresse propre de pointeurSurAge : %p\n", &pointeurSurAge);
    return 0;
}


