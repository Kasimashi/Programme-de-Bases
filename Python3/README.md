# Python

## Mots clés

### Classes

- `__str__` se concentre sur la lisibilité, sa sortie peut donc sacrifier certains détails pour plus de clarté.
- `__repr__` privilégie l'absence d'ambiguïté, en fournissant une représentation détaillée de l'état de l'objet, incluant souvent toutes les informations pertinentes pour la reconstruction de l'objet.


```python
classe  Point : 
    def  __init__ ( self, x, y ): 
        self.x = x 
        self.y = y 

    def  __str__ ( self ): 
        return  f"Point( {self.x} , {self.y} )" 

    def  __repr__ ( self ): 
        return  f"Point(x= {self.x} , y= {self.y} )" 

# Utilisation
 point = Point( 3 , 4 ) 
print ( str (point))    # Sortie : Point(3, 4) 
print ( repr (point))   # Sortie : Point(x=3, y=4)
```

- Le __dict__ en Python représente un dictionnaire ou tout objet de mappage utilisé pour stocker les attributs de l'objet. Ils sont également connus sous le nom d'objets mappingproxy . Pour faire simple, chaque objet en Python possède un attribut désigné par __dict__. Pour récupérer les attributs __dict__ d'un objet, nous utilisons la fonction intégrée vars() de Python.

- 
### Fonctions

-`lambda arguments : expression`

En Python, le mot-clé lambda est utilisé pour définir des fonctions anonymes, également appelées fonctions lambda.

Les fonctions lambda sont des fonctions qui ne sont pas définies avec un nom, mais qui peuvent être utilisées dans des expressions ou des fonctions.

Elles sont souvent utilisées dans des situations où une fonction simple est nécessaire pour une tâche spécifique, comme trier une liste ou filtrer des éléments.

```
>>> square = lambda x : x ** 2
>>> square(2)
4
```

-`callable`

callable() method returns:

True - if the object appears callable
False - if the object is not callable.
It important to remember that, even if callable() is True, call to the object may still fail.

However, if callable() returns False, call to the object will certainly fail.

```python
x = 5
print(callable(x))

def testFunction():
  print("Test")

y = testFunction
print(callable(y))
```

Output :

```
False
True
```

- `getattr`

The getattr() method returns the value of the named attribute of an object. If not found, it returns the default value provided to the function.

Ex : 

```python
class Person:
    age = 23
    name = "Adam"

person = Person()

# when default value is provided
print('The sex is:', getattr(person, 'sex', 'Male'))

# when no default value is provided
print('The sex is:', getattr(person, 'sex'))
```
