CC = gcc
CFLAGS = -Wall -Werror -Wextra -pedantic -I.
LIBS =  -lllist -pthread

RM = rm -f

SRC0 = $(wildcard *.c)
OBJ0 = $(patsubst %.c,%.o,$(SRC0))
NAME0 = cli_visual

.PHONY: all clean oclean cli_visual debug betty

all: cli_visual

clean:
	$(RM) $(NAME0)

oclean:
	$(RM) $(OBJ0)

cli_visual: $(OBJ0)
	$(CC) $(CFLAGS) $(LIBS) $^ -o $@

debug: $(OBJ0)
	$(CC) $(CFLAGS) $(LIBS) $^ -o $@ -g

betty:
	betty *.c *.h
