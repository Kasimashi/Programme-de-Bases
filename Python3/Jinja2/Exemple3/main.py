import sys
from PyQt6.QtWidgets import QApplication, QWidget, QVBoxLayout, QPushButton, QTextEdit, QListWidget
from viewmodel import HouseViewModel

class MainView(QWidget):
    def __init__(self):
        super().__init__()
        self.vm = HouseViewModel()

        self.setWindowTitle("House Doc Generator")

        self.list = QListWidget()
        for h in self.vm.houses:
            self.list.addItem(h.name)

        self.summary_btn = QPushButton("Générer sommaire")
        self.house_btn = QPushButton("Générer doc maison")
        self.output = QTextEdit()

        layout = QVBoxLayout()
        layout.addWidget(self.list)
        layout.addWidget(self.summary_btn)
        layout.addWidget(self.house_btn)
        layout.addWidget(self.output)
        self.setLayout(layout)

        self.summary_btn.clicked.connect(self.show_summary)
        self.house_btn.clicked.connect(self.show_house_doc)

    def show_summary(self):
        content = self.vm.generate_summary()
        self.output.setText(content)

    def show_house_doc(self):
        row = self.list.currentRow()
        if row >= 0:
            house = self.vm.houses[row]
            content = self.vm.generate_house_doc(house)
            self.output.setText(content)

# ---------- Point d'entrée ----------
if __name__ == "__main__":
    app = QApplication(sys.argv)
    view = MainView()
    view.show()
    sys.exit(app.exec())
