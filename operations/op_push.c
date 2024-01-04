#include "../monty.h"

/**
 * op_push - Adds a new element to the top of the stack
 * @stack: Pointer to a pointer to the top of the stack
 * @line_number: Line number in the file being processed
 *
 * This function creates a new node and adds it to the top of the stack.
 * It assigns the given line_number as the value of the new node. If the
 * allocation fails or if the line_number is invalid, it displays an error
 * message and exits with a failure status. The new node becomes the top
 * element of the stack.
 */

void op_push(stack_type **stack, unsigned int line_number)
{
	stack_type *new_node = malloc(sizeof(stack_type));

	if (!line_number && line_number != 0)
	{
		fprintf(stderr, "L%d: usage: push integer\n", line_number);
		exit(EXIT_FAILURE);
	}

	if (!new_node)
	{
		fprintf(stderr, "Error: malloc failed\n");
		exit(EXIT_FAILURE);
	}

	new_node->n = line_number;
	new_node->prev = NULL;
	new_node->next = *stack;

	if (*stack)
		(*stack)->prev = new_node;

	*stack = new_node;
}