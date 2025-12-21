import sys
from PyQt6.QtWidgets import QApplication, QWidget, QPushButton, QVBoxLayout, QLabel

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


# === VIEW ===
class RelayView(QWidget):
    def __init__(self):
        super().__init__()
        self.setWindowTitle("Controleur de Relais Virtuel - MVC")

        # Widgets
        self.label = QLabel("État: OFF")
        self.button = QPushButton("Toggle")

        # Layout
        layout = QVBoxLayout()
        layout.addWidget(self.label)
        layout.addWidget(self.button)
        self.setLayout(layout)

    def set_state(self, state: bool):
        """Met à jour l'affichage selon l'état du relais"""
        self.label.setText(f"État: {'ON' if state else 'OFF'}")


# === CONTROLLER ===
class RelayController:
    def __init__(self, model: Relay, view: RelayView):
        self.model = model
        self.view = view

        # Connecte le bouton de la vue à la méthode du controller
        self.view.button.clicked.connect(self.toggle_relay)

        # Initialisation de la vue
        self.update_view()

    def toggle_relay(self):
        self.model.toggle()
        self.update_view()

    def turn_on(self):
        self.model.on()
        self.update_view()

    def turn_off(self):
        self.model.off()
        self.update_view()

    def update_view(self):
        self.view.set_state(self.model.is_on())


# === MAIN ===
def main():
    app = QApplication(sys.argv)

    relay = Relay()
    view = RelayView()
    controller = RelayController(relay, view)

    view.show()
    sys.exit(app.exec())


if __name__ == "__main__":
    main()
