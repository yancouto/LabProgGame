CC = gcc
DEBUG = true

# If SystemRoot, then Windows. Else, *NIX.
ifdef SystemRoot
	# OpenGL pra Windows
	GLFLAGS = -w -Wl,-subsystem,windows -lOpenGL32 -lglu32 -lfreeGLUT
	CLEAN = del *.o game.exe
else
	# OpenGL pra *NIX
	GLFLAGS = -lGL -lGLU -lglut
	CLEAN = rm *.o game
endif

# OpenAL
ALFLAGS = -lopenal32

# Para GDB debugging.
ifeq ($(DEBUG), true)
	CFLAGS = -ansi -Wall -pedantic -lm -g -Wno-unused-result $(GLFLAGS)
else
	CFLAGS = -ansi -Wall -pedantic -lm -O2 -Wno-unused-result $(GLFLAGS)
endif

all: List.o Main.o Controller.o Util.o Bullet.o Ship.o Enemy.o Scene.o Section.o Player.o Vector.o  Graphics.o Camera.o
	$(CC) $? $(CFLAGS) $(ALFLAGS) -o game

Main.o: Main.c Main.h Util.h Controller.h Bullet.h Ship.h Enemy.h Player.h Vector.h Graphics.h Camera.h Vector.h Sound.h
	$(CC) $(CFLAGS) $(ALFLAGS) Main.c -c -o Main.o

Controller.o: Controller.c Controller.h Main.h Util.h Bullet.h Ship.h Enemy.h Player.h Vector.h Graphics.h Camera.h
	$(CC) $(CFLAGS) $(ALFLAGS) Controller.c -c -o Controller.o

Util.o: Util.c Util.h Vector.h
	$(CC) $(CFLAGS) $(ALFLAGS) Util.c -c -o Util.o

List.o: List.c List.h
	$(CC) $(CFLAGS) $(ALFLAGS) List.c -c -o List.o

Ship.o: Ship.c List.h Ship.h Scene.h Section.h Player.h Main.h Vector.h Graphics.h Util.h Controller.h
	$(CC) $(CFLAGS) $(ALFLAGS) Ship.c -c -o Ship.o

Bullet.o: Bullet.c Bullet.h List.h Ship.h Enemy.h Util.h Vector.h Graphics.h
	$(CC) $(CFLAGS) $(ALFLAGS) Bullet.c -c -o Bullet.o

Enemy.o: Enemy.c Enemy.h Bullet.h Ship.h Vector.h Graphics.h Util.h
	$(CC) $(CFLAGS) $(ALFLAGS) Enemy.c -c -o Enemy.o

Scene.o: Scene.c Scene.h Section.h List.h Vector.h
	$(CC) $(CFLAGS) $(ALFLAGS) Scene.c -c -o Scene.o

Section.o: Section.c Section.h Enemy.h Util.h List.h Vector.h
	$(CC) $(CFLAGS) $(ALFLAGS) Section.c -c -o Section.o

Player.o: Player.c Player.h Vector.h
	$(CC) $(CFLAGS) $(ALFLAGS) Player.c -c -o Player.o

Graphics.o: Graphics.c Graphics.h Util.h Bullet.h Ship.h Enemy.h Camera.h
	$(CC) $(CFLAGS) $(ALFLAGS) Graphics.c -c -o Graphics.o

Vector.o: Vector.c Vector.h
	$(CC) $(CFLAGS) $(ALFLAGS) Vector.c -c -o Vector.o

Camera.o: Camera.c Camera.h Ship.h Graphics.h Util.h
	$(CC) $(CFLAGS) $(ALFLAGS) Camera.c -c -o Camera.o

Sound.o: Sound.c Sound.h
	$(CC) $(CFLAGS) $(ALFLAGS) Sound.c -c -o Sound.o

clean:
	$(CLEAN)