#!/usr/bin/python3

RUM = "RHUM"

print(RUM.upper()) #La fonction upper est une nouveauté pour vous. Vous devez reconnaître le point « . » qui symbolisait déjà, dans le chapitre sur les modules, une relation d'appartenance (a.bsignifiait quebétait contenu dansa). Ici, il possède la même signification : la fonctionlowerest une fonction de la variable RUM.
print(type(RUM)) #vous obtenez<class 'str'>. Nous avons dit qu'une variable est issue d'un type de donnée. Je vais à présent reformuler : un objet est issu d'une classe. La classe est une forme de type de donnée, sauf qu'elle permet de définir des fonctions et variables propres au type. C'est pour cela que, dans toutes les chaînes de caractères, on peut appeler la fonctionlower. C'est tout simplement parce que la fonctionlowera été définie dans la classestr. Les fonctions définies dans une classe sont appelées des méthodes.

print(dir(RUM)) #Affiche les différentes méthodes de la classe 'str'
