from abc import ABC, abstractmethod

# ----- Interface imprimante -----
class Printer(ABC):
    @abstractmethod
    def print(self, content: str):
        pass


# ----- Implémentations -----
class LaserPrinter(Printer):
    def print(self, content: str):
        print(f"Impression laser: {content}")


class InkjetPrinter(Printer):
    def print(self, content: str):
        print(f"Impression jet d'encre: {content}")


# ----- Interfaces annexes -----
class Logger(ABC):
    @abstractmethod
    def log(self, message: str):
        pass


class FileLogger(Logger):
    def log(self, message: str):
        with open("print.log", "a") as f:
            f.write(message + "\n")


class Notifier(ABC):
    @abstractmethod
    def notify(self, message: str):
        pass


class ConsoleNotifier(Notifier):
    def notify(self, message: str):
        print(f"Notification: {message}")


# ----- Service métier -----
class PrintService:
    def __init__(self, printer: Printer, logger: Logger, notifier: Notifier):
        self.printer = printer
        self.logger = logger
        self.notifier = notifier

    def print_document(self, content: str):
        self.printer.print(content)
        self.logger.log(content)
        self.notifier.notify("Document imprimé")


# ----- Utilisation -----
if __name__ == "__main__":
    printer = LaserPrinter()      # interchangeable
    logger = FileLogger()
    notifier = ConsoleNotifier()

    service = PrintService(printer, logger, notifier)
    service.print_document("Bonjour SOLID")
