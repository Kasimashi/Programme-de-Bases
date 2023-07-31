# Decorator

Exemple de la machine à café : 
Une machine à café qui pourrait permettre de rajouter dans le café du sucre, du lait ou de la chantilly.
L'ajout de tout ces ingrédients fait monter le prix.
Le programme permet de fermer à la modification et d'ouvrir à l'extension.
En rajoutant des "Décorateurs" qui doivent hériter de DecoratorBoisson.


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
    
    class Expresso{
        -price
        +prix()
        +description()
    }

    Boisson <|-- Expresso
    Boisson <|-- Coffee
    Boisson <|-- DecoratorBoisson
    DecoratorBoisson <|-- Sucre
    DecoratorBoisson <|-- Lait
    DecoratorBoisson <|-- Chantilly
    DecoratorBoisson *-- Boisson

    class DecoratorBoisson{
        # Boisson* component_
        +DecoratorBoisson(Boisson* component) : component_(component)
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