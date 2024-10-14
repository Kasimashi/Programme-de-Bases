#!/usr/bin/python3
class Person:
    def __init__(self, name, old, country):
        self.name = name
        self.country = country
        self.old = old


class Banker(Person):
    def __init__(self, name, old, country):
        super().__init__(name, old, country)  # Faire référence à la classe mère avec super.__init__();
        # Person.__init__(self,name, old,country) # Même chose que ligne précédente.

class CEOBank(Banker):
    def __init__(self, name, old, country):
        super().__init__(name, old, country)

Banquier = Banker("Luc", 20, "United Kingdom")
print(Banquier.name)
print(Banquier)
Personne = Person(name="Serge", old=30, country="France")
print(Personne)

CEO = CEOBank(name="Tom", old=35, country="USA")
print(CEO)