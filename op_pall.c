#include "monty.h"

/**
 * op_pall - Prints all elements in the stack
 * @stack: Pointer to a pointer to the top of the stack
 * @line_number: Line number in the file being processed (unused)
 *
 * This function prints all the integer values stored in the stack,
 * starting from the top element and moving downwards. It traverses
 * the stack, printing each node's 'n' value followed by a newline.
 */

void op_pall(stack_type **stack, unsigned int line_number)
{
	stack_type *current = *stack;
	(void)line_number;

	while (current != NULL)
	{
		printf("%d\n", current->n);
		current = current->next;
	}
	strcpy(file_s.VALUE, "");
	strcpy(file_s.OP, "");
}
