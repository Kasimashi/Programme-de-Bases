# Design Pattern

## Creation

### Factory

Fabrique est un patron de conception de création qui définit une interface pour créer des objets dans une classe mère, mais délègue le choix des types d’objets à créer aux sous-classes.

![image](https://github.com/Kasimashi/Programme-de-Bases/assets/62567511/7dfb1ad7-2318-4559-ae05-260b84ab7fe1)

### Abstract Factory

Fabrique abstraite est un patron de conception qui permet de créer des familles d’objets apparentés sans préciser leur classe concrète.

![image](https://github.com/Kasimashi/Programme-de-Bases/assets/62567511/fbd5b4cf-57b2-47cf-8778-9ceacfe6cd66)

### Builder

Monteur est un patron de conception de création qui permet de construire des objets complexes étape par étape. Il permet de produire différentes variations ou représentations d’un objet en utilisant le même code de construction.

![image](https://github.com/Kasimashi/Programme-de-Bases/assets/62567511/2e769eea-1329-476e-895e-a2f60fe8c126)

### Prototype

Prototype est un patron de conception qui crée de nouveaux objets à partir d’objets existants sans rendre le code dépendant de leur classe.

![image](https://github.com/Kasimashi/Programme-de-Bases/assets/62567511/cbd24836-4e96-4d29-8987-5ac1d5f5d927)

### Singleton

Singleton est un patron de conception de création qui garantit que l’instance d’une classe n’existe qu’en un seul exemplaire, tout en fournissant un point d’accès global à cette instance.

![image](https://github.com/Kasimashi/Programme-de-Bases/assets/62567511/09813a47-5588-40f8-8179-0f985f77381c)

## Structural

### Adapter

L’Adaptateur est un patron de conception structurel qui permet de faire collaborer des objets ayant des interfaces normalement incompatibles.

![image](https://github.com/Kasimashi/Programme-de-Bases/assets/62567511/7c0e0fb7-1bec-4644-ab5a-51cbe04332fb)

### Bridge

Le Pont est un patron de conception structurel qui permet de séparer une grosse classe ou un ensemble de classes connexes en deux hiérarchies — abstraction et implémentation — qui peuvent évoluer indépendamment l’une de l’autre.

![image](https://github.com/Kasimashi/Programme-de-Bases/assets/62567511/7e9c20d9-3c59-4d79-b7a1-b8170afa6e56)

### Composite

Composite est un patron de conception structurel qui permet d’agencer les objets dans des arborescences afin de pouvoir traiter celles-ci comme des objets individuels.

![image](https://github.com/Kasimashi/Programme-de-Bases/assets/62567511/6f348a38-ae0b-4548-89ea-f36f4c358a07)

### Decorateur

Décorateur est un patron de conception structurel qui permet d’affecter dynamiquement de nouveaux comportements à des objets en les plaçant dans des emballeurs qui implémentent ces comportements.

![image](https://github.com/Kasimashi/Programme-de-Bases/assets/62567511/b7e03685-dcc3-4831-836e-15249f8a573c)

### Facade

Façade est un patron de conception structurel qui procure une interface offrant un accès simplifié à une librairie, un framework ou à n’importe quel ensemble complexe de classes.

![image](https://github.com/Kasimashi/Programme-de-Bases/assets/62567511/0b3513cb-1025-485d-b967-77492613fcbc)

### Flyweight

Poids mouche est un patron de conception structurel qui permet de stocker plus d’objets dans la RAM en partageant les états similaires entre de multiples objets, plutôt que de stocker les données dans chaque objet.

![image](https://github.com/Kasimashi/Programme-de-Bases/assets/62567511/f44c8ef3-9977-4f10-a6cd-e169950ef5ff)

### Proxy

La Procuration est un patron de conception structurel qui vous permet d’utiliser un substitut pour un objet. Elle donne le contrôle sur l’objet original, vous permettant d’effectuer des manipulations avant ou après que la demande ne lui parvienne.

![image](https://github.com/Kasimashi/Programme-de-Bases/assets/62567511/1c625f09-6d0e-4deb-a34e-22515c2cb268)

## Behavioral

### Chain of Responsibility

Chaîne de responsabilité est un patron de conception comportemental qui permet de faire circuler des demandes dans une chaîne de handlers. Lorsqu’un handler reçoit une demande, il décide de la traiter ou de l’envoyer au handler suivant de la chaîne.

![image](https://github.com/Kasimashi/Programme-de-Bases/assets/62567511/71a3da76-004c-49a8-89b1-f466d70084fc)

### Command

Commande est un patron de conception comportemental qui prend une action à effectuer et la transforme en un objet autonome qui contient tous les détails de cette action. Cette transformation permet de paramétrer des méthodes avec différentes actions, planifier leur exécution, les mettre dans une file d’attente ou d’annuler des opérations effectuées.

![image](https://github.com/Kasimashi/Programme-de-Bases/assets/62567511/e97bb24a-04bf-4d00-963a-02d2b071b330)

### Iterator

Itérateur est un patron de conception comportemental qui permet de parcourir les éléments d’une collection sans révéler sa représentation interne (liste, pile, arbre, etc.).

![image](https://github.com/Kasimashi/Programme-de-Bases/assets/62567511/6ef39e1d-6004-41c2-9941-e2f91f33ccf7)

### Mediator

Médiateur est un patron de conception comportemental qui diminue les dépendances chaotiques entre les objets. Il restreint les communications directes entre les objets et les force à collaborer uniquement via un objet médiateur.

![image](https://github.com/Kasimashi/Programme-de-Bases/assets/62567511/0485daec-56f2-4353-90ed-02e13acecdff)

### Memento

Mémento est un patron de conception comportemental qui permet de sauvegarder et de rétablir l’état précédent d’un objet sans révéler les détails de son implémentation.

![image](https://github.com/Kasimashi/Programme-de-Bases/assets/62567511/6f0840ff-fd69-419f-9256-3e06f3487050)

### Observer

L’Observateur est un patron de conception comportemental qui permet de mettre en place un mécanisme de souscription pour envoyer des notifications à plusieurs objets, au sujet d’événements concernant les objets qu’ils observent.


![image](https://github.com/Kasimashi/Programme-de-Bases/assets/62567511/0ba42884-c506-4b01-8d69-061dc869b205)

### State

État est un patron de conception comportemental qui permet de modifier le comportement d’un objet lorsque son état interne change. L’objet donne l’impression qu’il change de classe.

![image](https://github.com/Kasimashi/Programme-de-Bases/assets/62567511/26473feb-37a6-4a7c-9be7-3013cfee31c0)

### Strategy

Stratégie est un patron de conception comportemental qui permet de définir une famille d’algorithmes, de les mettre dans des classes séparées et de rendre leurs objets interchangeables.

![image](https://github.com/Kasimashi/Programme-de-Bases/assets/62567511/a3d86a19-e7ae-430f-aea8-a39235a2fc60)

### Template Method

Patron de Méthode est un patron de conception comportemental qui permet de mettre le squelette d’un algorithme dans la classe mère, mais laisse les sous-classes redéfinir certaines étapes de l’algorithme sans changer sa structure.

![image](https://github.com/Kasimashi/Programme-de-Bases/assets/62567511/7236b033-310b-4c3f-b218-4637e273b1d8)

### Visitor

Visiteur est un patron de conception comportemental qui vous permet de séparer les algorithmes et les objets sur lesquels ils opèrent.

![image](https://github.com/Kasimashi/Programme-de-Bases/assets/62567511/5c1be571-e20a-439b-92f2-427edaea0a70)


