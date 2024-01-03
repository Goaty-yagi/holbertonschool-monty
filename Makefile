CC = gcc
SRC = $(wildcard *.c)
OBJ = $(SRC:%.c=%.o)
NAME = monty
RM = rm
CFLAGS = -Wall -pedantic -Werror -Wextra -std=gnu89

all:$(OBJ)
	$(CC) $(OBJ) -o $(NAME)

first:
	$(CC) $(CFLAGS) -c -o $(SRC)

clean:
	$(RM) -rf *~ $(NAME) $(OBJ)
