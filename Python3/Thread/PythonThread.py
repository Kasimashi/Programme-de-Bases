import threading
import time
import serial
from flask import Flask


# Classe pour le serveur COM sur le port série (Thread 1)
class ServerCOM:
    def __init__(self, port='COM1', baudrate=9600):
        self.port = port
        self.baudrate = baudrate
        self.ser = None

    def run(self):
        try:
            # Ouverture du port série
            self.ser = serial.Serial(self.port, self.baudrate, timeout=1)
            print(f"Serveur COM démarré sur le port {self.port}")

            while True:
                if self.ser.in_waiting > 0:
                    data = self.ser.readline().decode('utf-8').strip()
                    print(f"Reçu depuis COM: {data}")
                    # Réponse du serveur COM
                    self.ser.write(f"Réponse à: {data}\n".encode('utf-8'))
        except serial.SerialException as e:
            print(f"Erreur avec le port série: {e}")
        except KeyboardInterrupt:
            print("Arrêt du serveur COM.")
        finally:
            if self.ser and self.ser.is_open:
                self.ser.close()  # Assurez-vous que le port série est fermé correctement


# Classe pour le serveur HTTP 1 (Thread 2)
class ServerHTTP1:
    def __init__(self):
        self.app = Flask(__name__)

    def run(self):
        @self.app.route('/')
        def home():
            return "Serveur HTTP 1 : Page d'accueil"

        self.app.run(host='0.0.0.0', port=5000, threaded=True)  # Serveur 1 sur le port 5000


# Classe pour le serveur HTTP 2 (Thread 3)
class ServerHTTP2:
    def __init__(self):
        self.app = Flask(__name__)

    def run(self):
        @self.app.route('/status')
        def status():
            return "Serveur HTTP 2 : Page de statut"

        self.app.run(host='0.0.0.0', port=5001, threaded=True)  # Serveur 2 sur le port 5001


# Fonction principale pour démarrer les serveurs dans des threads distincts
def main():
    # Création des objets des serveurs
    server_com = ServerCOM(port='COM1', baudrate=9600)  # Server COM
    server_http_1 = ServerHTTP1()  # Server HTTP 1
    server_http_2 = ServerHTTP2()  # Server HTTP 2

    # Création des threads avec noms
    thread_com = threading.Thread(target=server_com.run, daemon=True, name="Thread-Serveur-COM")
    thread_http_1 = threading.Thread(target=server_http_1.run, daemon=True, name="Thread-Serveur-HTTP-1")
    thread_http_2 = threading.Thread(target=server_http_2.run, daemon=True, name="Thread-Serveur-HTTP-2")

    # Démarrage des threads
    thread_com.start()
    thread_http_1.start()
    thread_http_2.start()

    # Affichage des threads actifs dans la boucle principale
    try:
        while True:
            time.sleep(1)  # Programme principal reste actif
            active_threads = threading.enumerate()  # Liste des threads actifs
            print("Threads actifs :", [thread.name for thread in active_threads])
    except KeyboardInterrupt:
        print("Arrêt du programme principal.")


if __name__ == "__main__":
    main()
