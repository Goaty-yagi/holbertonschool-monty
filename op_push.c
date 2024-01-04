#include "monty.h"
#include <ctype.h>

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
