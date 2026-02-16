from PyQt6.QtWidgets import QWidget, QVBoxLayout, QTextEdit

class HousePreviewWidget(QWidget):
    def __init__(self, viewmodel):
        super().__init__()
        self.vm = viewmodel
        self.setWindowTitle("Prévisualisation Maison")
        self.resize(600, 700)

        # Zone Markdown
        self.preview = QTextEdit()
        self.preview.setReadOnly(True)

        layout = QVBoxLayout()
        layout.addWidget(self.preview)
        self.setLayout(layout)

    def show_house(self, house_index):
        """
        Affiche le Markdown de la maison sélectionnée
        """
        if house_index >= 0 and house_index < len(self.vm.houses):
            house = self.vm.houses[house_index]
            content = self.vm.generate_house_doc(house)
            self.preview.setMarkdown(content)
