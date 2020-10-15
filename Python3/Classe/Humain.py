#!/usr/bin/python3

class Humain:
    """
    Classe des êtres humains
    """

    humains_crees = 0
    
    def __init__(self, c_prenom,c_age): #Constructeur de la classe Humain
        print("Création d'un Humain en mémoire à l'adresse : ", self)
        self.prenom = c_prenom
        self.age = c_age
        Humain.humains_crees +=1
        #pass

print("Lancement du programme :")

h1 = Humain("Serge",45)
print("Prénom de h1 -> {} humain existant : {}".format(h1.prenom,Humain.humains_crees))
h2 = Humain("Clement",23)
h2.prenom = "Jean Paul"
print("Prénom de h2 -> {} humain existant :{}".format(h2.prenom,Humain.humains_crees))
