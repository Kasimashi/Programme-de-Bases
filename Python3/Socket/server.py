#coding:utf-8

import socket
import threading

class ThreadForClient(threading.Thread):
    def __init__(self, conn):
        threading.Thread.__init__(self)
        self.conn = conn

    def run(self) -> None:
        data = self.conn.recv(1024)
        data = data.decode("utf8")
        print(data)

host , port = ('', 5566)

socket = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
socket.bind((host,port))
print("Le serveur est démarré !\n")

while True:
    socket.listen(5)
    conn, address = socket.accept()
    print("Un client vient de se connecter ...")

    my_tread = ThreadForClient(conn)
    my_tread.start() #Afin de lancer la méthode run

conn.close()
socket.close()