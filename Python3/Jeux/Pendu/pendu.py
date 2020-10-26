#!/usr/bin/python3
#coding:utf-8

import turtle

turtle.tracer(1)  # Turns off screen updates

pendu = turtle.Turtle()
pendu.speed(100)

STEP = 50
NB_CASE = 8
def saisie():
    CORRECT = False
    while not(CORRECT): #Tant que c'est pas une lettre:
        letter = str(input("Rentrer une lettre : "))
        CORRECT = letter.isalpha() & len(letter) == 1
        if not(CORRECT):
            print("Doit être une lettre unique.")
    return letter.upper() # Renvoie la lettre en majuscule

def traitPendu(etape):
    pendu.pensize(10) ## Epaisseur du trait dessin pendu
    if (etape==0): # Base
        pendu.penup()
        pendu.setpos(-4*STEP, -4*STEP)
        pendu.pendown()
        pendu.setpos(STEP, -4*STEP)
        pendu.penup()
    elif (etape==1): #Poutre verticale
        pendu.penup()
        pendu.setpos(-2*STEP, -4*STEP)
        pendu.pendown()
        pendu.setpos(-2*STEP, 3 * STEP)
        pendu.penup()
    elif (etape==2): # Poutre horizontal
        pendu.penup()
        pendu.setpos(-2 * STEP, 3 * STEP)
        pendu.pendown()
        pendu.setpos(2 * STEP, 3 * STEP)
        pendu.penup()
    elif (etape==3): # Poutre penchée
        pendu.penup()
        pendu.setpos(-2 * STEP, 1 * STEP)
        pendu.pendown()
        pendu.setpos(0, 3 * STEP)
        pendu.penup()
    elif (etape==4): # Corde
        pendu.penup()
        pendu.setpos(STEP, 3 * STEP)
        pendu.pendown()
        pendu.setpos(STEP, 2 * STEP)
        pendu.penup()
    elif (etape==5): #Tête
        pendu.penup()
        pendu.setpos(STEP,0)
        pendu.pendown()
        pendu.circle(STEP)
        pendu.penup()
    elif (etape==6):#Corps
        pendu.penup()
        pendu.setpos(STEP, 0)
        pendu.pendown()
        pendu.setpos(STEP, -2 * STEP)
        pendu.penup()
    elif (etape==7):#Jambe gauche
        pendu.penup()
        pendu.setpos(STEP, -2 * STEP)
        pendu.pendown()
        pendu.setpos(-STEP/2, -3.5 * STEP)
        pendu.penup()
    elif (etape==8):#Jambe droite
        pendu.penup()
        pendu.setpos(STEP, -2 * STEP)
        pendu.pendown()
        pendu.setpos(2.5 * STEP, -3.5 * STEP)
        pendu.penup()
    elif (etape==9):#Bras droit
        pendu.penup()
        pendu.setpos(STEP, - STEP)
        pendu.pendown()
        pendu.setpos(2.5 * STEP, 0)
        pendu.penup()
    elif (etape==10):#Bras gauche
        pendu.penup()
        pendu.setpos(STEP, - STEP)
        pendu.pendown()
        pendu.setpos(-0.5* STEP, 0)
        pendu.penup()
    pendu.pensize() ##Reset pensize


## Dessin de la grille
for i in range(NB_CASE+1):
    pendu.penup()
    pendu.setpos(-(NB_CASE*STEP/2), ((NB_CASE*STEP/2) - (STEP) * i)) # Start horizontal line
    pendu.pendown()
    pendu.setpos((NB_CASE*STEP/2), ((NB_CASE*STEP/2) - (STEP) * i)) # End horizontal line

    pendu.penup()
    pendu.setpos((-(NB_CASE*STEP/2) + (STEP) * i), (NB_CASE*STEP/2)) # Start vertical line
    pendu.pendown()
    pendu.setpos((-(NB_CASE*STEP/2) + (STEP) * i), -(NB_CASE*STEP/2)) # End vertical line

### Cette fonction renvoi un texte "_" en fonction de la longueur du mot mystère
def reponseVierge(motMystere):
    reponse = ""
    for i in range(len(motMystere)):
        reponse+="_"
    return reponse

etape = 0
motMystere = "COUCOU" ## Mot à découvrir
temp = reponseVierge(motMystere) ## Mot en cours de découverte

## Cette fonction renvoi l'index des occurences de la lettre donnée en argument
def look_for_letter(motMystere, lettre_saisie):
    return [i for i, ch in enumerate(motMystere) if ch == lettre_saisie]

## Cette fonction rajoute une lettre au mot au bon endroit si elle a lieu d'être
def ajouteLettre(temp,motMystere,lettre_saisie):
    s = list(temp)
    for elm in look_for_letter(motMystere,lettre_saisie):
        s[elm] = lettre_saisie
    s = "".join(s)
    return s

## Cette fonction regarde si la lettre est présente dans le mot
def testLettre(motMystere,lettre_saisie):
    return lettre_saisie in motMystere

while (1):
    print("On joue avec un mot de {} lettre : {}".format(len(temp),temp))
    if (etape==12):
        print("Vous avez perdu ...")
        break
    elif ("_" not in temp):
        print("Vous avez gagné le mot mystère était {}!".format(temp))
        break
    lettre_saisie = saisie()
    if testLettre(motMystere,lettre_saisie):
        temp = ajouteLettre(temp,motMystere,lettre_saisie)
    else:
        traitPendu(etape) # Ajout d'un trait sur le pendu
        etape += 1

turtle.update()
print("Cliquer sur l'image pour quitter")
turtle.exitonclick()
