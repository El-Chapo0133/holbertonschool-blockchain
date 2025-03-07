CC = gcc
CFLAGS = -Wall -Werror -Wextra -pedantic -Wno-deprecated-declarations
LIB_FLAGS = -lssl -crypto
OBJDIR = targets/

SRC0 = sha256.c ec_create.c ec_to_pub.c ec_from_pub.c ec_save.c ec_load.c ec_sign.c ec_verify .c
OBJ0 = $(iaddprefix $(OBJDIR) $(SRC0:.c=.o))
NAME0 = libhblk_crypto.a

libhblk_crypto.a: hblk_crypto.h $(OBJDIR) $(OBJ0)
	ar rcs $(NAME0) $(OBJ0) $(LIBFLAGS)

$(OBJDIR)%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

$(OBJDIR):
	mkdir $(OBJDIR)

clean:
	rm *.o
	rm test/*.o
	rm out

betty:
	betty *.c *.h
