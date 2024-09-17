# Python

## Mots clés

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
