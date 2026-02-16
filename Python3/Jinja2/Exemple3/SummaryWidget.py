from PyQt6.QtWidgets import QWidget, QVBoxLayout, QHBoxLayout, QPushButton, QListWidget, QTextEdit, QTreeWidget, QTreeWidgetItem
import os
import subprocess
import sys
from PyQt6.QtWidgets import QApplication
from viewmodel import HouseViewModel

class SummaryWidget(QWidget):
    def __init__(self, viewmodel, output_dir="output"):
        super().__init__()
        self.vm = viewmodel
        self.output_dir = output_dir
        os.makedirs(self.output_dir, exist_ok=True)

        self.setWindowTitle("Summary Generator")
        self.resize(1200, 600)

        # --- Liste des maisons ---
        self.list_widget = QListWidget()
        for item in self.vm.houses:
            self.list_widget.addItem(item.name)

        # --- Zone pour le détail de la maison (QTreeWidget) ---
        self.house_tree = QTreeWidget()
        self.house_tree.setHeaderHidden(True)

        # --- Zone pour le sommaire ---
        self.summary_output = QTextEdit()
        self.summary_output.setReadOnly(True)

        # --- Boutons ---
        self.generate_btn = QPushButton("Régénérer summary")
        self.open_folder_btn = QPushButton("Ouvrir dossier output")

        # --- Connexions ---
        self.generate_btn.clicked.connect(self.show_summary)
        self.open_folder_btn.clicked.connect(self.open_output_folder)
        self.list_widget.currentRowChanged.connect(self.show_object_tree)

        # --- Layout horizontal ---
        left_layout = QVBoxLayout()
        left_layout.addWidget(self.list_widget)
        left_layout.addWidget(self.house_tree)

        right_layout = QVBoxLayout()
        right_layout.addWidget(self.summary_output)
        right_layout.addWidget(self.generate_btn)
        right_layout.addWidget(self.open_folder_btn)

        main_layout = QHBoxLayout()
        main_layout.addLayout(left_layout, 1)
        main_layout.addLayout(right_layout, 2)

        self.setLayout(main_layout)

        # --- Affichage initial ---
        self.show_summary()

    def show_summary(self):
        """
        Génère le summary complet (Markdown), l'affiche et l'exporte
        """
        summary = self.vm.generate_summary()
        self.summary_output.setMarkdown(summary)

        filename = os.path.join(self.output_dir, "summary.md")
        with open(filename, "w", encoding="utf-8") as f:
            f.write(summary)

    def show_object_tree(self, row):
        """
        Affiche n'importe quel objet basé sur un dict ou __dict__ sous forme hiérarchique
        """
        self.house_tree.clear()
        if row < 0:
            return

        obj = self.vm.houses[row]
        self._populate_tree(self.house_tree, obj, root_name=obj.name)

    def _populate_tree(self, tree_widget, obj, root_name="Objet"):
        """
        Fonction récursive pour remplir le QTreeWidget
        """
        def add_item(parent, key, value):
            if isinstance(value, dict):
                item = QTreeWidgetItem(parent, [str(key)])
                for k, v in value.items():
                    add_item(item, k, v)
            elif isinstance(value, list):
                item = QTreeWidgetItem(parent, [str(key)])
                for i, elem in enumerate(value, 1):
                    if isinstance(elem, (dict, list)):
                        add_item(item, f"{i}", elem)
                    else:
                        QTreeWidgetItem(item, [str(elem)])
            else:
                QTreeWidgetItem(parent, [f"{key} : {value}"])

        # Convertit en dict si c'est un objet
        try:
            data = obj.__dict__
        except AttributeError:
            data = {"Valeur": str(obj)}

        root_item = QTreeWidgetItem(tree_widget, [root_name])
        for k, v in data.items():
            add_item(root_item, k, v)

        tree_widget.expandAll()

    def open_output_folder(self):
        """
        Ouvre le dossier output
        """
        path = os.path.abspath(self.output_dir)
        if sys.platform == "win32":
            os.startfile(path)
        elif sys.platform == "darwin":
            subprocess.run(["open", path])
        else:
            subprocess.run(["xdg-open", path])


if __name__ == "__main__":
    app = QApplication(sys.argv)
    vm = HouseViewModel()
    widget = SummaryWidget(vm)
    widget.show()
    sys.exit(app.exec())
