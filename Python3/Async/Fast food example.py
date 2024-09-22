## Reference

import asyncio  # Le module qui nous permet de faire de l'async
from datetime import datetime
"""
Comme nous l'avions dis, une fonction asynchrone est une fonction qui quand elle va bloquer,
va laissé la main à une autre fonction elle-même asynchrone.

Pour indiquer qu'une fonction est asynchrone, on utilise le mot clé async
Pour indiquer qu'une fonction risque de bloquer, on utilise le mot-clé await
"""


"""
La machine à soda est certainement la plus simple. 
Il est possible de verrouiller une ressource de manière à ce qu’une seule tâche puisse y accéder à la fois, 
en utilisant ce que l’on appelle un verrou (asyncio.Lock).
 Plaçons un verrou sur notre machine à soda
 
 Le async with SODA_LOCK signifie que lorsque le serveur arrive à la machine à soda pour y déposer un gobelet :

soit la machine est libre (déverrouillée), auquel cas il peut la verrouiller pour l’utiliser immédiatement,
soit celle-ci est déjà en train de fonctionner, 
auquel cas il attend (de façon asynchrone, donc en rendant la main) que le soda en cours de préparation soit prêt avant de verrouiller la machine à son tour.
"""

SODA_LOCK = asyncio.Lock()
async def preparer_boisson(client:str):
    """
    La fonction qui nous permet de préparer la boisson

    """
    # Acquisition du verrou
    # la syntaxe 'async with FOO' peut être lue comme 'with (yield from FOO)'
    async with SODA_LOCK:
        print(f"{client}: Préparation du soda")
        # Représente le temps où le soda sera versé dans le gobelet, on va pouvoir à ce moment là faire autre chose graçe au mot-clé await
        await asyncio.sleep(3)
        print(f"{client}: Le soda est prêt !")


"""
Passons à la cuisine. Seuls 3 burgers peuvent être fabriqués en même temps. 
Cela peut se modéliser en utilisant un sémaphore (asyncio.Semaphore), qui est une sorte de "verrou multiple". 
On l’utilise pour qu’au plus N tâches puissent exécuter un morceau de code à un instant donné.
"""
BURGER_SEM = asyncio.Semaphore(3)
async def preparer_hamburger(client:str):
    """
    Le async with BURGER_SEM veut dire que lorsqu’une commande est passée en cuisine :
        - soit il y a un cuisinier libre, et celui-ci commence immédiatement à préparer le hamburger,
        - soit tous les cuisiniers sont occupés, auquel cas on attend qu’il y en ait un qui se libère pour s’occuper de notre hamburger.
    """
    async with BURGER_SEM:
        """ La fonction qui nous permet de préparer l'hamburger """
        print(f"{client}: Je prépare le burger")
        # Représente le temps de cuisson du steak, on va pouvoir à ce moment là faire autre chose graçe au mot-clé await
        await asyncio.sleep(5)
        print(f"{client}: L'hamburger est prêt !")


"""
Passons enfin au bac à frites. 
Cette fois, asyncio ne nous fournira pas d’objet magique, donc il va nous falloir réfléchir un peu plus. 
Il faut que l’on puisse l’utiliser une fois pour faire les frites des 5 prochaines commandes. 
Dans ce cas, un compteur semble une bonne idée:

Chaque fois que l’on prend une portion de frites, on décrémente le compteur ;
S’il n’y a plus de frites dans le bac, il faut en refaire.
Mais attention, si les frites sont déjà en cours de préparation, 
il est inutile de lancer une nouvelle fournée !

Dans cet exemple, on place un verrou sur le bac à frites pour qu’un seul serveur puisse y accéder à la fois. 
Lorsqu’un serveur arrive devant le bac à frites, soit celui-ci contient encore des portions de frites, 
auquel cas il en récupère une et retourne immédiatement, soit le bac est vide, 
donc le serveur met des frites à cuire avant de pouvoir en récupérer une portion.
"""

FRIES_COUNTER = 0
FRIES_LOCK = asyncio.Lock()
async def preparer_frite(client:str):
    """ La fonction qui nous permet de préparer les frites """
    global FRIES_COUNTER
    async with FRIES_LOCK:
        if FRIES_COUNTER == 0:
            print(f"{client}: Démarrage de la cuisson des frites")
            # Représente le temps de chauffe des frites, on va pouvoir à ce moment là faire autre chose graçe au mot-clé await
            await asyncio.sleep(5)
            FRIES_COUNTER = 5
        FRIES_COUNTER -= 1
        print(f"{client}: Les frites sont prêtes !")



loop = asyncio.get_event_loop()

# On indique les différentes tâches
client = "client1"
commande = asyncio.gather(preparer_boisson(client), preparer_frite(client), preparer_hamburger(client))
start_time = datetime.now()
# On appel la fonction principal
loop.run_until_complete(commande)

total = datetime.now() - start_time
print("<= Client servi en {}".format(datetime.now() - start_time))