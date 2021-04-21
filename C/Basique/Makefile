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

all: base1 base2

base1: base1.c
	$(CC) -o $@ $^ $(LDFLAGS)
	
base2: base2.c
	$(CC) -o $@ $^ $(LDFLAGS)

clean:
	rm -rf *.o

mrproper: clean
	rm -rf $(EXEC)
