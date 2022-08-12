Pour importer une bibliothèque interne développé dans un autre dossier :

Il faut créer un fichier __init__.py à la racine du module.
Son contenu peut être vide ou importer les libraries internes comme par exemple:

```
# __init__.py
from .stringLength import stringLength
from .stringToLower import stringToLower
from .stringToUpper import stringToUpper
```

from application.app.folder.file import func_name

L’exemple de code ci-dessous montre comment importer le module à partir du package parent.

from ..parent_directory import mymodule
Pour importer le module à partir du répertoire deux niveaux ci-dessus à partir du répertoire courant, nous devrons mettre trois points avant le nom du répertoire du package pour remonter de deux niveaux, comme indiqué dans l’exemple de code ci-dessous.

from ...parent_parent_directory import mymodule

Source : 
* https://timothybramlett.com/How_to_create_a_Python_Package_with___init__py.html
* https://www.delftstack.com/fr/howto/python/python-import-from-parent-directory/