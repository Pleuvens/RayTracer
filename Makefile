CC=gcc
CFLAGS= -g3 -std=c99 -Wall -Wextra -Werror -pedantic -D_GNU_SOURCE

SRC= raytracer/input_camera.c raytracer/input.c raytracer/str_utils.c \
raytracer/str_tools.c raytracer/rt.c

rt:
		$(CC) $(CFLAGS) $(SRC) -o rt

all: rt

clean:
			$(RM) rt
