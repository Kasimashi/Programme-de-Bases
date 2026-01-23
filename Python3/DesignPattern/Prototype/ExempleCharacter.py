import copy

# Prototype
class Character:
    def __init__(self, name, health, attack, skills):
        self.name = name
        self.health = health
        self.attack = attack
        self.skills = skills  # liste de compétences

    def __str__(self):
        return f"{self.name} | HP: {self.health}, ATK: {self.attack}, Skills: {self.skills}"

    # méthode clone
    def clone(self):
        # clone profond pour copier aussi les listes/objets internes
        return copy.deepcopy(self)

# Création des prototypes
warrior_prototype = Character("Guerrier", 150, 20, ["Coup d'épée", "Bouclier"])
mage_prototype = Character("Mage", 100, 25, ["Boule de feu", "Téléport"])

# Cloner un prototype et modifier certaines propriétés
player1 = warrior_prototype.clone()
player1.name = "Arthur"

player2 = mage_prototype.clone()
player2.name = "Merlin"
player2.skills.append("Soin")  # ajout d'une compétence

# Affichage
print(player1)
print(player2)
