#include "monty.h"

void op_pop(stack_type **stack, unsigned int line_number)
{	
    stack_type *temp = *stack;
	(void)line_number;

	if (!*stack)
	{
		fprintf(stderr, "L%u: can't pop an empty stack\n", line_number);
		exit(EXIT_FAILURE);
	}
	
    *stack = (*stack)->next;
    free(temp);
}
