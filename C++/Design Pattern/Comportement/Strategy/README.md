# Hello

```mermaid
classDiagram

    class Client{
    }
    Client --> Context
    Client ..> StrategyA
    Client ..> StrategyB
    Client ..> StrategyC
    IStrategy --o Context

    class Context{
        -strategy
        +setStategy()
        +doSomething()
    }

    class IStrategy{
        +execute()
    }
    IStrategy <|-- StrategyA
    IStrategy <|-- StrategyB
    IStrategy <|-- StrategyC
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