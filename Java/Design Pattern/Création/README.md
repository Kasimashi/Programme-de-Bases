# Design pattern CREATION

Les design patterns créationnels délèguent la création d’objets à une fonction ou classe spécifique.

- Si les objets partagent les mêmes fonctions, mais sont de types différents, il faut privilégier le design pattern Factory Method.

- Si vous souhaitez économiser l’instanciation d’un objet coûteux pour le modifier légèrement, vous implémenterez le design patten Prototype.

- Si les objets à manipuler sont complexes, ou leur construction dynamique (elle dépend de nombreux paramètres passés par l’utilisateur), nous pourrons utiliser le design pattern Builder. Et si certains objets sont toujours construits ou doivent être reconstruits dans un ordre spécifique, nous pourrons utiliser des Directeurs.

- Enfin, le design pattern Singleton est particulier et présente des défauts majeurs de conception. Son usage est justifié dans certains cas très particuliers (gestion de la base de données), mais devrait être évité.

-------------------------------------------------------------

Fabrique (Factory)	Créer un objet dont le type dépend du contexte
Fabrique abstraite (abstract Factory)	Fournir une interface unique pour instancier des objets d'une même famille sans avoir à connaître les classes à instancier
Monteur (Builder)	 
Prototype (Prototype)	Création d'objet à partir d'un prototype
Singleton (Singleton)	Classe qui ne pourra avoir qu'une seule instance
