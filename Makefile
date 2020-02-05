CC= g++
CXXFLAGS= -Wall -Wextra -Werror -pedantic -std=c++17 -g

OBJ= \
     scene.o \
     main.o

VPATH= src/

Raytracer: $(OBJ)
	$(CC) $(CXXFLAGS) $(OBJ) -o Raytracer

clean:
	$(RM) $(OBJ) Raytracer
