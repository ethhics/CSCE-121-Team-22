CC = g++
CFLAGS = -std=c++17 -Wall -Wextra -pedantic
LIBS = -lfltk -lfltk_images
SRC = $(wildcard src/*cpp)
OBJ = $(SRC:.cpp=.o)

all: $(SRC) PROJECT

PROJECT: $(OBJ)
	$(CC) build/$(OBJ:src/%=%) build/DEPENDENCIES.a -o bin/PROJECT $(LIBS)

.cpp.o:
	$(CC) $(CFLAGS) -c $< -o build/$(@:src/%=%)

clean:
	rm -f build/*o

rebuild: clean all
