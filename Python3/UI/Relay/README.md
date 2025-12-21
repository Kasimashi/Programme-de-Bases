| Aspect             | MVVM                                  | MVC                              |
|-------------------|---------------------------------------|---------------------------------|
| Relation Vue/Modèle| Vue <-> ViewModel <-> Modèle          | Vue <- Controller -> Modèle      |
| Signalisation     | Signaux Qt (data binding)             | Vue appelle controller manuellement |
| Couplage          | Vue et modèle découplés via VM        | Vue et modèle découplés via Controller |
| Adapté pour       | Data binding complexe, UI réactive    | Logique simple, événements directs |


Association : 

```mermaid
classDiagram
    %% === Models ===
    RelayData --> Relay : contains
    Relay --> DBManager : optional persistence
    RelayManager --> Relay : contains multiple

    %% === ViewModels ===
    RelayViewModel --> Relay : 1-1
    RelaysViewModel --> Relay : 1-many

    %% === Views ===
    RelayView --> RelayViewModel : observes
    MainWindow --> RelayView : contains multiple

    %% Description des relations
    class RelayData {
        +name: str
        +state: bool
    }

    class Relay {
        +data: RelayData
        +on()
        +off()
        +toggle()
        +is_on(): bool
    }

    class DBManager {
        +load_relays()
        +add_relay()
        +update_relay()
    }

    class RelayManager {
        +relays: list[Relay]
        +load_from_db()
        +add_relay()
    }

    class RelayViewModel {
        +toggle()
        +turn_on()
        +turn_off()
        +state_changed: Signal
    }

    class RelaysViewModel {
        +relays: list[Relay]
        +toggle(index)
        +state_changed: Signal(index, state)
    }

    class RelayView {
        +label: QLabel
        +button: QPushButton
        +update_label(state)
    }

    class MainWindow {
        +layout: QVBoxLayout
    }
```