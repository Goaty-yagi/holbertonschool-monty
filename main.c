#include "monty.h"

struct file_operation file_s = {NULL, "", ""};

/**
 * process_file_operations - Process operations and execute instructions
 * @stack: Pointer to the stack structure
 *
 * This function reads lines from a file, parses each line, 
 * and executes corresponding
 * instructions based on the defined operations.
 *
 */
void process_file_operations(stack_type **stack)
{
	char line[256];
	unsigned int counter = 0, executed = 0, line_number = 1;
	instruction_t instructions[] = {
		{"push", op_push},
		{"pall", op_pall}};
	size_t num_length = sizeof(instructions) / sizeof(instructions[0]);

	while (fgets(line, sizeof(line), file_s.READ_FILE))
	{
		line[strcspn(line, "\n")] = '\0';
		define_global_var(line);
		if (file_s.OPERATION[0] != '\0')
		{
			while (counter < num_length)
			{
				if (strcmp(instructions[counter].opcode, file_s.OPERATION) == 0)
				{
					instructions[counter].f(stack, line_number);
					executed = 1;
					break;
				}
				counter++;
			}
			if (!executed)
			{
				fprintf(stderr, "L%i: unknown instruction %s\n", line_number, file_s.OPERATION);
				free_all_node(stack);
				exit(EXIT_FAILURE);
			}
			counter = 0;
			executed = 0;
			line_number++;
		}
	}
}

/**
 * main - Entry point of the Monty interpreter
 * @argc: Number of arguments passed
 * @argv: Pointers to the arguments
 *
 * This function is the entry point for the Monty interpreter. It reads a file
 * with Monty bytecode instructions, parses each line into opcode and value (if
 * present), matches with predefined instructions, and executes file_s.operation
 * on the stack. It uses helper functions like 'initialise_line', 'free_all_node',
 * and calls appropriate file_s.operation functions based on the opcode found.
 *
 * Return: EXIT_SUCCESS on successful execution, EXIT_FAILURE for incorrect arguments
 * or file opening failure.
 */


int main(int argc, char *argv[])
{
	stack_type *stack = NULL;

	if (argc != 2)
	{
		fprintf(stderr, "USAGE: monty file\n");
		return (EXIT_FAILURE);
	}

	file_s.READ_FILE = fopen(argv[1], "r");

	if (!file_s.READ_FILE)
	{
		fprintf(stderr, "Error: Can't open file %s\n", argv[1]);
		return (EXIT_FAILURE);
	}
	process_file_operations(&stack);
	free_all_node(&stack);
	return (EXIT_SUCCESS);
}
