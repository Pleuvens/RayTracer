CC=gcc
CFLAGS= -std=c99 -Wall -Wextra -Werror -pedantic

SRC=

rt:
		$(CC) $(CFLAGS) $(SRC) -o rt

all: rt

clean:
			$(RM) rt
