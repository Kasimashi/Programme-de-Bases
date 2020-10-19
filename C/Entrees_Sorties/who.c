
/*
La commande who permet de savoir qui est connecté :

  vagrant@precise32:~$ who
    vagrant  pts/0        2016-10-25 10:14 (10.0.2.2)
    vagrant  pts/1        2016-10-25 10:29 (10.0.2.2)
  vagrant@precise32:~$

(Si la commande who pose problème, essayez donc la commande ps)

Le deuxième mot de chaque ligne représente le terminal.
Il suffit donc de rediriger la sortie de la commande
lancée sur le premier terminal vers le second, exemple :

  vagrant@precise32:~$ date > /dev/pts/1
*/
