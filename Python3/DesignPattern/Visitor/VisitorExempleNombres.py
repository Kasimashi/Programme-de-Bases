from abc import ABC, abstractmethod

# ======================
# Éléments (AST)
# ======================

class Expression(ABC):
    @abstractmethod
    def accepter(self, visiteur):
        pass


class Nombre(Expression):
    def __init__(self, valeur):
        self.valeur = valeur

    def accepter(self, visiteur):
        return visiteur.visiter_nombre(self)


class Addition(Expression):
    def __init__(self, gauche, droite):
        self.gauche = gauche
        self.droite = droite

    def accepter(self, visiteur):
        return visiteur.visiter_addition(self)


class Multiplication(Expression):
    def __init__(self, gauche, droite):
        self.gauche = gauche
        self.droite = droite

    def accepter(self, visiteur):
        return visiteur.visiter_multiplication(self)


# ======================
# Visitor abstrait
# ======================

class VisiteurExpression(ABC):
    @abstractmethod
    def visiter_nombre(self, nombre):
        pass

    @abstractmethod
    def visiter_addition(self, addition):
        pass

    @abstractmethod
    def visiter_multiplication(self, multiplication):
        pass


# ======================
# Visitor : évaluation
# ======================

class VisiteurEvaluation(VisiteurExpression):
    def visiter_nombre(self, nombre):
        return nombre.valeur

    def visiter_addition(self, addition):
        return (addition.gauche.accepter(self) +
                addition.droite.accepter(self))

    def visiter_multiplication(self, multiplication):
        return (multiplication.gauche.accepter(self) *
                multiplication.droite.accepter(self))


# ======================
# Visitor : affichage
# ======================

class VisiteurAffichage(VisiteurExpression):
    def visiter_nombre(self, nombre):
        return str(nombre.valeur)

    def visiter_addition(self, addition):
        return f"({addition.gauche.accepter(self)} + {addition.droite.accepter(self)})"

    def visiter_multiplication(self, multiplication):
        return f"({multiplication.gauche.accepter(self)} * {multiplication.droite.accepter(self)})"


# ======================
# Programme principal
# ======================

def main():
    # (2 + 3) * 4
    expr = Multiplication(
        Addition(Nombre(2), Nombre(3)),
        Nombre(4)
    )

    visiteur_eval = VisiteurEvaluation()
    visiteur_aff = VisiteurAffichage()

    print("Expression :", expr.accepter(visiteur_aff))
    print("Résultat   :", expr.accepter(visiteur_eval))


if __name__ == "__main__":
    main()
