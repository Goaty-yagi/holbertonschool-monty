#include "monty.h"

/**
 * initialise_line - Tokenizes a line into an args_t structure.
 *
 * @line: The line to be tokenized.
 * @args: A structure to store the tokenized arguments.
 * @max_args: The maximum number of loop. now assumption is always 2.
 *
 * Description:
 * This function tokenizes the line into separate arguments using
 * space as the delimiter. It populates the 'args' structure with the tokenized
 * arguments.
 */

void initialise_line(char *line, args_t *args, int max_args)
{
	int arg_count = 0;
	char *token;

	if (line == NULL)
		return;
	token = strtok(line, " ");
	while (token != NULL && arg_count < max_args)
	{
		if (arg_count == 0)
		{
			args->opcode = token;
		}
		else
		{
			args->val = atoi(token);
		}
		token = strtok(NULL, " ");
		arg_count = arg_count + 1;
	}
}
