#!/usr/bin/python3

import turtle
import os
import pygame

try:
    pygame.mixer.init()
    pygame.mixer.music.load("audio.mp3")
    pygame.mixer.music.play()
except:
    print("Pas de son ...")

turtle.tracer(1)  # Turns off screen updates

turtle.title("Mon application")

class Pendu(turtle.Turtle):
    """
    Class pour le jeu du pendu
    """
    __STEP = 50
    __NB_CASE = 8

    etape = 0
    motMystere = "COUCOU" ## Mot à découvrir

    temp = ["_" for i in range(len(motMystere))]

    #temp = reponseVierge(motMystere) ## Mot en cours de découverte
    
    letter = str("")

    def __init__(self): #Constructeur de la classe Pendu

        super().__init__() ## Héritage de Turtle
        print("Constuction de l'objet")
        turtle.color('deep pink')
        turtle.write('Hello!',font=("Verdana", 15, "normal"))
        #self.hideturtle() # On cache le curseur

        self.speed(100)
        print("BIENVENUE AU JEU DU PENDU ! :)")

        ## Dessin de la grille
        for i in range(self.__NB_CASE+1):
            self.penup()
            self.setpos(-(self.__NB_CASE*self.__STEP/2), ((self.__NB_CASE*self.__STEP/2) - (self.__STEP) * i)) # Start horizontal line
            self.pendown()
            self.setpos((self.__NB_CASE*self.__STEP/2), ((self.__NB_CASE*self.__STEP/2) - (self.__STEP) * i)) # End horizontal line

            self.penup()
            self.setpos((-(self.__NB_CASE*self.__STEP/2) + (self.__STEP) * i), (self.__NB_CASE*self.__STEP/2)) # Start vertical line
            self.pendown()
            self.setpos((-(self.__NB_CASE*self.__STEP/2) + (self.__STEP) * i), -(self.__NB_CASE*self.__STEP/2)) # End vertical line
        
    def afficheMessage(self):
        print("On joue avec un mot de {} lettre : {}".format(len(self.temp),self.temp))

    def traitPendu(self):
        self.pensize(10) ## Epaisseur du trait dessin pendu
        if (self.etape==0): # Base
            self.penup()
            self.setpos(-4*self.__STEP, -4*self.__STEP)
            self.pendown()
            self.setpos(self.__STEP, -4*self.__STEP)
            self.penup()
        elif (self.etape==1): #Poutre verticale
            self.penup()
            self.setpos(-2*self.__STEP, -4*self.__STEP)
            self.pendown()
            self.setpos(-2*self.__STEP, 3 * self.__STEP)
            self.penup()
        elif (self.etape==2): # Poutre horizontal
            self.penup()
            self.setpos(-2 * self.__STEP, 3 * self.__STEP)
            self.pendown()
            self.setpos(2 * self.__STEP, 3 * self.__STEP)
            self.penup()
        elif (self.etape==3): # Poutre penchée
            self.penup()
            self.setpos(-2 * self.__STEP, 1 * self.__STEP)
            self.pendown()
            self.setpos(0, 3 * self.__STEP)
            self.penup()
        elif (self.etape==4): # Corde
            self.penup()
            self.setpos(self.__STEP, 3 * self.__STEP)
            self.pendown()
            self.setpos(self.__STEP, 2 * self.__STEP)
            self.penup()
        elif (self.etape==5): #Tête
            self.penup()
            self.setpos(self.__STEP,0)
            self.pendown()
            self.circle(self.__STEP)
            self.penup()
        elif (self.etape==6):#Corps
            self.penup()
            self.setpos(self.__STEP, 0)
            self.pendown()
            self.setpos(self.__STEP, -2 * self.__STEP)
            self.penup()
        elif (self.etape==7):#Jambe gauche
            self.penup()
            self.setpos(self.__STEP, -2 * self.__STEP)
            self.pendown()
            self.setpos(-self.__STEP/2, -3.5 * self.__STEP)
            self.penup()
        elif (self.etape==8):#Jambe droite
            self.penup()
            self.setpos(self.__STEP, -2 * self.__STEP)
            self.pendown()
            self.setpos(2.5 * self.__STEP, -3.5 * self.__STEP)
            self.penup()
        elif (self.etape==9):#Bras droit
            self.penup()
            self.setpos(self.__STEP, - self.__STEP)
            self.pendown()
            self.setpos(2.5 * self.__STEP, 0)
            self.penup()
        elif (self.etape==10):#Bras gauche
            self.penup()
            self.setpos(self.__STEP, - self.__STEP)
            self.pendown()
            self.setpos(-0.5* self.__STEP, 0)
            self.penup()
        self.etape += 1
        self.pensize() ##Reset pensize

    def saisie(self):
        CORRECT = False
        while not(CORRECT): #Tant que c'est pas une lettre:
            self.letter = turtle.textinput("Jeu du pendu", "Proposer une lettre : ") #Avec turtle
            ## self.letter = str(input("Proposer une lettre : ")) #En ligne de console
            CORRECT = self.letter.isalpha() & len(self.letter) == 1
            if not(CORRECT):
                print("Doit être une lettre unique.")

    ### Cette fonction demande au joueur s'il veut recommecer
    def recommencer(self):
        print("Voulez vous recommencer une partie ?! (O/N)")
        CORRECT = False
        while not(CORRECT): #Tant que la réponse n'est pas bonne:
            letter = str(input("Faites votre choix : "))
            letter = letter.upper() ## Mise en majuscule de la lettre
            CORRECT = (letter == 'O') | (letter == 'N')
            if not(CORRECT):
                print("La réponse doit être O ou N")
        if (letter == 'O') :
            return True
        elif (letter == 'N'):
            return False
        else:
            return False

    ### Cette fonction test si la partie est terminé gagné ou non
    def testFin(self):
        if (self.etape==12):
            print("Vous avez perdu ... la bonne réponse était {}".format(self.motMystere))
            return True
        elif ("_" not in self.temp):
            print("Vous avez gagné le mot mystère était {}!".format(self.temp))
            return True
        else:
            return False
            
    ### Cette fonction renvoi un texte "_" en fonction de la longueur du mot mystère
    def reponseVierge(self,motMystere):
        reponse = ""
        for i in range(len(motMystere)):
            reponse+="_"
        return reponse



    ## Cette fonction renvoi l'index des occurences de la lettre donnée en argument
    def look_for_letter(self,motMystere, lettre_saisie):
        return [i for i, ch in enumerate(motMystere) if ch == lettre_saisie]

    ## Cette fonction rajoute une lettre au mot au bon endroit si elle a lieu d'être
    def ajouteLettre(self):
        s = list(self.temp)
        for elm in self.look_for_letter(self.motMystere,self.letter):
            s[elm] = self.letter
        s = "".join(s)
        self.temp = s


    ## Cette fonction regarde si la lettre est présente dans le mot
    def testLettre(self):
        return self.letter in self.motMystere
        
    def clean(self):
        import platform

        self.reset()
        self.ht()
        def clear():  
            if (platform.system() == 'Linux'):
                os.system('clear') #on Windows System
            elif (platform.system() == 'Windows'):
                os.system('cls')
        clear()


    def __del__(self):
        print("Destruction de l'objet")
        turtle.update()
        print("Fin du jeu : Cliquer sur l'image pour quitter")
        turtle.exitonclick()
    # actions 

print("Lancement du programme :")


restart = True
while (restart):
    Jeu = Pendu()
    while not(Jeu.testFin()):
        Jeu.afficheMessage()
        Jeu.saisie()
        if Jeu.testLettre():
            Jeu.ajouteLettre()
        else:
            Jeu.traitPendu() # Ajout d'un trait sur le pendu
        
    restart = Jeu.recommencer()
    Jeu.clean()
    #Jeu.__del__()
