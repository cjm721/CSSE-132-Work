# Makefile for echo client and echo server

CC = gcc
CFLAGS = -g #-O -Wall

all: client server

client: client.c
	$(CC) $(CFLAGS) -o client client.c

server: server.c
	$(CC) $(CFLAGS) -o server server.c

clean:
	rm -f *.o client server
