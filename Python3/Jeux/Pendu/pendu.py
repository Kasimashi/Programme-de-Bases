import turtle

turtle.tracer(1)  # Turns off screen updates

grid = turtle.Turtle()
grid.speed(100)

STEP = 50
LENGTH = 400

def potence(elements):
   grid.pensize(10)
   if (elements==0): # Base
      grid.penup()
      grid.setpos(-4*STEP, -4*STEP)  # go to start hoz line possition
      grid.pendown()
      grid.setpos(STEP, -4*STEP) # draw horizontal line
      grid.penup()
   elif (elements==1): #Poutre verticale
      grid.penup()
      grid.setpos(-2*STEP, -4*STEP)  # go to start hoz line possition
      grid.pendown()
      grid.setpos(-2*STEP, 3 * STEP)  # draw horizontal line
      grid.penup()
   elif (elements==2): # Poutre horizontal
      grid.penup()
      grid.setpos(-2 * STEP, 3 * STEP) # go to start hoz line possition
      grid.pendown()
      grid.setpos(2 * STEP, 3 * STEP)  # draw horizontal line
      grid.penup()
   elif (elements==3): # Poutre penchée
      grid.penup()
      grid.setpos(-2 * STEP, 1 * STEP)  # go to start hoz line possition
      grid.pendown()
      grid.setpos(0, 3 * STEP)  # draw horizontal line
      grid.penup()
   elif (elements==4): # Corde
      grid.penup()
      grid.setpos(STEP, 3 * STEP)  # go to start hoz line possition
      grid.pendown()
      grid.setpos(STEP, 2 * STEP)
      grid.penup()
   elif (elements==5): #Tête
      grid.penup()
      grid.setpos(STEP,0)  # go to start hoz line possition
      grid.pendown()
      grid.circle(STEP)
      grid.penup()
   elif (elements==6):#Corps
      grid.penup()
      grid.setpos(STEP, 0)  # go to start hoz line possition
      grid.pendown()
      grid.setpos(STEP, -2 * STEP)
      grid.penup()
   elif (elements==7):#Jambe gauche
      grid.penup()
      grid.setpos(STEP, -2 * STEP)  # go to start hoz line possition
      grid.pendown()
      grid.setpos(-STEP/2, -3.5 * STEP)
      grid.penup()
   elif (elements==8):#Jambe droite
      grid.penup()
      grid.setpos(STEP, -2 * STEP)  # go to start hoz line possition
      grid.pendown()
      grid.setpos(2.5 * STEP, -3.5 * STEP)
      grid.penup()
   elif (elements==9):#Bras droit
      grid.penup()
      grid.setpos(STEP, - STEP)  # go to start hoz line possition
      grid.pendown()
      grid.setpos(2.5 * STEP, 0)
      grid.penup()
   elif (elements==10):#Bras gauche
      grid.penup()
      grid.setpos(STEP, - STEP)  # go to start hoz line possition
      grid.pendown()
      grid.setpos(-0.5* STEP, 0)
      grid.penup()


## Dessin de la grille
for i in range(0, LENGTH+STEP, STEP):
   grid.penup()
   grid.setpos(-LENGTH/2, (LENGTH/2 - i)) # go to start hoz line possition
   grid.pendown()
   grid.setpos(LENGTH/2, (LENGTH/2 - i)) # draw horizontal line

   grid.penup()
   grid.setpos((-LENGTH/2 + i), LENGTH/2) # go to start vertical line possition
   grid.pendown()
   grid.setpos((-LENGTH / 2 + i), -LENGTH / 2)

for elements in range(11):

   potence(elements) # Print week


turtle.update() 
turtle.exitonclick()
