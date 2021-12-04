Quelque part dans le parc national de Krüger en Afrique du sud, se trouve un très profond canyon. Ce canyon peut être traversé par une liane tendue au dessus du vide. De part et d'autre du canyon se trouve de nombreux babouins. Les babouins utilisent la liane pour traverser en funambule le canyon.
On vous propose de modéliser la traversée des babouins de 2 façon différentes :
- En utilisant la duplication de processus
- En utilisant des threads

##Duplication de processus.
Il est demandé de modéliser la traversée du canyon pour 2 babouins : un père et son fils.
Les règles sont les suivantes :
    - Le père traverse en premier le cayon et met 1 seconde à traverser
    - Dès que le père a traversé le fils traverse à son tour, en mettant cette fois 2 secondes.
    
Contrainte :
Utilisation de la fonction fork();
Utilisation du signal SIGUSR1 pour que le père signifie à son fils que c'est à son tour.
Utiliser la fonction sleep(int s) pour temporiser
Pour faire patienter le fils utiliser une variable globale ATTENTE_FILS et une boucle while();

L'affichage doit être le suivant :
Babouin pere commence à  traverser liane.
Babouin pere a fini à traverser liane.
Babouin fils commence à traverser liane.
Babouin fils a fini de traverser liane.
