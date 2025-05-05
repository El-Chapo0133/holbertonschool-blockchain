CC = gcc
CFLAGS = -Wall -Wextra -pedantic -std=gnu90 -ggdb3 -c -I../blockchain/v0.3 -L../blockchain/v0.3 -lhblk_blockchain -pthread

SRC0 = $(wildcard *.c)
OBJ0 = $(SRC0:.c=.o)
NAME0 = cli_blockchain_base

HEADERS = $(wildcard *.h)

.PHONY: oclean clean cli_blockchain_base

all: $(NAME)

clean:
	$(RM) *~ $(NAME0)

oclean:
	$(RM) *~ $(OBJ0)

$(NAME0): $(OBJ0) $(HEADERS)
	$(CC) -o $@ $^ $(CFLAGS)

betty:
	betty *.c *.h
