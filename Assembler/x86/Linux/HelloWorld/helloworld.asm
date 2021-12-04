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
