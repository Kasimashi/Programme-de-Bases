#!/usr/bin/python3
# coding: utf-8

import mysql.connector

try:
    conn = mysql.connector.connect(host="localhost",user="user",password="user", database="test1")
    cursor = conn.cursor()
    conn.close()

    cursor.execute("""SELECT id, name, age FROM users WHERE id = %s""", ("5",))
    rows = cursor.fetchall()
    for row in rows:
        print('{0} : {1} - {2}'.format(row[0], row[1], row[2]))

except Exception as e:
        print("[Erreur]",e)
        connection.rollback()
finally:
    connection.close()

