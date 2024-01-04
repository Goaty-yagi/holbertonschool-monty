#include "monty.h"

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
