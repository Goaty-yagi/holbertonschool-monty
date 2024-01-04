#include "../monty.h"

/**
 * op_add - Adds the top two elements of the stack
 * @stack: Pointer to a pointer to the top of the stack
 * @line_number: Line number in the file being processed
 *
 * This function adds the top two elements of the stack and stores the result
 * in the second element from the top. If the stack doesn't contain enough
 * elements, it displays an error message.
 */

void op_add(stack_type **stack, unsigned int line_number)
{
	stack_type *temp = *stack;
	if (!*stack | !(*stack)->next)
	{
		fprintf(stderr, "L<%u>: can't add, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}

	*stack = temp->next;
    (*stack)->n += temp->n;
	(*stack)->prev = NULL;
	free(temp);
}
