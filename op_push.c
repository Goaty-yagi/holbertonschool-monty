#include "monty.h"

/**
 * parse_input - Parses the input string
 * @str: The input string to parse
 *
 * Return: 0 if the string doesn't start with a digit, 1 otherwise
 */

int parse_input(char *str)
{
	int len = strlen(str);
	int counter = 0;

	while (counter < len)
	{
		if (str[counter] == '-' && counter == 0)
		{
			counter = counter + 1;
			continue;
		}
		if (!isdigit(str[counter]))
		{
			if (counter == 0)
			{
				return (0);
			}
			str[counter] = '\0';
			return (1);
		}
		counter = counter + 1;
	}
	return (1);
}

/**
 * op_push - Adds a new element to the top of the stack
 * @stack: Pointer to a pointer to the top of the stack
 * @line_number: Line number in the file being processed
 *
 * This function creates a new node and adds it to the top of the stack.
 * It assigns the given line_number as the file_s.value of the new node. If the
 * allocation fails or if the line_number is invalid, it displays an error
 * message and exits with a failure status. The new node becomes the top
 * element of the stack.
 */

void op_push(stack_type **stack, unsigned int line_number)
{
	stack_type *new_node;

	if (!parse_input(file_s.VALUE) || file_s.VALUE[0] == '\0')
	{
		fprintf(stderr, "L%d: usage: push integer\n", line_number);
		free_all_node(stack);
		exit(EXIT_FAILURE);
	}

	new_node = malloc(sizeof(stack_type));
	if (!new_node)
	{
		fprintf(stderr, "Error: malloc failed\n");
		free_all_node(stack);
		exit(EXIT_FAILURE);
	}
	new_node->n = atoi(file_s.VALUE);
	new_node->prev = NULL;
	new_node->next = *stack;

	if (*stack)
		(*stack)->prev = new_node;

	*stack = new_node;

	strcpy(file_s.VALUE, "");
	strcpy(file_s.OP, "");
}
