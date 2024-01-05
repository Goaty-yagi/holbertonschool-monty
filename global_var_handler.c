#include "monty.h"

char OPERATION[16];
char VALUE[16];

/**
 * define_global_var - Tokenizes a line into an args_t structure.
 *
 * @line: The line to be tokenized.
 *
 * Description:
 * This function tokenizes the line into separate arguments using
 * space as the delimiter.
 */

void define_global_var(char *line)
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
		}
		token = strtok(NULL, " ");
		arg_count = arg_count + 1;
	}
}
