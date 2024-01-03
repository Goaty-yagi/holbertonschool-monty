#include <stdio.h>
#include <stdlib.h>
#include "monty.h"

int main(int argc, char *argv[])
{
	FILE *file = fopen(argv[1], "r");
	stack_type *stack = NULL;
	char line[256];
	unsigned int line_number = 1;
	char *opcode;
	char *value;

	if (argc != 2)
	{
		fprintf(stderr, "USAGE: monty file\n");
		return EXIT_FAILURE;
	}

	if (!file)
	{
		fprintf(stderr, "Error: Can't open file %s\n", argv[1]);
		return EXIT_FAILURE;
	}

	while (fgets(line, sizeof(line), file))
	{
		line[strcspn(line, "\n")] = '\0'; // Remove newline if present

		opcode = strtok(line, " ");
		value = strtok(NULL, " ");

		if (strcmp(opcode, "push") == 0)
		{
			op_push(&stack, line_number, value);
		}
		else if (strcmp(opcode, "pall") == 0)
		{
			op_pall(&stack);
		}

		line_number++;
	}

	fclose(file);

	return EXIT_SUCCESS;
}
