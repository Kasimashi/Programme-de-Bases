import sys
from PyQt6.QtWidgets import (
    QApplication, QMainWindow, QWidget, QVBoxLayout,
    QPushButton, QListWidget, QMenuBar
)
from PyQt6.QtGui import QAction
from viewmodel import HouseViewModel
from SummaryWidget import SummaryWidget
from HousePreviewWidget import HousePreviewWidget  # fenêtre externe

class MainView(QMainWindow):
    def __init__(self):
        super().__init__()
        self.vm = HouseViewModel()
        self.setWindowTitle("House Doc Generator")
        self.resize(800, 600)

        # --- Widget central ---
        central_widget = QWidget()
        self.setCentralWidget(central_widget)

        # --- Liste des maisons ---
        self.list = QListWidget()
        for h in self.vm.houses:
            self.list.addItem(h.name)

        # --- Bouton doc maison ---
        self.house_btn = QPushButton("Générer doc maison")

        # --- Layout simple ---
        layout = QVBoxLayout()
        layout.addWidget(self.list)
        layout.addWidget(self.house_btn)
        central_widget.setLayout(layout)

        # --- Connexions ---
        self.list.currentRowChanged.connect(self.update_house_preview)
        self.house_btn.clicked.connect(self.export_house_doc)

        # --- Menu ---
        menu_bar = QMenuBar()
        self.setMenuBar(menu_bar)
        file_menu = menu_bar.addMenu("Fichier")

        open_summary_action = QAction("Ouvrir SummaryWidget", self)
        open_summary_action.triggered.connect(self.open_summary_widget)
        file_menu.addAction(open_summary_action)

        open_preview_action = QAction("Ouvrir Prévisualisation Maison", self)
        open_preview_action.triggered.connect(self.open_house_preview_widget)
        file_menu.addAction(open_preview_action)

        quit_action = QAction("Quitter", self)
        quit_action.triggered.connect(self.close)
        file_menu.addAction(quit_action)

        # --- Fenêtres externes ---
        self.summary_widget = None
        self.house_preview_widget = None

        # --- Sélection initiale ---
        if self.vm.houses:
            self.list.setCurrentRow(0)

    # --- Méthodes ---
    def update_house_preview(self, row):
        """
        Met à jour la fenêtre externe de prévisualisation Markdown
        """
        if self.house_preview_widget:
            self.house_preview_widget.show_house(row)

    def export_house_doc(self):
        """
        Exporte le doc Markdown de la maison sélectionnée
        """
        row = self.list.currentRow()
        if row >= 0:
            house = self.vm.houses[row]
            content = self.vm.generate_house_doc(house)
            # fichier exporté depuis generate_house_doc si nécessaire

    def open_summary_widget(self):
        if self.summary_widget is None:
            self.summary_widget = SummaryWidget(self.vm)
        self.summary_widget.show()
        self.summary_widget.raise_()

    def open_house_preview_widget(self):
        """
        Ouvre la fenêtre externe de prévisualisation de la maison
        """
        if self.house_preview_widget is None:
            self.house_preview_widget = HousePreviewWidget(self.vm)
        self.house_preview_widget.show()
        self.house_preview_widget.raise_()
        # Affiche la maison actuellement sélectionnée
        current_row = self.list.currentRow()
        self.house_preview_widget.show_house(current_row)


if __name__ == "__main__":
    app = QApplication(sys.argv)
    view = MainView()
    view.show()
    sys.exit(app.exec())
