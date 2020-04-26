
CC=g++
CFLAGS=-O0 -g

Footsketball: src/Main.cpp obj/Animation.o obj/AnimationVoid.o obj/Game.o obj/GameCoordinates.o obj/GameObject.o obj/Position.o obj/SDLKeyboardControl.o obj/SDLSpriteCache.o obj/SDLMatchOverlay.o obj/GameSystem.o obj/Scene.o obj/FBStateNormal.o obj/FPStateControlled.o obj/FootsketMatch.o obj/FootsketTeam.o obj/FootsketTeamCabuenes.o obj/FootsketTeamInmaculada.o obj/FootsketPlayer.o obj/FootsketBall.o obj/StateVoid.o obj/FPSCounter.o
	$(CC) $(CFLAGS) -o $@ $^ -lSDL2 -lSDL2_image -lSDL2_ttf 
	
obj/Animation.o: src/Animation.cpp src/Animation.h
	$(CC) $(CFLAGS) -c -o $@ src/Animation.cpp

obj/AnimationVoid.o: src/AnimationVoid.cpp src/AnimationVoid.h
	$(CC) $(CFLAGS) -c -o $@ src/AnimationVoid.cpp

obj/Scene.o: src/Scene.cpp src/Scene.h
	$(CC) $(CFLAGS) -c -o $@ src/Scene.cpp

obj/Game.o: src/Game.h src/Game.cpp
	$(CC) $(CFLAGS) -c -o $@ src/Game.cpp 

obj/GameCoordinates.o: src/GameCoordinates.h src/GameCoordinates.cpp src/Position.h
	$(CC) $(CFLAGS) -c -o $@ src/GameCoordinates.cpp 

obj/GameObject.o: src/GameObject.cpp src/GameObject.h
	$(CC) $(CFLAGS) -c -o $@ src/GameObject.cpp 

obj/Position.o: src/Position.cpp src/Position.h
	$(CC) $(CFLAGS) -c -o $@ src/Position.cpp

obj/SDLKeyboardControl.o: src/SDLKeyboardControl.cpp src/SDLKeyboardControl.h src/IControl.h
	$(CC) $(CFLAGS) -c -o $@ src/SDLKeyboardControl.cpp

obj/SDLSpriteCache.o: src/SDLSpriteCache.cpp src/SDLSpriteCache.h
	$(CC) $(CFLAGS) -c -o $@ src/SDLSpriteCache.cpp

obj/SDLMatchOverlay.o: src/SDLMatchOverlay.cpp src/SDLMatchOverlay.h
	$(CC) $(CFLAGS) -c -o $@ src/SDLMatchOverlay.cpp

obj/GameSystem.o: src/GameSystem.cpp src/GameSystem.h
	$(CC) $(CFLAGS) -c -o $@ src/GameSystem.cpp

obj/FPStateControlled.o: src/FPStateControlled.cpp src/FPStateControlled.h
	$(CC) $(CFLAGS) -c -o $@ src/FPStateControlled.cpp

obj/FBStateNormal.o: src/FBStateNormal.cpp src/FBStateNormal.h
	$(CC) $(CFLAGS) -c -o $@ src/FBStateNormal.cpp

obj/FootsketMatch.o: src/FootsketMatch.cpp src/FootsketMatch.h
	$(CC) $(CFLAGS) -c -o $@ src/FootsketMatch.cpp

obj/FootsketTeam.o: src/FootsketTeam.cpp src/FootsketTeam.h
	$(CC) $(CFLAGS) -c -o $@ src/FootsketTeam.cpp

obj/FootsketTeamCabuenes.o: src/FootsketTeamCabuenes.cpp src/FootsketTeamCabuenes.h
	$(CC) $(CFLAGS) -c -o $@ src/FootsketTeamCabuenes.cpp

obj/FootsketTeamInmaculada.o: src/FootsketTeamInmaculada.cpp src/FootsketTeamInmaculada.h
	$(CC) $(CFLAGS) -c -o $@ src/FootsketTeamInmaculada.cpp

obj/FootsketPlayer.o: src/FootsketPlayer.cpp src/FootsketPlayer.h
	$(CC) $(CFLAGS) -c -o $@ src/FootsketPlayer.cpp

obj/FootsketBall.o: src/FootsketBall.cpp src/FootsketBall.h
	$(CC) $(CFLAGS) -c -o $@ src/FootsketBall.cpp

obj/StateVoid.o: src/StateVoid.cpp src/StateVoid.h
	$(CC) $(CFLAGS) -c -o $@ src/StateVoid.cpp

obj/FPSCounter.o: src/FPSCounter.cpp src/FPSCounter.h
	$(CC) $(CFLAGS) -c -o $@ src/FPSCounter.cpp

clean:
	rm -Rf obj/* Footsketball