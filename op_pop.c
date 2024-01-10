#include "monty.h"

/**
 * op_pop - Removes the top element from the stack
 * @stack: Pointer to a pointer to the top of the stack
 * @line_number: Line number in the file being processed (unused)
 *
 * This function removes the top element from the stack. If the stack is empty,
 * it displays an error message indicating it can't pop from an empty stack.
 * Otherwise, it updates the stack pointer to point to the next element and
 * deallocates the memory of the removed element.
 */

void op_pop(stack_type **stack, unsigned int line_number)
{
	stack_type *temp = *stack;
	(void)line_number;

	if (!*stack)
	{
		fprintf(stderr, "L%u: can't pop an empty stack\n", line_number);
		free_all_node(stack);
		exit(EXIT_FAILURE);
	}

	*stack = (*stack)->next;
	free(temp);
}
