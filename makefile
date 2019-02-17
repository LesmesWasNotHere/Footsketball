
CC=g++
CFLAGS=-I .

Footsketball: src/Main.cpp obj/Game.o obj/GameCoordinates.o obj/GameObject.o obj/Animation.o obj/SpriteCache.o
	$(CC) -o $@ $? -lSDL2
	
obj/Game.o: src/Game.h src/Game.cpp
	$(CC) -c -o $@ src/Game.cpp 

obj/GameCoordinates.o: src/GameCoordinates.h src/GameCoordinates.cpp
	$(CC) -c -o $@ src/GameCoordinates.cpp 

obj/GameObject.o: src/GameObject.cpp src/GameObject.h
	$(CC) -c -o $@ src/GameObject.cpp 

obj/Animation.o: src/Animation.cpp src/Animation.h
	$(CC) -c -o $@ src/Animation.cpp

obj/SpriteCache.o: src/SpriteCache.cpp src/SpriteCache.h
	$(CC) -c -o $@ src/SpriteCache.cpp

clean:
	rm -Rf obj/* Footsketball