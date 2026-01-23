"""
👉 Tout est mélangé : logique métier, persistance, affichage, paiement…
Violation de :

SRP (Single Responsibility)

OCP (Open/Closed)

DIP (Dependency Inversion)

ISP (Interface Segregation)

❌ Problèmes :

Si tu ajoutes un nouveau moyen de paiement → tu modifies la classe

Elle fait trop de choses

Dépend directement de détails concrets (print, type de paiement)
"""
class OrderManager:
    def __init__(self):
        self.orders = []

    def create_order(self, product, price, payment_type):
        order = {"product": product, "price": price}
        self.orders.append(order)

        # Logique de paiement
        if payment_type == "card":
            print("Paiement par carte effectué")
        elif payment_type == "paypal":
            print("Paiement via PayPal effectué")
        else:
            raise ValueError("Type de paiement non supporté")

        # Sauvegarde en base (simulée)
        print("Commande enregistrée en base")

        # Envoi email
        print(f"Email envoyé pour {product}")

        # Affichage
        print(f"Commande créée : {order}")
