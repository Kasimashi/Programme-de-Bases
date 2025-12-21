import sys
from dataclasses import dataclass
from PyQt6.QtWidgets import QApplication, QWidget, QPushButton, QVBoxLayout, QLabel
from PyQt6.QtCore import QObject, pyqtSignal

# === MODEL ===
@dataclass
class RelayData:
    name: str
    state: bool = False

class Relay:
    def __init__(self, data: RelayData):
        self.data = data

    def on(self):
        self.data.state = True
        print(f"{self.data.name} ON")

    def off(self):
        self.data.state = False
        print(f"{self.data.name} OFF")

    def toggle(self):
        self.data.state = not self.data.state
        print(f"{self.data.name} {'ON' if self.data.state else 'OFF'}")

    def is_on(self):
        return self.data.state


# === DATA MODEL ===
class RelayManager:
    """Gère plusieurs relais et peut charger une liste de RelayData"""
    def __init__(self):
        self.relays = []

    def add_relay(self, relay: Relay):
        self.relays.append(relay)

    def load_from_data(self, data_list: list[RelayData]):
        """Charge plusieurs relais depuis une liste de RelayData"""
        self.relays = [Relay(data) for data in data_list]

    def all_states(self):
        return [relay.is_on() for relay in self.relays]


# === VIEWMODEL ===
class RelayViewModel(QObject):
    state_changed = pyqtSignal(bool)

    def __init__(self, relay: Relay):
        super().__init__()
        self._relay = relay

    def toggle(self):
        self._relay.toggle()
        self.state_changed.emit(self._relay.is_on())

    def turn_on(self):
        self._relay.on()
        self.state_changed.emit(self._relay.is_on())

    def turn_off(self):
        self._relay.off()
        self.state_changed.emit(self._relay.is_on())

    def get_state(self):
        return self._relay.is_on()


# === VIEW ===
class RelayView(QWidget):
    def __init__(self, view_model: RelayViewModel):
        super().__init__()
        self.vm = view_model
        self.setWindowTitle(self.vm._relay.data.name)

        self.label = QLabel(f"État: {'ON' if self.vm.get_state() else 'OFF'}")
        self.button = QPushButton("Toggle")

        layout = QVBoxLayout()
        layout.addWidget(self.label)
        layout.addWidget(self.button)
        self.setLayout(layout)

        self.button.clicked.connect(self.vm.toggle)
        self.vm.state_changed.connect(self.update_label)

    def update_label(self, state: bool):
        self.label.setText(f"État: {'ON' if state else 'OFF'}")


# === MAIN ===
def main():
    app = QApplication(sys.argv)

    # Exemple de liste de RelayData
    relay_data_list = [
        RelayData("Relay 1", False),
        RelayData("Relay 2", True),
        RelayData("Relay 3", False),
    ]

    manager = RelayManager()
    manager.load_from_data(relay_data_list)

    main_window = QWidget()
    main_window.setWindowTitle("Contrôleur de Relais Virtuel")
    layout = QVBoxLayout()

    for relay in manager.relays:
        vm = RelayViewModel(relay)
        view = RelayView(vm)
        layout.addWidget(view)

    main_window.setLayout(layout)
    main_window.show()

    sys.exit(app.exec())


if __name__ == "__main__":
    main()
