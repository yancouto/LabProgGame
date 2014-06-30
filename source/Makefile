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

# Para GDB debugging.
ifeq ($(DEBUG), true)
	CFLAGS = -ansi -Wall -pedantic -lm -g -Wextra -Wno-unused-result $(GLFLAGS)
else
	CFLAGS = -ansi -Wall -pedantic -lm -O2 -Wextra -Wno-unused-result $(GLFLAGS)
endif

all: List.o Main.o Controller.o Util.o Bullet.o Ship.o Enemy.o Item.o Scene.o Section.o Player.o Vector.o  Graphics.o Camera.o TextBox.o String.o UserInterface.o
	$(CC) $? $(CFLAGS) -o game

Main.o: Main.c Main.h Util.h Controller.h Bullet.h Ship.h Enemy.h Player.h Vector.h Graphics.h Camera.h Vector.h TextBox.h Item.h UserInterface.h
	$(CC) $(CFLAGS) Main.c -c -o Main.o

Controller.o: Controller.c Controller.h Main.h Util.h Bullet.h Ship.h Enemy.h Player.h Vector.h Graphics.h Camera.h Item.h
	$(CC) $(CFLAGS) Controller.c -c -o Controller.o

Util.o: Util.c Util.h Vector.h
	$(CC) $(CFLAGS) Util.c -c -o Util.o

List.o: List.c List.h
	$(CC) $(CFLAGS) List.c -c -o List.o

Ship.o: Ship.c List.h Ship.h Scene.h Section.h Player.h Main.h Vector.h Graphics.h Util.h Controller.h Item.h
	$(CC) $(CFLAGS) Ship.c -c -o Ship.o

Bullet.o: Bullet.c Bullet.h List.h Ship.h Enemy.h Util.h Vector.h Graphics.h Item.h
	$(CC) $(CFLAGS) Bullet.c -c -o Bullet.o

Enemy.o: Enemy.c Enemy.h Bullet.h Ship.h Vector.h Graphics.h Util.h Player.h Item.h
	$(CC) $(CFLAGS) Enemy.c -c -o Enemy.o

Scene.o: Scene.c Scene.h Section.h List.h Vector.h
	$(CC) $(CFLAGS) Scene.c -c -o Scene.o

Section.o: Section.c Section.h Enemy.h Util.h List.h Vector.h Item.h
	$(CC) $(CFLAGS) Section.c -c -o Section.o

Player.o: Player.c Player.h Vector.h Controller.h
	$(CC) $(CFLAGS) Player.c -c -o Player.o

Graphics.o: Graphics.c Graphics.h Util.h Bullet.h Ship.h Enemy.h Camera.h Item.h UserInterface.h ../resources/spaceship.inc ../resources/bullet.inc ../resources/item_booster.inc ../resources/item_health.inc ../resources/item_life.inc ../resources/enemy.inc
	$(CC) $(CFLAGS) Graphics.c -c -o Graphics.o

Vector.o: Vector.c Vector.h
	$(CC) $(CFLAGS) Vector.c -c -o Vector.o

Camera.o: Camera.c Camera.h Ship.h Graphics.h Util.h Item.h
	$(CC) $(CFLAGS) Camera.c -c -o Camera.o

TextBox.o: TextBox.c TextBox.h String.h List.h Ship.h Vector.h	
	$(CC) $(CFLAGS) TextBox.c -c -o TextBox.o

String.o: String.h String.c
	$(CC) $(CFLAGS) String.c -c -o String.o

Item.o: Item.h Item.c Controller.h
	$(CC) $(CFLAGS) Item.c -c -o Item.o

UserInterface.o: UserInterface.h UserInterface.c
	$(CC) $(CFLAGS) UserInterface.c -c -o UserInterface.o

clean:
	$(CLEAN)