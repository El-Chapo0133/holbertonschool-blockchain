CC = gcc
CFLAGS = -Wall -Wextra -pedantic -I.
LIBS = -L. -lhblk_blockchain -lhblk_crypto -lllist -lssl -lcrypto -pthread
CTAGS = ctags
TAGS = .tags

RM = rm -f

SRC0 = $(wildcard *.c)
OBJ0 = $(patsubst %.c,%.o,$(SRC0))
NAME0 = cli

HEADERS = $(wildcard *.h)

.PHONY: all cli oclean clean distclean tags debug betty

all: cli

clean:
	$(RM) $(NAME0)

oclean:
	$(RM) $(OBJ0)

distclean:
	$(RM) $(TAGS)

tags:
	$(CTAGS) -f $(TAGS) -R

cli: $(OBJ0)
	$(CC) $(CFLAGS) $^ -o $@ $(LIBS)

debug: $(OBJ0)
	$(CC) $(CFLAGS) $^ -o $@ $(LIBS) -g # to use with gdb


betty:
	betty *.c *.h
