import sys
from PyQt6.QtWidgets import QApplication, QWidget, QPushButton, QLabel, QVBoxLayout


# =======================
# ENTITY
# =======================
class CounterEntity:
    def __init__(self, value=0):
        self.value = value


# =======================
# INTERACTOR
# =======================
class CounterInteractor:
    def __init__(self, entity: CounterEntity):
        self.entity = entity

    def increment(self):
        self.entity.value += 1
        return self.entity.value

    def get_value(self):
        return self.entity.value


# =======================
# ROUTER
# =======================
class CounterRouter:
    def show_message(self, view, text: str):
        view.label.setText(text)  # navigation / affichage simplifié


# =======================
# VIEW
# =======================
class CounterView(QWidget):
    def __init__(self):
        super().__init__()
        self.setWindowTitle("VIPER PyQt6 (1 fichier)")

        self.label = QLabel("0")
        self.button = QPushButton("Incrémenter")

        layout = QVBoxLayout()
        layout.addWidget(self.label)
        layout.addWidget(self.button)
        self.setLayout(layout)

    def on_increment_clicked(self, callback):
        self.button.clicked.connect(callback)


# =======================
# PRESENTER
# =======================
class CounterPresenter:
    def __init__(self, view, interactor, router):
        self.view = view
        self.interactor = interactor
        self.router = router

        self.view.on_increment_clicked(self.handle_increment)
        self.update_view()

    def handle_increment(self):
        value = self.interactor.increment()
        self.router.show_message(self.view, str(value))

    def update_view(self):
        value = self.interactor.get_value()
        self.router.show_message(self.view, str(value))


# =======================
# MAIN (Assembly)
# =======================
if __name__ == "__main__":
    app = QApplication(sys.argv)

    entity = CounterEntity()
    interactor = CounterInteractor(entity)
    router = CounterRouter()
    view = CounterView()
    presenter = CounterPresenter(view, interactor, router)

    view.show()
    sys.exit(app.exec())
