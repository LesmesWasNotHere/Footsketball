
CC=g++
CFLAGS=-I .

Footsketball: src/Main.cpp obj/GameObject.o
	$(CC) -o $@ $? -lSDL2
	
obj/GameObject.o: src/GameObject.cpp src/GameObject.h
	$(CC) -c -o $@ src/GameObject.cpp 

clean:
	rm -Rf obj/* Footsketball