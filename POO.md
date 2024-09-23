# Programmation orienté objet

## Propriétés

– Une propriété `public` :
ça veux dire qu’elle est accessible depuis n’importe quelle partie du code, 
donc vous avez créé une instance de votre classe, un objet, donc l’objet voiture1.nom, 
nom est une propriété public, une variable public de votre classe.

– Une propriété `private` : 
Est accessible que depuis la même classe, 
donc c’est à dire que de l’extérieur, 
si vous créez une instance voiture, voiture.couleur, 
si couleur est définie en private, vous ne pourrez pas accéder à la propriété couleur directement. 
Il vous faudra passer par une méthode qui le permet. Il faut savoir que les classes qui héritent d’une autre classe, n’ont pas accès aux attributs ou aux propriétés private.

– Une propriété peut être `protected` :
Elle est accessible depuis la même classe ET également depuis les classes qui en héritent. 
Ce type de propriété vous permet, pour l’héritage, private, la propriété reste uniquement cantonné à la même classe et pas celle qui en hérite, 
et protected ça permet de transférer les propriétés, elles peuvent être modifiées par les classes qui en héritent.

## Méthodes

– Une méthode `protected`, est, elle, accessible depuis la même classe et toutes celles qui en héritent. 
C’est exactement le même principe que les propriétés. 
Si vous avez compris les attributs public, private, protected, static pour les propriétés, et également pour les classes, pour les méthodes, c’est le même principe de fonctionnement.
