# x86

La famille x86 regroupe les microprocesseurs compatibles avec le jeu d'instructions de l'Intel 8086.
Le nom « x86 » est un terme générique pour la famille de processeurs Intel, le "x" correspondant à plusieurs valeurs, depuis le 8086, en passant par 80286, 80386 ou 80486.

La conception de la gamme x86 a mis l'accent sur la compatibilité ascendante. Ainsi, les générations successives de processeurs admettent plusieurs modes de fonctionnement, qui diffèrent en particulier du point de vue de l'accès à la mémoire.

Les logiciels pensés en 32 bits (i386) fonctionnent donc sur une architecture 64 bits (AMD64).

# Compilation d'un fichier assembleur Intelx86/Intelx64 avec Linux :

Pour cette étape, vous aurez besoin du logiciel nasm installé sur votre machine. Si vous êtes sous Debian ou Ubuntu, il suffit de taper la commande
```
sudo apt-get install nasm
```

Passons maintenant à l'assemblage de votre fichier source.
Rendez vous en ligne de commande dans le repertoire ou se situe votre fichier source que nous allons appeler test.asm pour l'exemple. Voici la ligne à taper:

Pour compiler en 32 bits :

```
nasm -f elf32 <MonFichier>.asm -o <MonFichier>.o
```
Pour compiler en 64 bits :
```
nasm -f elf64 <MonFichier>.asm -o <MonFichier>.o
```

Ceci créera un fichier nommé test.o dans le repertoire courant. 
```
file helloworld.o
helloworld.o: ELF 32-bit LSB relocatable, Intel 80386, version 1 (SYSV), not stripped
```
ou
```
file helloworld_64.o 
helloworld_64.o: ELF 64-bit LSB relocatable, x86-64, version 1 (SYSV), not stripped
```

Ce fichier est un executable 32 bits/64 bits (suivant le format choisis) qui n'est pas encore exécutable, ce n'est encore qu'un fichier objet, c'est à dire un fichier qu'il faut lier avec les bibliothèques dont il dépend comme par exemple la libraire standard libc.

Maintenant que nous avons notre fichier objet nommé test.o nous allons créer notre executable.
Deux cas se présentent ici:
- Votre programme débute avec une procédure nommée "_start". Celà signifie que votre programme possède son propre point d'entrée sans utiliser de fonction main. Ca ne change pas grand chose, toutefois vous aurez besoin d'utiliser la commande "ld" pour créer votre executable:

Pour 32 bits :
```
ld -m elf_i386 <MonFichier>.o -o <MonProgramme>
```
Pour 64 bits :
```
ld <MonFichier>.o -o <MonProgramme>
```

On vérifie le type de fichier :
```
└──╼ $file helloworld
helloworld: ELF 32-bit LSB executable, Intel 80386, version 1 (SYSV), statically linked, not stripped
┌─[kasi@parrot]─[~/Desktop/Programme-de-Bases/Assembler/x86/Linux]
└──╼ $file helloworld_64
helloworld_64: ELF 64-bit LSB executable, x86-64, version 1 (SYSV), statically linked, not stripped
```

- Votre programme débute avec une procédure nommée "main". Vous aurez donc besoin d'utiliser gcc pour créer votre executable:
```
gcc test.o -o test
```


On peut ainsi executer le programme.

## Références :
https://trailofbits.github.io/ctf/vulnerabilities/references/X86_Win32_Reverse_Engineering_Cheat_Sheet.pdf
