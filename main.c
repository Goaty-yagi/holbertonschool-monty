#include <stdio.h>
#include <stdlib.h>
#include "monty.h"


/*void process_instructions()
{
	
}
*/

int main(int argc, char *argv[])
{
	FILE *file = fopen(argv[1], "r");
	stack_type *stack = NULL;
	char line[256];
	args_t args;
	unsigned int counter;
	instruction_t instructions[] = {
		{"push", op_push},
		{"pall", op_pall},
		{"pint", op_pint},
		{"pop", op_pop},
		{"swap", op_swap},
	};
	size_t num_length = sizeof(instructions) / sizeof(instructions[0]);

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
		line[strcspn(line, "\n")] = '\0'; /* Remove newline if present */
		initialise_line(line, &args, 2);
		counter = 0;

		while (counter < num_length)
		{
			if (strcmp(instructions[counter].opcode, args.opcode) == 0)
			{
				instructions[counter].f(&stack, args.val);
				break;
			}
			counter = counter + 1;
		}
	}

	fclose(file);
	free_all_node(&stack);
	return EXIT_SUCCESS;
}
