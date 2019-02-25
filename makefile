
CC=g++
CFLAGS=-I .

Footsketball: src/Main.cpp obj/Animation.o obj/Game.o obj/GameCoordinates.o obj/GameObject.o obj/Position.o obj/SDLSpriteCache.o
	$(CC) -o $@ $^ -lSDL2 -lSDL2_image
	
obj/Animation.o: src/Animation.cpp src/Animation.h
	$(CC) -c -o $@ src/Animation.cpp

obj/Game.o: src/Game.h src/Game.cpp
	$(CC) -c -o $@ src/Game.cpp 

obj/GameCoordinates.o: src/GameCoordinates.h src/GameCoordinates.cpp src/Position.h
	$(CC) -c -o $@ src/GameCoordinates.cpp 

obj/GameObject.o: src/GameObject.cpp src/GameObject.h
	$(CC) -c -o $@ src/GameObject.cpp 

obj/Position.o: src/Position.cpp src/Position.h
	$(CC) -c -o $@ src/Position.cpp

obj/SDLSpriteCache.o: src/SDLSpriteCache.cpp src/SDLSpriteCache.h
	$(CC) -c -o $@ src/SDLSpriteCache.cpp

clean:
	rm -Rf obj/* Footsketball