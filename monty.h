
#ifndef MONTY_H
#define MONTY_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

/**
 * struct stack_s - doubly linked list representation of a stack (or queue)
 * @n: integer
 * @prev: points to the previous element of the stack (or queue)
 * @next: points to the next element of the stack (or queue)
 *
 * Description: doubly linked list node structure
 * for stack, queues, LIFO, FIFO
 */
typedef struct stack_s
{
	int n;
	struct stack_s *prev;
	struct stack_s *next;
} stack_type;

/**
 * struct instruction_s - opcode and its function
 * @opcode: the opcode
 * @f: function to handle the opcode
 *
 * Description: opcode and its function
 * for stack, queues, LIFO, FIFO
 */
typedef struct instruction_s
{
	char *opcode;
	void (*f)(stack_type **stack, unsigned int line_number);
} instruction_t;

/**
 * struct file_operation - File operations structure
 * @READ_FILE: Pointer to a FILE structure for reading operations
 * @OP: Operation, command, or action
 * @VALUE: Value related to the operation
 *
 * Description: Structure defining file operations, including
 * reading from a file, the operation/command, and associated value.
 */
struct file_operation
{
	FILE *READ_FILE;
	char OP[256];
	char VALUE[256];
};

extern struct file_operation file_s;

void op_push(stack_type **stack, unsigned int line_number);
void op_pall(stack_type **stack, unsigned int line_number);
void define_global_var(char *line);
void free_all_node(stack_type **stack);

#endif
