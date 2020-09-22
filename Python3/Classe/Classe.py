#!/usr/bin/python3
#Attention à la portée des variables !
#Pour rendre une variable privée, vous devez faire précéder son nom de deux underscore comme ceci : __var.

class FirstClass:
    
    language = "Python3" #Variable commune à toute les instances de la classe
    #Ici, notre variable language sera accessible partout, sans même instancier la classe. C'est à dire que n'importe où (où cette classe sera accessible), vous pourrez faire FirstClass.language qui vous retournera la chaîne de caractères "Python".
    
    def __init__(self,name): #Définition du constructeur : self est l'instance en lui même : Pour acceder à ses méthodes il faut faire self.method
    # Cependant pour connaitre name, nous devons déjà la préciser, et pour cela, nous devons instancier la classe. Il serait peut-être temps de vous apprendre à le faire ! 
        self.name = name
        
var = FirstClass("Takuma") #On instancie la classe
print (var.name)
print (var.language)

class Identity:
    
    identifier = "Carte d'identité"
    
    def __init__(self,name):
        self.name = name
        self.country = ""
        self.old = 0
        
    def addOld(self,old):
        self.old = old #ajouter une méthode permettant d'ajouter l'âge de la personne. Pour cela, nous allons créer une méthode la même manière que les fonctions que vous créiez en dehors des classes. Celle-ci tout comme le constructeur prendra en premier paramètre notre instance self et en deuxième paramètre l'âge de la personne. Nous lui demanderons ensuite d'affecter cette valeur à notre variable d'instance "old", comme ceci

    def addCountry(self,country):
        self.country = country
        
    def render(self):
        print("Identity : \n\tName: {}\n\tOld: {}\n\tCountry :{}".format(self.name,self.old,self.country))
        
Serge = Identity("Serge")
Serge.addOld(36)
Serge.addCountry("France")
Serge.render()

class Person:
    def __init__(self,name,old,country):
        self.name = name
        self.country = country
        self.old = old
        
class Banker(Person):
    def __init__(self,name,old,country):
        super().__init__(name,old,country)#Faire référence à la classe mère avec super.__init__();
        #Person.__init__(self,name, old,country) # Même chose que ligne précédente.
    
Banquier = Banker("Luc",20,"United Kingdom")
print(Banquier.name)
    
