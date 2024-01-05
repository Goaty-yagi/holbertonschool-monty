#include "monty.h"

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
	FILE *file = fopen(argv[1], "r");
	stack_type *stack = NULL;
	char line[256];
	args_t args;
	unsigned int counter = 0;
	instruction_t instructions[] = {
		{"push", op_push},
		{"pall", op_pall},
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
		while (counter < num_length)
		{
			if (strcmp(instructions[counter].opcode, args.opcode) == 0)
			{
				instructions[counter].f(&stack, args.val);
			}
			counter = counter + 1;
		}
		counter = 0;
	}

	fclose(file);
	free_all_node(&stack);
	return EXIT_SUCCESS;
}
