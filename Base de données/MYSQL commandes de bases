Se connecter en tant que utilisateur root :
sudo mysql -u root -p

Lister les bases de données sur le serveur :
CREATE DATABASE 'yourDB';

Lister les bases de données :
SHOW DATABASES;

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