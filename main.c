#include "monty.h"

FILE *READ_FILE;

/**
 * main - Entry point of the Monty interpreter
 * @argc: Number of arguments passed to the program
 * @argv: Array of pointers to the arguments
 *
 * This function serves as the entry point for the Monty interpreter. It reads
 * a file containing Monty bytecode instructions, parses each line into opcode
 * and value (if present), matches the opcode with predefined instructions, and
 * executes the corresponding operation on the stack. It uses various helper
 * functions such as 'initialise_line', 'free_all_node', and calls the
 * appropriate operation functions based on the opcode found.
 *
 * Returns:
 * - EXIT_SUCCESS upon successful execution.
 * - EXIT_FAILURE if arguments are incorrect or if file opening fails.
 */

int main(int argc, char *argv[])
{
	stack_type *stack = NULL;
	char line[256];
	unsigned int counter = 0;
	unsigned int executed = 0;
	unsigned int line_number = 1;
	instruction_t instructions[] = {
		{"push", op_push},
		{"pall", op_pall},
	};
	size_t num_length = sizeof(instructions) / sizeof(instructions[0]);
	READ_FILE = fopen(argv[1], "r");

	if (argc != 2)
	{
		fprintf(stderr, "USAGE: monty file\n");
		return (EXIT_FAILURE);
	}

	if (!READ_FILE)
	{
		fprintf(stderr, "Error: Can't open file %s\n", argv[1]);
		return (EXIT_FAILURE);
	}

	while (fgets(line, sizeof(line), READ_FILE))
	{
		line[strcspn(line, "\n")] = '\0'; /* Remove newline if present */
		declare_global_var(line);
		if (strcmp(OPERATION, "") != 0)
		{
			while (counter < num_length)
			{
				if (strcmp(instructions[counter].opcode, OPERATION) == 0)
				{
					instructions[counter].f(&stack, line_number);
					executed = 1;
				}
				counter = counter + 1;
			}
			if (!executed)
			{
				fprintf(stderr, "L%i: unknown instruction %s\n", line_number, OPERATION);
				fclose(READ_FILE);
				free_all_node(&stack);
				return (EXIT_FAILURE);
			}
			counter = 0;
			executed = 0;
			line_number = line_number + 1;
		}
	}

	fclose(READ_FILE);
	free_all_node(&stack);
	return EXIT_SUCCESS;
}
