CC = gcc
CFLAGS = -Wall -Werror -Wextra -pedantic -Wno-deprecated-declarations
LIB_FLAGS = -lssl -crypto

SRC0 = sha256.c ec_create.c ec_to_pub.c ec_from_pub.c ec_save.c ec_load.c ec_sign.c ec_verify .c
OBJ0 = $(SRC0:.c=.o)
NAME0 = libhblk_crypto.a

libhblk_crypto.a: hblk_crypto.h $(OBJ0)
	ar rcs $(NAME0) $(OBJ0) $(LIBFLAGS)

$(OBJ0):
	$(CC) $(CFLAGS) -c $< -o $@ $(LIB_FLAGS)

clean:
	$(RM) *~ $(NAME0)
	rm *.o
	rm test/*.o
	rm out

betty:
	betty *.c *.h
