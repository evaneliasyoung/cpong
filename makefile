CC      = gcc
FLAGS   = -g -Wall
POSTS   = -lmingw32 -lSDL2main -lSDL2
OBJECTS = main.o utils.o draw.o game.o

default: cpong.exe

%.o: %.c
	$(CC) $(FLAGS) -c $< -o $@ $(POSTS)

cpong.exe: $(OBJECTS)
	$(CC) $(FLAGS) $(OBJECTS) -o $@ $(POSTS)

clean:
	-rm -f $(OBJECTS)
	-rm -f cpong.exe
