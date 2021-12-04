/* Ce programme permet de faire une boucle for en incrémentant jusqu a 9 (inclus) un registre r1 */

main: /* Déclaration du programme principal */
	/*
	for (int i=0;i<10;i++){
	}
	*/
	mov r1, #0 //met la valeur 0 dans r1
	loop:

		add r1, r1, #1 //On rajoute 1 à r1
		cmp r1,#9 //On compare r1 à 9
		blo loop // Condition code jump to loop if lower than "9"
	b main //Retour à la fonction main
