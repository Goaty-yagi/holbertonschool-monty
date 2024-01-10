CC = gcc
SRC = $(wildcard *.c)
OBJ = $(SRC:%.c=%.o)
NAME = monty
RM = rm
CFLAGS = -Wall -pedantic -Werror -Wextra -std=gnu89
VALG = valgrind
VFLAGS = --leak-check=full --show-leak-kinds=all --track-origins=yes
BT = betty
BYTECODE0 = bytecodes/00.m
BYTECODE1-0 = bytecodes/task1/00.m
BYTECODE1-1 = bytecodes/task1/01.m
BYTECODE2-0 = bytecodes/task2/00.m
BYTECODE2-1 = bytecodes/task2/01.m
BYTECODE2-2 = bytecodes/task2/02.m

all:$(OBJ)
	$(CC) $(OBJ) -o $(NAME)

first:
	$(CC) $(CFLAGS) -c -o $(SRC)

clean:
	$(RM) -rf *~ $(NAME) $(OBJ)

betty:
	$(BT) $(SRC)

memory:
	$(VALG) $(VFLAGS) ./$(NAME) $(BYTECODE0)

memory1-0:
	$(VALG) $(VFLAGS) ./$(NAME) $(BYTECODE1-0)

memory1-1:
	$(VALG) $(VFLAGS) ./$(NAME) $(BYTECODE1-1)

memory2-0:
	$(VALG) $(VFLAGS) ./$(NAME) $(BYTECODE2-0)

memory2-1:
	$(VALG) $(VFLAGS) ./$(NAME) $(BYTECODE2-1)

memory2-2:
	$(VALG) $(VFLAGS) ./$(NAME) $(BYTECODE2-2)