# Decorator

Exemple de la machine à café : 
Une machine à café qui pourrait permettre de rajouter dans le café du sucre, du lait ou de la chantilly.
L'ajout de tout ces ingrédients fait monter le prix.
Le programme permet de fermer à la modification et d'ouvrir à l'extension.
En rajoutant des "Décorateurs" qui doivent hériter de CoffeeDecorator.


```mermaid
classDiagram

    class Boisson{     
        +~Boisson()
        +std::string Description() const = 0
        +double prix() = 0
    }

    class Coffee{
        -price
        +prix()
        +description()
    }

    Boisson <|-- Coffee
    Boisson <|-- CoffeeDecorator
    CoffeeDecorator <|-- Sucre
    CoffeeDecorator <|-- Lait
    CoffeeDecorator <|-- Chantilly
    CoffeeDecorator *-- Boisson

    class CoffeeDecorator{
        # Boisson* component_
        +DecoratorCoffee(Boisson* component) : component_(component)
        +prix()
        +Description()
    }

    class Sucre{
        -price
        +Description()
        +prix()
    }

    class Chantilly{
        -price
        +Description()
        +prix()
    }

    class Lait{
        -price
        +Description()
        +prix()
    }
```