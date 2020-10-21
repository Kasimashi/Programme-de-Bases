Se connecter en tant que utilisateur root :
sudo mysql -u root -p

Lister les bases de données sur le serveur :
CREATE DATABASE 'yourDB';

Lister les bases de données :
SHOW DATABASES;

Utiliser une base de donnée:
use <databasename>

AFFICHER LES TABLES d'une base:
SHOW TABLES;

CREER UNE TABLE :
CREATE TABLE personnages (
id INT(6) UNSIGNED AUTO_INCREMENT PRIMARY KEY,
nom VARCHAR(255),
forcePerso INT,
degats INT,
niveau INT,
experience INT,
reg_date TIMESTAMP DEFAULT CURRENT_TIMESTAMP ON UPDATE CURRENT_TIMESTAMP
)

SUPPRIMER TOUTES LES LIGNES D'UNE TABLE :

TRUNCATE TABLE <databasename>;

Lister les utilisateurs de la base de données :
SELECT User FROM mysql.user;

Créer un utilisateur :
CREATE USER 'user1'@localhost IDENTIFIED BY 'password1';

Supprimer un utilisateur :
DROP USER 'user1'@localhost;

Donner les privilèges  à un utilisateur sur une BDD:
GRANT ALL PRIVILEGES ON 'yourDB'.* TO 'user1'@localhost;

Donner les privilèges à un utilisateur sur toutes les bases :
GRANT ALL PRIVILEGES ON *.* TO 'user1'@localhost IDENTIFIED BY 'password1';

Mettre à jour les privilèges :
FLUSH PRIVILEGES;

Afficher les privilèges :
SHOW GRANTS FOR 'user1'@localhost;
