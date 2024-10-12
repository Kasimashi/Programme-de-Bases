# Cas réservation des vols

On souhaite gérer les réservartions de vols effectués dans une agence.
D'après les interviews avec les membres de l'agence, on sait que :

- Les compagnies aériennes proposent différents vols.
- Un vol est ouvert à la reservation et refermé sur ordre de la compagnie
- Un client peut réserver ou ou plusieurs vols pour des passagers différents.
- Une réservation concerne un seul vol et un seul passager
- Une réservation peut être confirmée ou annulée
- Un vol a un aéroport de départ et d'arrivée.
- Un vol a un jour et une heure de départ, un jour une heure d'arrivée.
- Un vol peut comporter des escales dans un ou plusieurs aéroports.
- Une escale a une heure de départ et une heure d'arrivée
- Chaques aéroports dessert une ou plusieurs villes.

```mermaid
classDiagram
    
    class Personne {
        +String Nom
        +String Prénom
        +String Téléphone
    }
    Personne <|-- Client
    Personne <|-- Passager
    
    class Client {
        
    }
    Client "1" -- "1..*" Reservation : reverve
    
    class Passager {
    }
    
    class Ville {
        +String Nom
    }
    class Aeroport {
        +Ville villes
    }
    Aeroport "1..*" -- "1..*" Ville : dessert
    
    class Escale {
        +Date Départ
        +Date Arrivée
    }
    Escale "1" -- "1" Date
    Escale "1" -- "1" Date
    
    class Date {
        Jour
        Heure
    }

    class Vol {
        +Aeroport Départ
        +Aeroport Arrivée
        +Date Départ
        +Date Arrivée
        +Escale Escales[]
        +creer()
        +modifier()
        +afficher()
        +ouvrir()
        +fermer()
    }
    Vol "1" -- "1" Date : Départ
    Vol "1" -- "1" Date : Arrivée
    Vol "1..*" -- "1" Aeroport : Départ
    Vol "1..*" -- "1" Aeroport : Arrivée
    Vol "1" -- "*" Escale
    
    class Reservation {
        + Vol flight
        +Bool confirmed
        
    }
    Reservation "1..*" -- "1" Passager : A pour
    Reservation "*" -- "1" Vol : concerne
    
    class Compagnie {
        +String Nom
        +creer()
        +modifier()
        +afficher()
    }
    Compagnie "1" -- "1..*" Vol  : propose
```