import sys
from dataclasses import dataclass
from enum import Enum, auto
from PyQt6.QtWidgets import QApplication, QWidget, QPushButton, QLabel, QVBoxLayout


# =======================
# STATE (Model)
# =======================
@dataclass(frozen=True)
class CounterState:
    count: int = 0


# =======================
# INTENTS
# =======================
class CounterIntent(Enum):
    INCREMENT = auto()


# =======================
# REDUCER
# =======================
def counter_reducer(state: CounterState, intent: CounterIntent) -> CounterState:
    if intent == CounterIntent.INCREMENT:
        return CounterState(count=state.count + 1)
    return state


# =======================
# VIEW
# =======================
class CounterView(QWidget):
    def __init__(self):
        super().__init__()
        self.setWindowTitle("MVI PyQt6 (1 fichier)")

        self.label = QLabel("0")
        self.button = QPushButton("Incrémenter")

        layout = QVBoxLayout()
        layout.addWidget(self.label)
        layout.addWidget(self.button)
        self.setLayout(layout)

    def render(self, state: CounterState):
        self.label.setText(str(state.count))


# =======================
# STORE (orchestrateur)
# =======================
class Store:
    def __init__(self, initial_state: CounterState):
        self.state = initial_state
        self.subscribers = []

    def dispatch(self, intent: CounterIntent):
        self.state = counter_reducer(self.state, intent)
        self.notify()

    def subscribe(self, callback):
        self.subscribers.append(callback)
        callback(self.state)  # rendu initial

    def notify(self):
        for cb in self.subscribers:
            cb(self.state)


# =======================
# MAIN
# =======================
if __name__ == "__main__":
    app = QApplication(sys.argv)

    view = CounterView()
    store = Store(CounterState())

    # View → Intent
    view.button.clicked.connect(lambda: store.dispatch(CounterIntent.INCREMENT))

    # State → View
    store.subscribe(view.render)

    view.show()
    sys.exit(app.exec())
