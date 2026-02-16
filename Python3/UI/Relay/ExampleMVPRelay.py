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
        self.setWindowTitle("Controleur de Relais Virtuel (MVP)")

        self.label = QLabel("État: OFF")
        self.button = QPushButton("Toggle")

        layout = QVBoxLayout()
        layout.addWidget(self.label)
        layout.addWidget(self.button)
        self.setLayout(layout)

    # API exposée au Presenter
    def set_state(self, state: bool):
        self.label.setText(f"État: {'ON' if state else 'OFF'}")

    def on_toggle_clicked(self, callback):
        self.button.clicked.connect(callback)


# === PRESENTER ===
class RelayPresenter:
    def __init__(self, model: Relay, view: RelayView):
        self.model = model
        self.view = view

        # connecter la vue au presenter
        self.view.on_toggle_clicked(self.toggle_relay)

        # initialiser la vue
        self.update_view()

    def toggle_relay(self):
        self.model.toggle()
        self.update_view()

    def update_view(self):
        state = self.model.is_on()
        self.view.set_state(state)


# === MAIN ===
def main():
    app = QApplication(sys.argv)

    relay = Relay()
    view = RelayView()
    presenter = RelayPresenter(relay, view)

    view.show()
    sys.exit(app.exec())


if __name__ == "__main__":
    main()
