CC = gcc
CFLAGS = -ansi -Wall -pedantic -O2 -lm -lGL -lGLU -lglut

all: List.o Main.o Controller.o Util.o Bullet.o Ship.o Enemy.o Scene.o Section.o Player.o Graphics.o
	$(CC) $? $(CFLAGS) -o game

Main.o: Main.c Main.h Util.h Controller.h Bullet.h Ship.h Enemy.h Player.h Graphics.h
	$(CC) $(CFLAGS) Main.c -c -o Main.o

Controller.o: Controller.c Controller.h Main.h Util.h Bullet.h Ship.h Enemy.h Player.h
	$(CC) $(CFLAGS) Controller.c -c -o Controller.o

Util.o: Util.c Util.h
	$(CC) $(CFLAGS) Util.c -c -o Util.o

List.o: List.c List.h
	$(CC) $(CFLAGS) List.c -c -o List.o

Ship.o: Ship.c List.h Ship.h Scene.h Section.h Player.h Main.h Graphics.h
	$(CC) $(CFLAGS) Ship.c -c -o Ship.o

Bullet.o: Bullet.c Bullet.h List.h Ship.h Enemy.h Util.h Graphics.h
	$(CC) $(CFLAGS) Bullet.c -c -o Bullet.o

Enemy.o: Enemy.c Enemy.h Bullet.h Ship.h Graphics.h
	$(CC) $(CFLAGS) Enemy.c -c -o Enemy.o

Scene.o: Scene.c Scene.h Section.h List.h
	$(CC) $(CFLAGS) Scene.c -c -o Scene.o

Section.o: Section.c Section.h Enemy.h Util.h List.h
	$(CC) $(CFLAGS) Section.c -c -o Section.o

Player.o: Player.c Player.h
	$(CC) $(CFLAGS) Player.c -c -o Player.o

Graphics.o: Graphics.c Graphics.h Util.h Bullet.h Ship.h Enemy.h
	$(CC) $(CFLAGS) Graphics.c -c -o Graphics.o

clean:
	rm *.o game

cleanWindows:
	del *.o game.exe