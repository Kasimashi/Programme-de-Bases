# Création d'un programme HelloWorld Assembleur

Ce qu'il faut comprendre dans cette exemple est que le registre eax permet de chercher l'instruction C à executer via l'appel d'un "syscall".
Les numéros de syscall sont disponible dans le fichier unistd_32.h
et peut être trouver en tapant la commande :
`locale unistd_32.h` puis faire un cat sur le résultat.

Essayons maintenant de décortiquer le programme assembleur :

```
global _start

section .text ;Définis la partie du programme ou se trouve les instructions à executer.

;Les numéros syscalls sont disponible dans le fichier standart unistd_32.h : il faut se servir de ces numéros pour les mettres dans les registres afin de faire les instructions voulus.
_start:
    ;void write(0x01,message,message_length);
    mov eax, 0x4 ; Correspond par rapport au fichier unistd_32 à l'instruction syscall: write.
    mov ebx, 0x1 ; Correspond au premier argument de la fonction write disponible avec la commande man 2 write ou le manuel c.
    mov ecx, message ; Correspond au second argument de la fonction write c'est à dire le buffer en lui même ou plus précisément l'addresse du buffer.
    mov edx, message_length ; Correspond à la variable count qui donne la taille du buffer à afficher. (ici 0xF = 15) 
    int 0x80 ; int pour interruption et 0x8à est l'identifiant qui indique qu'il faut lancer le syscall.

    ;void exit(int status);
    mov eax, 0x1 ; Correspond par rapport au fichier unistd_32 à l'instruction syscall: exit.
    mov ebx, 0x0 ; Correspond à la variable status (return 0) en c.
    int 0x80 ; int pour interruption et 0x8à est l'identifiant qui indique qu'il faut lancer le syscall.

section .data ; Va être la section ou sont définis les variables du programme les labels etc ...
    message: db "give me a bottle of rum!", 0dh, 0ah ; message est le label de la variable, db correspond à l'accronyme define byte, la virgule permet de rajouter le bytes : 0x0d et le bytes 0x0a qui correspond respectivement au "\r" "\n"
    message_length equ $-message
```

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
