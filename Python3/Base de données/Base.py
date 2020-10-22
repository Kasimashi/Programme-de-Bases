#!/usr/bin/python3
# coding: utf-8

###
# Ce programme Python3 sert à afficher le contenu de la base de donnée (localhost) base test1 table personnages et affiche l'ensemble du contenu dans une liste.
###
import mysql.connector

try:
    mydb = mysql.connector.connect(
      host="127.0.0.1",
      user="user",
      password="user",
      database="test1"
    )

    mycursor = mydb.cursor()

    mycursor.execute("SELECT * FROM personnages")

    myresult = mycursor.fetchall()
    
    print(type(myresult))

    for x in myresult:
      print(x)

except Exception as e:
        print("[Erreur]",e)
finally:
    print("Fin")
