"""
On sépare :

Commande

Paiement

Persistance

Notification

On dépend d’abstractions.

✔️ Pourquoi cette version respecte SOLID
Principe	Respecté ?	Pourquoi
SRP	✅	Chaque classe a une responsabilité
OCP	✅	Ajouter un nouveau paiement → nouvelle classe
LSP	✅	Toutes les implémentations respectent leur interface
ISP	✅	Interfaces petites et ciblées
DIP	✅	Dépend d’abstractions, pas de classes concrètes
"""


from abc import ABC, abstractmethod

# ----- Entité -----
class Order:
    def __init__(self, product: str, price: float):
        self.product = product
        self.price = price


# ----- Interfaces (abstractions) -----
class PaymentProcessor(ABC):
    @abstractmethod
    def pay(self, amount: float):
        pass


class OrderRepository(ABC):
    @abstractmethod
    def save(self, order: Order):
        pass


class Notifier(ABC):
    @abstractmethod
    def notify(self, order: Order):
        pass


# ----- Implémentations -----
class CardPayment(PaymentProcessor):
    def pay(self, amount: float):
        print(f"Paiement par carte de {amount}€")


class PaypalPayment(PaymentProcessor):
    def pay(self, amount: float):
        print(f"Paiement PayPal de {amount}€")


class DatabaseOrderRepository(OrderRepository):
    def save(self, order: Order):
        print(f"Commande sauvegardée en base: {order.product}")


class EmailNotifier(Notifier):
    def notify(self, order: Order):
        print(f"Email envoyé pour {order.product}")


# ----- Service métier -----
class OrderService:
    def __init__(
        self,
        payment_processor: PaymentProcessor,
        repository: OrderRepository,
        notifier: Notifier
    ):
        self.payment_processor = payment_processor
        self.repository = repository
        self.notifier = notifier

    def create_order(self, product: str, price: float):
        order = Order(product, price)

        self.payment_processor.pay(price)
        self.repository.save(order)
        self.notifier.notify(order)

        print("Commande créée avec succès")


# ----- Utilisation -----
if __name__ == "__main__":
    payment = CardPayment()       # on peut changer ici sans toucher au service
    repo = DatabaseOrderRepository()
    notifier = EmailNotifier()

    service = OrderService(payment, repo, notifier)
    service.create_order("Livre", 20)
