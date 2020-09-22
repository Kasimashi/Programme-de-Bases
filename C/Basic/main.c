#include <stdio.h> //Directive de préprocesseur

int main(int argc, char **argv)
{
	/*
	 * Ceci est un commentaire
	 */
	char int8_mavariable;//sur 1 octet
	short int16_mavariable;//sur 2 octet
	int int32_mavariable; // sur 4 octets
	long int64_mavariable;// sur 8 octet

	/* Pour les variables non signées (positive)*/

	unsigned char uint8_mavariable;// sur 1 octet
	unsigned short uint16_mavariable;// sur 2 octet
	unsigned int uint32_mavariable;// sur 4 octet
	unsigned long uint64_mavariable;// sur 8 octet

	/* Variable à virgule */
	float f_mavariable; // sur 4 octet
	double d_mavariable; //sur 8 octet
	
	printf("give me a bottle of rum!\n");

	return 0; //Retour de la fonction
}
