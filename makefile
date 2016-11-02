CC = g++
CFLAGS = -std=c++17 -Wall -Wextra -pedantic
LIBS = -lfltk -lfltk_images
SRC = $(wildcard src/*cpp)
OBJ = $(SRC:.cpp=.o)
TESTS := $(wildcard src/test/*cpp)

all: $(SRC) PROJECT

PROJECT: $(OBJ)
	$(CC) $(OBJ:src/%=build/%) build/DEPENDENCIES.a -o bin/PROJECT $(LIBS)

.cpp.o:
	$(CC) $(CFLAGS) -c $< -o build/$(@:src/%=%)

clean:
	rm -f build/*o

rebuild: clean all

test: $(TESTS:src/test/%.cpp=bin/%)

bin/%: src/test/%.cpp
	$(CC) $(CFLAGS) $(OBJ:src/%=build/%) build/DEPENDENCIES.a $< -o $@ $(LIBS)

#$(CC) $(OBJ:src/%=build/%) $@ build/DEPENDENCIES.a -o $(@:src/test/%.cpp=bin/%) $(LIBS)
