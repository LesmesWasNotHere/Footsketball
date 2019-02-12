
CC=g++
CFLAGS=-I .

Footsketball: src/Main.cpp obj/GameObject.o obj/Animation.o
	$(CC) -o $@ $? -lSDL2
	
obj/GameObject.o: src/GameObject.cpp src/GameObject.h
	$(CC) -c -o $@ src/GameObject.cpp 

obj/Animation.o: src/Animation.cpp src/Animation.h
	$(CC) -c -o $@ src/Animation.cpp

clean:
	rm -Rf obj/* Footsketball