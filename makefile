CC = g++
CFLAGS = -std=c++17 -Wall -Wextra -pedantic -fsanitize=address,undefined
LIBFLAGS = -std=c++17
LIBS = -lfltk -lfltk_image

all: build/PROJECT.o build/DEPENDENCIES.o
	$(CC) $(LIBFLAGS) build/PROJECT.o build/DEPENDENCIES.o -o bin/PROJECT

build/PROJECT.o:
	$(CC) $(CFLAGS) -c src/*cpp -o build/PROJECT.o

build/DEPENDENCIES.o:
	$(CC) $(LIBFLAGS) -c include/*cpp $(LIBS) -o build/DEPENDENCIES.o

clean:
	rm -f build/*
