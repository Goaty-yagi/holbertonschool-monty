#include "monty.h"

/**
 * op_pint - Prints the value at the top of the stack
 * @stack: Pointer to a pointer to the top of the stack
 * @line_number: Line number in the file being processed
 *
 * This function prints the integer value of the top element in the stack.
 * If the stack is empty, it displays an error message and exits with failure.
 */

void op_pint(stack_type **stack, unsigned int line_number)
{
	if (!*stack)
	{
		fprintf(stderr, "L<%u>: can't pint, stack empty\n", line_number);
		free_all_node(stack);
		exit(EXIT_FAILURE);
	}
	printf("%d\n", (*stack)->n);
}