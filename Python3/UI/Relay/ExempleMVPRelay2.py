import sys
from PyQt6.QtWidgets import (
    QApplication, QWidget, QPushButton,
    QVBoxLayout, QLabel, QHBoxLayout
)


# =======================
# MODEL
# =======================
class Relay:
    def __init__(self, name="Relay"):
        self.name = name
        self._state = False
        self._actions = 0

    def on(self):
        if not self._state:
            self._state = True
            self._actions += 1
            print(f"{self.name} ON")

    def off(self):
        if self._state:
            self._state = False
            self._actions += 1
            print(f"{self.name} OFF")

    def toggle(self):
        self._state = not self._state
        self._actions += 1
        print(f"{self.name} {'ON' if self._state else 'OFF'}")

    def is_on(self):
        return self._state

    def action_count(self):
        return self._actions


# =======================
# VIEW
# =======================
class RelayView(QWidget):
    def __init__(self):
        super().__init__()
        self.setWindowTitle("Relais - MVP")

        self.state_label = QLabel("État: OFF")
        self.count_label = QLabel("Actions: 0")

        self.btn_on = QPushButton("ON")
        self.btn_off = QPushButton("OFF")
        self.btn_toggle = QPushButton("TOGGLE")

        btn_layout = QHBoxLayout()
        btn_layout.addWidget(self.btn_on)
        btn_layout.addWidget(self.btn_off)
        btn_layout.addWidget(self.btn_toggle)

        layout = QVBoxLayout()
        layout.addWidget(self.state_label)
        layout.addWidget(self.count_label)
        layout.addLayout(btn_layout)
        self.setLayout(layout)

    # --- API pour le Presenter ---
    def set_state(self, state: bool):
        self.state_label.setText(f"État: {'ON' if state else 'OFF'}")

    def set_action_count(self, count: int):
        self.count_label.setText(f"Actions: {count}")

    def on_on_clicked(self, callback):
        self.btn_on.clicked.connect(callback)

    def on_off_clicked(self, callback):
        self.btn_off.clicked.connect(callback)

    def on_toggle_clicked(self, callback):
        self.btn_toggle.clicked.connect(callback)


# =======================
# PRESENTER
# =======================
class RelayPresenter:
    def __init__(self, model: Relay, view: RelayView):
        self.model = model
        self.view = view

        # Connexions
        self.view.on_on_clicked(self.turn_on)
        self.view.on_off_clicked(self.turn_off)
        self.view.on_toggle_clicked(self.toggle)

        # Init affichage
        self.refresh_view()

    def turn_on(self):
        self.model.on()
        self.refresh_view()

    def turn_off(self):
        self.model.off()
        self.refresh_view()

    def toggle(self):
        self.model.toggle()
        self.refresh_view()

    def refresh_view(self):
        self.view.set_state(self.model.is_on())
        self.view.set_action_count(self.model.action_count())


# =======================
# MAIN
# =======================
def main():
    app = QApplication(sys.argv)

    relay = Relay("Relais principal")
    view = RelayView()
    presenter = RelayPresenter(relay, view)

    view.show()
    sys.exit(app.exec())


if __name__ == "__main__":
    main()
