#!/usr/bin/python3
#coding:utf-8

import turtle

turtle.tracer(1)  # Turns off screen updates

grid = turtle.Turtle()
grid.speed(100)

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
   grid.pensize(10) ## Epaisseur du trait dessin pendu
   if (etape==0): # Base
      grid.penup()
      grid.setpos(-4*STEP, -4*STEP)
      grid.pendown()
      grid.setpos(STEP, -4*STEP)
      grid.penup()
   elif (etape==1): #Poutre verticale
      grid.penup()
      grid.setpos(-2*STEP, -4*STEP)
      grid.pendown()
      grid.setpos(-2*STEP, 3 * STEP)
      grid.penup()
   elif (etape==2): # Poutre horizontal
      grid.penup()
      grid.setpos(-2 * STEP, 3 * STEP)
      grid.pendown()
      grid.setpos(2 * STEP, 3 * STEP)
      grid.penup()
   elif (etape==3): # Poutre penchée
      grid.penup()
      grid.setpos(-2 * STEP, 1 * STEP)
      grid.pendown()
      grid.setpos(0, 3 * STEP)
      grid.penup()
   elif (etape==4): # Corde
      grid.penup()
      grid.setpos(STEP, 3 * STEP)
      grid.pendown()
      grid.setpos(STEP, 2 * STEP)
      grid.penup()
   elif (etape==5): #Tête
      grid.penup()
      grid.setpos(STEP,0)
      grid.pendown()
      grid.circle(STEP)
      grid.penup()
   elif (etape==6):#Corps
      grid.penup()
      grid.setpos(STEP, 0)
      grid.pendown()
      grid.setpos(STEP, -2 * STEP)
      grid.penup()
   elif (etape==7):#Jambe gauche
      grid.penup()
      grid.setpos(STEP, -2 * STEP)
      grid.pendown()
      grid.setpos(-STEP/2, -3.5 * STEP)
      grid.penup()
   elif (etape==8):#Jambe droite
      grid.penup()
      grid.setpos(STEP, -2 * STEP)
      grid.pendown()
      grid.setpos(2.5 * STEP, -3.5 * STEP)
      grid.penup()
   elif (etape==9):#Bras droit
      grid.penup()
      grid.setpos(STEP, - STEP)
      grid.pendown()
      grid.setpos(2.5 * STEP, 0)
      grid.penup()
   elif (etape==10):#Bras gauche
      grid.penup()
      grid.setpos(STEP, - STEP)
      grid.pendown()
      grid.setpos(-0.5* STEP, 0)
      grid.penup()
   grid.pensize() ##Reset pensize


## Dessin de la grille
for i in range(NB_CASE+1):
   grid.penup()
   grid.setpos(-(NB_CASE*STEP/2), ((NB_CASE*STEP/2) - (STEP) * i)) # Start horizontal line
   grid.pendown()
   grid.setpos((NB_CASE*STEP/2), ((NB_CASE*STEP/2) - (STEP) * i)) # End horizontal line

   grid.penup()
   grid.setpos((-(NB_CASE*STEP/2) + (STEP) * i), (NB_CASE*STEP/2)) # Start vertical line
   grid.pendown()
   grid.setpos((-(NB_CASE*STEP/2) + (STEP) * i), -(NB_CASE*STEP/2)) # End vertical line

etape = 0
motMystere = "COUCOU"


def look_for_letter(s, letter):
   return [i for i, ch in enumerate(s) if ch == letter]


def reponseVierge(motMystere):
   reponse = ""
   for i in range(len(motMystere)):
      reponse+="_ "
   return reponse

def ajouteLettre(motMystere):
   reponse = ""
   return reponse

def testLettre():
   return None

while (1):
   if (etape==12):
      print("Vous avez perdu ...")
      break
   #print(reponse)
   lettre_saisie = saisie()
   if lettre_saisie in motMystere:
      print("OK")
      print(look_for_letter(motMystere,lettre_saisie))
   else:
      traitPendu(etape) # Print week
      etape += 1

turtle.update() 
turtle.exitonclick()
