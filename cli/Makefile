CC = gcc
CFLAGS = -Wall -Wextra -pedantic -std=gnu90 -ggd3 -c -I../blockchain/v0.3 -L../blockchain/v0.3 -lhblk_blockchain -pthread

SRC0 = $(wildcard *.c)
OBJ0 = $(SRC0:.c=.o)
NAME0 = cli_blockchain_base

.PHONY: oclean clean cli_blockchain_base

clean:
	$(RM) *~ $(NAME0)

oclean:
	$(RM) *~ $(OBJ0)

cli_blockchain_base: cli.h
	$(CC) $(CFLAGS) $(OBJ0) -o $(NAME0)

betty:
	betty *.c *.h
