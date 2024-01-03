#include "monty.h"

void op_pall(stack_type **stack)
{
	stack_type *current = *stack;

	while (current != NULL)
	{
		printf("%d\n", current->n);
		current = current->next;
	}
}
