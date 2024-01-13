#include "monty.h"

struct file_operation file_s = {NULL, "", ""};

/**
 * main - Entry point of the Monty interpreter
 * @argc: Number of arguments passed to the program
 * @argv: Array of pointers to the arguments
 *
 * This function serves as the entry point for the Monty interpreter. It reads
 * a file containing Monty bytecode instructions, parses each line into opcode
 * and value (if present), matches the opcode with predefined instructions,
 * and executes the corresponding file_s.op on the stack. It uses various
 * helper functions such as 'initialise_line', 'free_all_node', and calls the
 * appropriate file_s.op functions based on the opcode found.
 *
 * Return: EXIT_SUCCESS upon successful execution, EXIT_FAILURE if arguments
 * are incorrect or if file opening fails.
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
