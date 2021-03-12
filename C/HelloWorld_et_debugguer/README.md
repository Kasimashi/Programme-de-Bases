# Première approche à GDB

Le but de ce programme est de faire bien entendu un "Hello World" mais aussi de montrer les fonctions que propose un debugguer quelqu'il soit.

## Compilation pour programme en mode debug

Pour compiler un programme avec les options de debug il convient de rajouter un flag spécifique ``` -g ``` qui permet de garder plus d'information dans le binaire et de limiter les optimisations du compilateur pour un debug plus simple.

Ainsi pour compiler notre programme ```hello.c``` nous utiliserons la commande :
```
gcc hello.c -o hello -g
```

Puis pour lancer le debugguer il faut appeler gdb avec en argument le nom de notre programme.

```
gdb hello
```

Je propose de passer directement au vif du sujet pour afficher une interface plus conviviale la commande : (On peut aussi répéter la commande pour afficher d'autres interfaces)
```
layout next
layout prev
```

Permet d'avoir une meilleure vision de ce se qui se passe (plus simple lorsqu'on a les sources)
On obtient ceci :
```
   ┌──hello.c───────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────┐
   │1       #include <stdio.h>                                                                                                                                                  │
   │2                                                                                                                                                                           │
   │3       int main() {                                                                                                                                                        │
   │4                                                                                                                                                                           │
B+>│5          printf("Hello, World!\n");                                                                                                                                       │
   │6          return 0;                                                                                                                                                        │
   │7       }                                                                                                                                                                   │
   │8                                                                                                                                                                           │
   │9                                                                                                                                                                           │
   │10                                                                                                                                                                          │
   │11                                                                                                                                                                          │
   │12                                                                                                                                                                          │
   │13                                                                                                                                                                          │
   │14                                                                                                                                                                          │
   │15                                                                                                                                                                          │
   │16                                                                                                                                                                          │
   │17                                                                                                                                                                          │
   │18                                                                                                                                                                          │
   │19                                                                                                                                                                          │
   │20                                                                                                                                                                          │
   └────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────┘
native process 6116 In: main                                                                                                                            L5    PC: 0x55555555463e 
(gdb) 
```

Pour mettre un breakpoint sur la ligne 5 on rentre ensuite la commande:
```
b 5
```

Pour retirer le breakpoint faire la commande :
```
clear 5
```

Pour lire ensuite instruction par instruction à l'echelle du code faire la commande :
```
next ou n
```

Pour lire ensuite instruction par instruction à l'echelle assembleur faire la commande :
```
s
```

# Liste des commandes

```
list ou l : permet d'afficher le code source lorsqu'il est présent dans le répertoire(nom du programme .c)
set disassembly intel : défini l'architecture de la machine cible
disassemble main : affiche le code assembleur de la fonction main

break main: Met un breakpoint au début de la fonction main
break 10: Met un point d'arrêt sur la ligne 10.

run ou r: lance le programme
continue ou c : continue le mode debug

print i ou p i: affiche la valeur de la variable i

info registers : affiche l'état des registres
p/x $pc : Afficher la valeur du program counter (addresse de la prochaine execution à executer)
x/i $pc : Affiche la prochaine instruction à executer

set $sp += 4 //Ajouter 4 au stack pointeur.

print *arr@10 : Afficher le contenue d'un tableau

quit : quitte GDB.
```

