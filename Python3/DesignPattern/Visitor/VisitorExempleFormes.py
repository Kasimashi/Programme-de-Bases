from abc import ABC, abstractmethod
import math

# ======================
# Interface des éléments
# ======================

class Forme(ABC):
    @abstractmethod
    def accept(self, visiteur):
        pass


class Cercle(Forme):
    def __init__(self, rayon):
        self.rayon = rayon

    def accept(self, visiteur):
        return visiteur.visiter_cercle(self)


class Rectangle(Forme):
    def __init__(self, largeur, hauteur):
        self.largeur = largeur
        self.hauteur = hauteur

    def accept(self, visiteur):
        return visiteur.visiter_rectangle(self)


# ======================
# Interface du Visitor
# ======================

class VisiteurForme(ABC):
    @abstractmethod
    def visiter_cercle(self, cercle):
        pass

    @abstractmethod
    def visiter_rectangle(self, rectangle):
        pass


# ======================
# Visitor concret : aire
# ======================

class VisiteurAire(VisiteurForme):
    def visiter_cercle(self, cercle):
        return math.pi * cercle.rayon ** 2

    def visiter_rectangle(self, rectangle):
        return rectangle.largeur * rectangle.hauteur


# ===========================
# Visitor concret : affichage
# ===========================

class VisiteurAffichage(VisiteurForme):
    def visiter_cercle(self, cercle):
        return f"Cercle(rayon={cercle.rayon})"

    def visiter_rectangle(self, rectangle):
        return f"Rectangle({rectangle.largeur}x{rectangle.hauteur})"


# ======================
# Programme principal
# ======================

def main():
    formes = [
        Cercle(2),
        Rectangle(3, 4),
        Cercle(5)
    ]

    visiteur_aire = VisiteurAire()
    visiteur_affichage = VisiteurAffichage()

    for forme in formes:
        print(forme.accept(visiteur_affichage))
        print("Aire =", forme.accept(visiteur_aire))
        print("-" * 20)


if __name__ == "__main__":
    main()
