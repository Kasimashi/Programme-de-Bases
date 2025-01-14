import queue
import random
import threading
import time
from flask import Flask, request, jsonify
import requests


# Classe pour le Worker LRC2AS
class ThingParkLRC2AS(threading.Thread):
    def __init__(self, incomingMsgQueue):
        super().__init__()
        self.incomingMsgQueue: queue.Queue = incomingMsgQueue

    def run(self):
        print("Start worker")
        while True:
            try:
                # Extraction et traitement des messages de la queue
                data = self.incomingMsgQueue.get(timeout=30)
                # Simulation d'un traitement
                # Générer un temps d'attente aléatoire entre 1 et 10 secondes
                delay = random.uniform(1, 10)

                print(f"Attente de {delay:.2f} secondes...")
                time.sleep(delay)

                print(f"Worker process data: {data}")
            except queue.Empty:
                break  # Arrête si aucune donnée n'est reçue dans un délai donné

            # Génération aléatoire du statut
            status = random.choice(["sent", "error"])
            response_message = {"status": status, "data": data}
            try:
                requests.post(f"http://127.0.0.1:5001/reports", json=response_message)
            except requests.exceptions.RequestException as e:
                pass


# Classe pour le serveur AS2LRC
class ThingParkAS2LRC(threading.Thread):
    def __init__(self, port, incomingMsgQueue):
        super().__init__()
        self.incomingMsgQueue: queue.Queue = incomingMsgQueue
        self.port = port
        self.app = Flask(__name__)
        self.queue = queue.Queue()

        @self.app.route('/send', methods=['POST'])
        def receive_data():
            data = request.json
            response_message = {"status": "enqueue", "data": data}
            # simulation d'un traitement ...
            print(f"LRC data enqueue {data}")
            self.incomingMsgQueue.put(data)
            # Si un serveur cible est configuré, envoie une requête POST
            return jsonify(response_message), 200

    def run(self):
        self.app.run(port=self.port, debug=False, use_reloader=False)


# Classe pour le serveur Flask (report)
class FlaskServerThread(threading.Thread):
    def __init__(self, port, message_status_queue):
        super().__init__()
        self.port = port
        self.app = Flask(__name__)
        self.message_status_queue = message_status_queue  # Queue pour les statuts des messages

        @self.app.route('/reports', methods=['POST'])
        def receive_data():
            data = request.json
            print(f"Local received data {data}")
            self.message_status_queue.put(data)


            return jsonify({"status": "sent", "message": "Successfully processed"}), 200

    def run(self):
        self.app.run(port=self.port, debug=False, use_reloader=False)


# Classe pour le client
class ClientThread(threading.Thread):
    def __init__(self, message_status_queue):
        super().__init__()
        self.message_status_queue = message_status_queue
        self.messages = [{"message": f"Hello {i}"} for i in range(5)]  # Messages à envoyer

    def run(self):

        # Traiter chaque message séquentiellement
        for message in self.messages:
            # Envoyer un message et attendre sa réponse
            self.send_message(message)

            while True:
                messageObj = self.message_status_queue.get(True)
                message = messageObj["data"]
                status = messageObj["status"]

                if status != "error":
                    break  # Sortir de la boucle si le statut n'est pas "error"

                # Si le statut est "error", renvoyer le message
                print(f"Retrying message due to error: {message}")
                self.send_message(message)

    def send_message(self, data):
        try:
            print(f"Sent to Thingpark: {data}")
            response = requests.post(f"http://127.0.0.1:5000/send", json=data)
            print(f"Thingpark responded: {response.json()}")
        except requests.exceptions.RequestException as e:
            print(f"Request to Server 1 failed: {e}")


# Main
if __name__ == "__main__":
    # Crée les queues
    incomingMsgQueue = queue.Queue()
    message_status_queue = queue.Queue()  # Queue pour les statuts des messages

    # Crée les threads
    AS2LRC = ThingParkAS2LRC(port=5000, incomingMsgQueue=incomingMsgQueue)
    LRC2AS = ThingParkLRC2AS(incomingMsgQueue=incomingMsgQueue)
    local_server = FlaskServerThread(port=5001, message_status_queue=message_status_queue)
    local_client = ClientThread(message_status_queue=message_status_queue)

    # Lance les threads
    AS2LRC.start()
    LRC2AS.start()
    local_server.start()
    local_client.start()

    # Attend que les threads se terminent
    LRC2AS.join()
    local_client.join()
    AS2LRC.join()
    local_server.join()
