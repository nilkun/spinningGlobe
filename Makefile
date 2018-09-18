SOURCEFILES= EarthDemo.cpp SpinningEarth.cpp Factory.o
# SOURCEFILES= main.o GameRenderer.o Grid.o Tile.o Debug.o EventHandler.o Unit.o GameUI.o Factory.o Game.o Player.o Settlement.o 
GAMEENGINE=../gameEngine/rendering.o ../gameEngine/viewport.o ../gameEngine/collisionDetection.o ../gameEngine/CreatorTools.o ../gameEngine/fileManager.o ../gameEngine/initialization.o 
UPDATING=
TARGETFILE=globe
LFLAGS= -Wall
CFLAGS=-lSDL2 -lSDL2_image -lSDL2_gfx -lSDL2_ttf
COMPILER=g++
all:
	$(COMPILER) $(LFLAGS) -o $(TARGETFILE) $(SOURCEFILES) $(GAMEENGINE) $(UPDATING) $(CFLAGS)
