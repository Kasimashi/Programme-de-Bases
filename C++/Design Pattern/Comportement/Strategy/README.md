# Strategy

Stratégie est un patron de conception comportemental qui permet de définir une famille d’algorithmes, de les mettre dans des classes séparées et de rendre leurs objets interchangeables.


```mermaid
classDiagram

    class Client{
    }
    Client --> Context
    Client ..> StrategyA
    Client ..> StrategyB
    Client ..> StrategyC
    Strategy --o Context

    class Context{
        -strategy
        +setStategy()
        +doSomething()
    }

    class Strategy{
        +execute()
    }
    Strategy <|-- StrategyA
    Strategy <|-- StrategyB
    Strategy <|-- StrategyC
    class StrategyA{
      +execute()
    }
    class StrategyB{
      +execute()
    }
    class StrategyC{
      +execute()
    }
```