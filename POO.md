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

## Héritage

La classe mère est une généréalisation des classes filles.

![image](https://github.com/user-attachments/assets/301e5346-e3b4-4fdc-a3ac-94a66157f527)

## Composition et agréation

- La composition est une relation de subordination forte dépendant du cycle de vie. Si la classe mère disparait, la classe composée aussi.
(On déclarera ici un objet dans la classe)

- L'agréation est une relation de subordination plus faible. La classe composée n'est pas détruite lors de la destruction de la classe mère.
(On utilisera ici un pointeur)

![image](https://github.com/user-attachments/assets/3c708a17-db8f-4416-8b78-36bbc44329cc)

## Association

- Une association montre le lien entre deux ou plusieurs classes.
- Une association n'est pas un lien de subordination. Aucune classe n'est supérieure à l'autre.
- Une association peut être réflexive

![image](https://github.com/user-attachments/assets/392acd33-09e1-45ad-88a1-f6b6a6e33c9e)

:warning: Une association possède une cardinalité d'association exemple : 

![image](https://github.com/user-attachments/assets/b108579a-9d01-4f2f-b9f8-bbafad4a3f02)


## Références

https://www.youtube.com/watch?v=aYV2ixlbN8E
