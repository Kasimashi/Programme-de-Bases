import sys
from PyQt6.QtWidgets import QApplication, QWidget, QPushButton, QVBoxLayout, QLabel
from PyQt6.QtCore import QObject, pyqtSignal

# === MODEL ===
class Relay:
    def __init__(self, name="Relay"):
        self.name = name
        self._state = False

    def on(self):
        self._state = True
        print(f"{self.name} ON")

    def off(self):
        self._state = False
        print(f"{self.name} OFF")

    def toggle(self):
        self._state = not self._state
        print(f"{self.name} {'ON' if self._state else 'OFF'}")

    def is_on(self):
        return self._state


# === VIEWMODEL ===
class RelayViewModel(QObject):
    state_changed = pyqtSignal(bool)  # signal pour la vue

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
        self.setWindowTitle("Controleur de Relais Virtuel")

        # Widgets
        self.label = QLabel("État: OFF")
        self.button = QPushButton("Toggle")

        # Layout
        layout = QVBoxLayout()
        layout.addWidget(self.label)
        layout.addWidget(self.button)
        self.setLayout(layout)

        # Connections
        self.button.clicked.connect(self.vm.toggle)
        self.vm.state_changed.connect(self.update_label)

    def update_label(self, state: bool):
        self.label.setText(f"État: {'ON' if state else 'OFF'}")


# === MAIN ===
def main():
    app = QApplication(sys.argv)

    relay = Relay()
    vm = RelayViewModel(relay)
    view = RelayView(vm)
    view.show()

    sys.exit(app.exec())


if __name__ == "__main__":
    main()
