CC = gcc
SRC = $(wildcard *.c)
OBJ = $(SRC:%.c=%.o)
NAME = monty
RM = rm
CFLAGS = -Wall -pedantic -Werror -Wextra -std=gnu89
VALG = valgrind
VFLAGS = --leak-check=full --show-leak-kinds=all --track-origins=yes
BT = betty

all:$(OBJ)
	$(CC) $(OBJ) -o $(NAME)

first:
	$(CC) $(CFLAGS) -c -o $(SRC)

clean:
	$(RM) -rf *~ $(NAME) $(OBJ)

memory:
	$(VALG) $(VFLAGS) $(NAME)

betty:
	$(BT) $(SRC)
