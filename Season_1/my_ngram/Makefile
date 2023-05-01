CC = gcc
SRC = my_ngram.c
OBJ = $(SRC:.c=.o)
TARGET = my_ngram
RM = rm -f
CFLAGS = -Wall -Werror -Wextra

all: $(OBJ)
	$(CC) $(CFLAGS) $(OBJ) -o $(TARGET)

clean:
	$(RM) *~ $(TARGET)

oclean:
	$(RM) $(OBJ)

fclean: clean oclean

re: fclean all