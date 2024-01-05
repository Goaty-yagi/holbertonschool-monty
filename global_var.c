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

void declare_global_var(char *line)
{
	int arg_count = 0;
	char *token;

	if (line == NULL)
		return;
	token = strtok(line, " ");
	while (token != NULL && arg_count < 2)
	{
		if (arg_count == 0)
		{
			strcpy(OPERATION, token);
		}
		else
		{
			strcpy(VALUE, token);
			printf("CECK_VAL:%s\n", VALUE);
		}
		token = strtok(NULL, " ");
		arg_count = arg_count + 1;
	}
}
