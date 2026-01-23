"""
❌ Problèmes :

Ajout d’une nouvelle imprimante → modification de la classe

Une seule classe = impression + log + stockage + notification

Dépend de détails (open, print, strings)
"""


class PrinterManager:
    def print_document(self, content, printer_type):
        if printer_type == "laser":
            print(f"Impression laser: {content}")
        elif printer_type == "inkjet":
            print(f"Impression jet d'encre: {content}")
        else:
            raise ValueError("Type d'imprimante non supporté")

        # Log
        print("Log: document imprimé")

        # Sauvegarde
        with open("print.log", "a") as f:
            f.write(content + "\n")

        # Notification
        print("Notification envoyée")