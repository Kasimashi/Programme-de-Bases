# Installation d'un serveur mysql sur Linux :
sudo apt-get install mysql-server

## Lancer le service mysql :
service mysql start

## Il faut maintenant se connecter à MySQL :
mysql -u root -p

Créer une base de donnée :
mysql > CREATE DATABASE test1;

## Installer les paquets nécéssaire à la dernière version de Python :
sudo apt-get install python-pip libmysqlclient-dev python-dev python-mysqldb
pip3 install mysql
pip3 install MySQL-python
pip3 install mysql-connector-python --allow-external mysql-connector-python
Pour Python3 :
sudo apt-get install python3-mysql.connector


