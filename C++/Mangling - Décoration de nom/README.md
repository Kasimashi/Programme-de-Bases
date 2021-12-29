#Attention au Mangling - Décoration de nom en C++

## Sans le extern C :

Si on essai de compiler on obtient le message d'erreur suivant :
````
gcc -c lib.c
g++ -c main.cpp
g++ main.o lib.o
main.o:main.cpp:(.text+0xe): undefined reference to `myfunct()'
collect2.exe: error: ld returned 1 exit status
make: *** [Makefile:4: all] Error 1
```

Si on observe les symboles du fichier .o on observe que notre fonction a été renommé en _Z7myfunctv c'est ce qu'on appelle le mangling. Présent uniquement en C++ il permet de déclarer avec le même nom plusieurs fonctions avec des prototypes differents.

```
nm main.o
0000000000000000 b .bss
0000000000000000 d .ctors
0000000000000000 d .data
0000000000000000 p .pdata
0000000000000000 r .rdata$zzz
0000000000000000 t .text
0000000000000000 r .xdata
                 U __main
000000000000001d t __tcf_0
0000000000000074 t _GLOBAL__sub_I_main
0000000000000038 t _Z41__static_initialization_and_destruction_0ii
                 U _Z7myfunctv
                 U _ZNSt8ios_base4InitC1Ev
                 U _ZNSt8ios_base4InitD1Ev
0000000000000000 b _ZStL8__ioinit
                 U atexit
0000000000000000 T main
```

## Avec le Extern C

Maintenant on rajoute le extern c dans le code autour de l'include. On voit que la fonction n'a pas été renommé au niveaux des symboles.
```
nm main.o
0000000000000000 b .bss
0000000000000000 d .ctors
0000000000000000 d .data
0000000000000000 p .pdata
0000000000000000 r .rdata$zzz
0000000000000000 t .text
0000000000000000 r .xdata
                 U __main
000000000000001d t __tcf_0
0000000000000074 t _GLOBAL__sub_I_main
0000000000000038 t _Z41__static_initialization_and_destruction_0ii
                 U _ZNSt8ios_base4InitC1Ev
                 U _ZNSt8ios_base4InitD1Ev
0000000000000000 b _ZStL8__ioinit
                 U atexit
0000000000000000 T main
                 U myfunct
```
