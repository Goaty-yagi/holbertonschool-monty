#include "monty.h"

void op_pall(stack_type **stack, unsigned int line_number)
{
	stack_type *current = *stack;
	(void)line_number;

	while (current != NULL)
	{
		printf("%d\n", current->n);
		current = current->next;
	}
}
