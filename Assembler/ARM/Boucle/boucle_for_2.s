/* Même programme avec le principe de load and store en utilisant 3 registres */

main: /* Déclaration du programme principal */

	ldr r0, =maVariable //Récupére l adresse de la variable r0
	ldr r1, [r0] //met la valeur pointée par r0 dans r1
	ldr r2, [r0] //On garde en mémoire la valeur initiale de la variable pointé par r0 dans r2
	loop:
		add r1, r1, #1 //On rajoute 1 à r1
		str r1, [r0] // On met à jour la variable pointé par r0 : maVariable
		cmp r1,#9 //On compare r1 à 9
		blo loop // Condition code jump to loop if lower than "9"
	str r2, [r0] // On met à jour la variable pointé par r0 : avec la valeur du registre intermédiaire r2 (Valeur initiale de la variable)
	b main //Retour à la fonction main
