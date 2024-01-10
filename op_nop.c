#include "monty.h"

/**
 * op_nop - Does nothing
 * @stack: Pointer to a pointer to the top of the stack (unused)
 * @line_number: Line number in the file being processed (unused)
 *
 * This function performs no operation. It is designed to comply with the
 * instruction set but doesn't modify the stack or perform any action.
 */

void op_nop(stack_type **stack, unsigned int line_number)
{
	(void)stack;
	(void)line_number;
}
