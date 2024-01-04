#include "monty.h"

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
