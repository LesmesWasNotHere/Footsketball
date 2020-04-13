
CC=g++
CFLAGS=-I .

Footsketball: src/Main.cpp obj/Animation.o obj/AnimationVoid.o obj/Game.o obj/GameCoordinates.o obj/GameObject.o obj/Position.o obj/SDLKeyboardControl.o obj/SDLSpriteCache.o obj/GameSystem.o obj/Scene.o obj/StateControlled.o obj/FootsketMatch.o obj/FootsketTeam.o obj/FootsketTeamCabuenes.o obj/FootsketTeamInmaculada.o obj/FootsketPlayer.o obj/StateVoid.o
	$(CC) -o $@ $^ -lSDL2 -lSDL2_image
	
obj/Animation.o: src/Animation.cpp src/Animation.h
	$(CC) -c -o $@ src/Animation.cpp

obj/AnimationVoid.o: src/AnimationVoid.cpp src/AnimationVoid.h
	$(CC) -c -o $@ src/AnimationVoid.cpp

obj/Scene.o: src/Scene.cpp src/Scene.h
	$(CC) -c -o $@ src/Scene.cpp

obj/Game.o: src/Game.h src/Game.cpp
	$(CC) -c -o $@ src/Game.cpp 

obj/GameCoordinates.o: src/GameCoordinates.h src/GameCoordinates.cpp src/Position.h
	$(CC) -c -o $@ src/GameCoordinates.cpp 

obj/GameObject.o: src/GameObject.cpp src/GameObject.h
	$(CC) -c -o $@ src/GameObject.cpp 

obj/Position.o: src/Position.cpp src/Position.h
	$(CC) -c -o $@ src/Position.cpp

obj/SDLKeyboardControl.o: src/SDLKeyboardControl.cpp src/SDLKeyboardControl.h src/IControl.h
	$(CC) -c -o $@ src/SDLKeyboardControl.cpp

obj/SDLSpriteCache.o: src/SDLSpriteCache.cpp src/SDLSpriteCache.h
	$(CC) -c -o $@ src/SDLSpriteCache.cpp

obj/GameSystem.o: src/GameSystem.cpp src/GameSystem.h
	$(CC) -c -o $@ src/GameSystem.cpp

obj/StateControlled.o: src/StateControlled.cpp src/StateControlled.h
	$(CC) -c -o $@ src/StateControlled.cpp

obj/FootsketMatch.o: src/FootsketMatch.cpp src/FootsketMatch.h
	$(CC) -c -o $@ src/FootsketMatch.cpp

obj/FootsketTeam.o: src/FootsketTeam.cpp src/FootsketTeam.h
	$(CC) -c -o $@ src/FootsketTeam.cpp

obj/FootsketTeamCabuenes.o: src/FootsketTeamCabuenes.cpp src/FootsketTeamCabuenes.h
	$(CC) -c -o $@ src/FootsketTeamCabuenes.cpp

obj/FootsketTeamInmaculada.o: src/FootsketTeamInmaculada.cpp src/FootsketTeamInmaculada.h
	$(CC) -c -o $@ src/FootsketTeamInmaculada.cpp

obj/FootsketPlayer.o: src/FootsketPlayer.cpp src/FootsketPlayer.h
	$(CC) -c -o $@ src/FootsketPlayer.cpp

obj/StateVoid.o: src/StateVoid.cpp src/StateVoid.h
	$(CC) -c -o $@ src/StateVoid.cpp


clean:
	rm -Rf obj/* Footsketball