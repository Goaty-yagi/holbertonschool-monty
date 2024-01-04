#include "../monty.h"

/**
 * op_swap - Swaps the top two elements of the stack
 * @stack: Pointer to a pointer to the top of the stack
 * @line_number: Line number in the file being processed
 *
 * This function swaps the positions of the top two elements in the stack.
 * If the stack has fewer than two elements, it displays an error message
 * and exits with a failure status. Otherwise, it rearranges the pointers
 * to perform the swap operation.
 */

void op_swap(stack_type **stack, unsigned int line_number)
{
	stack_type *temp = *stack;

	if (!*stack | !(*stack)->next)
	{
		fprintf(stderr, "L<%u>: can't swap, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}

	*stack = temp->next;
	(*stack)->prev = NULL;
	temp->prev = *stack;
	temp->next = (*stack)->next;
	(*stack)->next = temp;
}
