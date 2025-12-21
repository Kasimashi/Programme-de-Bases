import sys
import sqlite3
from dataclasses import dataclass
from PyQt6.QtWidgets import QApplication, QWidget, QPushButton, QVBoxLayout, QLabel
from PyQt6.QtCore import QObject, pyqtSignal

# === MODEL ===
@dataclass
class RelayData:
    name: str
    state: bool = False

class Relay:
    def __init__(self, data: RelayData, db_manager=None):
        self.data = data
        self.db_manager = db_manager  # optionnel, pour sauvegarde automatique

    def on(self):
        self.data.state = True
        print(f"{self.data.name} ON")
        self._save_state()

    def off(self):
        self.data.state = False
        print(f"{self.data.name} OFF")
        self._save_state()

    def toggle(self):
        self.data.state = not self.data.state
        print(f"{self.data.name} {'ON' if self.data.state else 'OFF'}")
        self._save_state()

    def is_on(self):
        return self.data.state

    def _save_state(self):
        if self.db_manager:
            self.db_manager.update_relay(self.data)


# === DATABASE MANAGER ===
class DBManager:
    """Gestion simple d'une base SQLite locale"""
    def __init__(self, db_file="relays.db"):
        self.conn = sqlite3.connect(db_file)
        self._create_table()

    def _create_table(self):
        cursor = self.conn.cursor()
        cursor.execute("""
            CREATE TABLE IF NOT EXISTS relays (
                id INTEGER PRIMARY KEY AUTOINCREMENT,
                name TEXT UNIQUE,
                state INTEGER
            )
        """)
        self.conn.commit()

    def load_relays(self):
        cursor = self.conn.cursor()
        cursor.execute("SELECT name, state FROM relays")
        rows = cursor.fetchall()
        return [RelayData(name=row[0], state=bool(row[1])) for row in rows]

    def add_relay(self, data: RelayData):
        cursor = self.conn.cursor()
        cursor.execute(
            "INSERT OR IGNORE INTO relays (name, state) VALUES (?, ?)",
            (data.name, int(data.state))
        )
        self.conn.commit()

    def update_relay(self, data: RelayData):
        cursor = self.conn.cursor()
        cursor.execute(
            "UPDATE relays SET state=? WHERE name=?",
            (int(data.state), data.name)
        )
        self.conn.commit()


# === DATA MODEL ===
class RelayManager:
    """Gère plusieurs relais et peut charger depuis DB"""
    def __init__(self, db_manager: DBManager):
        self.relays = []
        self.db_manager = db_manager

    def load_from_db(self):
        data_list = self.db_manager.load_relays()
        self.relays = [Relay(data, db_manager=self.db_manager) for data in data_list]

    def add_relay(self, relay: Relay):
        self.relays.append(relay)
        self.db_manager.add_relay(relay.data)


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

    db = DBManager()  # crée ou ouvre relays.db
    manager = RelayManager(db)
    manager.load_from_db()

    # Si la base est vide, ajouter des relais par défaut
    if not manager.relays:
        default_relays = [
            Relay(RelayData("Relay 1"), db),
            Relay(RelayData("Relay 2"), db),
            Relay(RelayData("Relay 3"), db),
        ]
        for r in default_relays:
            manager.add_relay(r)

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
