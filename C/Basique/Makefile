#Les variables interne d'un makefile :
#   $@	Le nom de la cible
#   $<	Le nom de la première dépendance
#   $^	La liste des dépendances
#   $?	La liste des dépendances plus récentes que la cible
#   $*	Le nom du fichier sans suffixe

CC=gcc
CFLAGS=-W -Wall -ansi -pedantic
# Wall enables all compiler's warning messages
LDFLAGS= -lpthread
EXEC=main

all: $(EXEC)

main: main.c
	$(CC) -o $@ $^ $(LDFLAGS)

clean:
	rm -rf *.o

mrproper: clean
	rm -rf $(EXEC)
