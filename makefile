
CC=g++
CFLAGS=-I .

Footsketball:
	$(CC) -o Footsketball src/Main.cpp -lSDL2
	