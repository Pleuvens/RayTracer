CC=gcc
CFLAGS= -g3 -lm -std=c99 -Wall -Wextra -Werror -pedantic -D_GNU_SOURCE

VPATH=raytracer:../

OBJ= input_camera.o input.o str_utils.o input_primitive.o input_light.o \
str_tools.o rt.o output.o scene.o vector3.o color.o light.o

all: rt rmo

rt: $(OBJ)
		$(CC) $(CFLAGS) $(OBJ) -o rt

rmo:
		rm *.o

clean:
		$(RM) rt vgcore.* *.o
