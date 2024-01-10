CC = gcc
SRC = $(wildcard *.c)
OBJ = $(SRC:%.c=%.o)
NAME = monty
RM = rm
CFLAGS = -Wall -pedantic -Werror -Wextra -std=gnu89

VALGRIND = valgrind
V_FLAGS = --leak-check=full --show-leak-kinds=all --track-origins=yes

BT = betty
HEADER = $(wildcard *.h)

BYTECODES_DIR = bytecodes
BYTECODES_TASK1 = $(wildcard $(BYTECODES_DIR)/task1/*.m)
BYTECODES_TASK2 = $(wildcard $(BYTECODES_DIR)/task2/*.m)
BYTECODES_TASK3 = $(wildcard $(BYTECODES_DIR)/task3/*.m)

all:$(OBJ)
	$(CC) $(OBJ) -o $(NAME)

first:
	$(CC) $(CFLAGS) -c -o $(SRC)

clean:
	$(RM) -rf *~ $(NAME) $(OBJ)

betty:
	$(BT) $(SRC) $(HEADER)

memory-task1: $(NAME)
	$(VALGRIND) $(V_FLAGS) ./$(NAME) $(BYTECODES_TASK1)

memory-task2: $(NAME)
	$(VALGRIND) $(V_FLAGS) ./$(NAME) $(BYTECODES_TASK2)

memory-task3: $(NAME)
	$(VALGRIND) $(V_FLAGS) ./$(NAME) $(BYTECODES_TASK3)