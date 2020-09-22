#coding:utf-8

import socket

host,port = ('localhost',5566)
socket = socket.socket(socket.AF_INET, socket.SOCK_STREAM)

try:
    socket.connect((host,port))
    print("Client connecté !")
except:
    print("Connection au serveur échouée")
finally:
    socket.close()