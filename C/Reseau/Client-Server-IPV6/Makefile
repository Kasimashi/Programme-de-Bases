CC = gcc
CFLAGS =-Wextra -Wall -std=gnu99 -Iinclude -Wno-unused-parameter -Wno-unused-variable -Wno-duplicate-decl-specifier 
LDFLAGS = 

SOURCES = client.c server.c
BINS = client server

OBJS = $(SOURCES:.c=.o)

all: $(BINS) 

client: client.c 
	$(CC) $(CFLAGS) $^ -o $@ $(LDFLAGS) 

server: server.c 
	$(CC) $(CFLAGS) $^ -o $@ $(LDFLAGS)

clean:
	rm -rf $(BINS)
