CC = gcc
CFLAGS = -ansi -Wall -pedantic -O2

all: List.o Main.o Controller.o Util.o Bullet.o Ship.o Enemy.o
	$(CC) $? $(CFLAGS) -o game

Main.o: Main.c Main.h Util.h Controller.h Bullet.h Ship.h Enemy.h
	$(CC) $(CFLAGS) Main.c -c -o Main.o

Controller.o: Controller.c Controller.h Main.h Util.h
	$(CC) $(CFLAGS) Controller.c -c -o Controller.o

Util.o: Util.c Util.h
	$(CC) $(CFLAGS) Util.c -c -o Util.o

List.o: List.c List.h
	$(CC) $(CFLAGS) List.c -c -o List.o

Ship.o: Ship.c List.h Ship.h
	$(CC) $(CFLAGS) Ship.c -c -o Ship.o

Enemy.o: Enemy.c Enemy.h
	$(CC) $(CFLAGS) Enemy.c -c -o Enemy.o

Bullet.o: Bullet.c Bullet.h List.h Ship.h Enemy.h
	$(CC) $(CFLAGS) Bullet.c -c -o Bullet.o

clean:
	rm *.o game

cleanWindows:
	del *.o game.exe