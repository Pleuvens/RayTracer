CC=clang++
CFLAGS= -std=c++17 -g -Wall -Wextra -Werror -pedantic

SRC= utils/color.cc utils/vector3.cc camera/camera.cc \
lights/light.cc lights/ambient_light.cc lights/directional_light.cc \
lights/point_light.cc material/material.cc objects/triangle.cc \
objects/object.cc raytracer/ray.cc scene/scene.cc \
input/parser.cc input/svati_parser.cc main.cc

all: rt

clean:
		$(RM) -rf rt vgcore.* *.o

rt:
		$(CC) $(CFLAGS) $(SRC) -o rt