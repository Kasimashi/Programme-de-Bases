from abc import ABC, abstractmethod
import json
import sys
from PyQt6.QtWidgets import (
    QApplication, QWidget, QVBoxLayout, QLabel,
    QLineEdit, QPushButton
)
from PyQt6.QtCore import QObject, pyqtSignal


# ======================
# MODEL (avec Visitor)
# ======================

class Champ(ABC):
    def __init__(self, nom):
        self.nom = nom

    @abstractmethod
    def accepter(self, visiteur):
        pass


class ChampTexte(Champ):
    def __init__(self, nom, valeur=""):
        super().__init__(nom)
        self.valeur = valeur

    def accepter(self, visiteur):
        return visiteur.visiter_champ_texte(self)


class ChampNombre(Champ):
    def __init__(self, nom, valeur=0):
        super().__init__(nom)
        self.valeur = valeur

    def accepter(self, visiteur):
        return visiteur.visiter_champ_nombre(self)


class Formulaire:
    def __init__(self):
        self.champs = []

    def ajouter_champ(self, champ):
        self.champs.append(champ)

    def accepter(self, visiteur):
        return visiteur.visiter_formulaire(self)


# ======================
# VISITOR abstrait
# ======================

class VisiteurFormulaire(ABC):
    @abstractmethod
    def visiter_formulaire(self, formulaire):
        pass

    @abstractmethod
    def visiter_champ_texte(self, champ):
        pass

    @abstractmethod
    def visiter_champ_nombre(self, champ):
        pass


# ======================
# VISITOR : validation
# ======================

class VisiteurValidation(VisiteurFormulaire):
    def __init__(self):
        self.erreurs = []

    def visiter_formulaire(self, formulaire):
        self.erreurs.clear()
        for champ in formulaire.champs:
            champ.accepter(self)
        return self.erreurs

    def visiter_champ_texte(self, champ):
        if not champ.valeur.strip():
            self.erreurs.append(f"{champ.nom} est vide")

    def visiter_champ_nombre(self, champ):
        if champ.valeur < 0:
            self.erreurs.append(f"{champ.nom} doit être >= 0")


# ======================
# VISITOR : export JSON
# ======================

class VisiteurExportJSON(VisiteurFormulaire):
    def __init__(self):
        self.data = {}

    def visiter_formulaire(self, formulaire):
        self.data.clear()
        for champ in formulaire.champs:
            champ.accepter(self)
        return json.dumps(self.data, indent=2, ensure_ascii=False)

    def visiter_champ_texte(self, champ):
        self.data[champ.nom] = champ.valeur

    def visiter_champ_nombre(self, champ):
        self.data[champ.nom] = champ.valeur


# ======================
# VIEWMODEL (MVVM)
# ======================

class FormulaireViewModel(QObject):
    validation_changed = pyqtSignal(str)
    json_changed = pyqtSignal(str)

    def __init__(self, formulaire):
        super().__init__()
        self.formulaire = formulaire

    def mettre_a_jour_nom(self, texte):
        self.formulaire.champs[0].valeur = texte

    def mettre_a_jour_age(self, texte):
        self.formulaire.champs[1].valeur = int(texte) if texte.isdigit() else -1

    def valider(self):
        visitor = VisiteurValidation()
        erreurs = self.formulaire.accepter(visitor)
        self.validation_changed.emit("\n".join(erreurs) or "Formulaire valide ✔")

    def exporter_json(self):
        visitor = VisiteurExportJSON()
        json_str = self.formulaire.accepter(visitor)
        self.json_changed.emit(json_str)


# ======================
# VIEW (Qt)
# ======================

class FormulaireView(QWidget):
    def __init__(self, vm):
        super().__init__()
        self.vm = vm
        self.setWindowTitle("MVVM + Visitor (PyQt6)")

        layout = QVBoxLayout()

        self.nom_edit = QLineEdit()
        self.age_edit = QLineEdit()

        self.label_validation = QLabel()
        self.label_json = QLabel()

        bouton_valider = QPushButton("Valider")
        bouton_export = QPushButton("Exporter JSON")

        layout.addWidget(QLabel("Nom :"))
        layout.addWidget(self.nom_edit)
        layout.addWidget(QLabel("Âge :"))
        layout.addWidget(self.age_edit)
        layout.addWidget(bouton_valider)
        layout.addWidget(bouton_export)
        layout.addWidget(QLabel("Validation :"))
        layout.addWidget(self.label_validation)
        layout.addWidget(QLabel("JSON :"))
        layout.addWidget(self.label_json)

        self.setLayout(layout)

        # Bindings
        self.nom_edit.textChanged.connect(vm.mettre_a_jour_nom)
        self.age_edit.textChanged.connect(vm.mettre_a_jour_age)
        bouton_valider.clicked.connect(vm.valider)
        bouton_export.clicked.connect(vm.exporter_json)

        vm.validation_changed.connect(self.label_validation.setText)
        vm.json_changed.connect(self.label_json.setText)


# ======================
# MAIN
# ======================

def main():
    app = QApplication(sys.argv)

    formulaire = Formulaire()
    formulaire.ajouter_champ(ChampTexte("nom"))
    formulaire.ajouter_champ(ChampNombre("age"))

    vm = FormulaireViewModel(formulaire)
    view = FormulaireView(vm)
    view.show()

    sys.exit(app.exec())


if __name__ == "__main__":
    main()
