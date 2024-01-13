#include "monty.h"

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
	unsigned int counter = 0, executed = 0, line_num = 1;
	instruction_t instructions[] = {
		{"push", op_push}, {"pall", op_pall}, {"pint", op_pint}, {"pop", op_pop},
		{"swap", op_swap}, {"add", op_add}, {"nop", op_nop}};
	size_t num_length = sizeof(instructions) / sizeof(instructions[0]);

	while (fgets(line, sizeof(line), file_s.READ_FILE))
	{
		line[strcspn(line, "\n")] = '\0';
		if (strspn(line, " \t\n\r") == strlen(line))
		{
			line_num = line_num + 1;
			continue;
		}
		define_global_var(line);
		if (file_s.OP[0] != '\0')
		{
			while (counter < num_length)
			{
				if (strcmp(instructions[counter].opcode, file_s.OP) == 0)
				{
					instructions[counter].f(stack, line_num);
					executed = 1;
					break;
				}
				counter = counter + 1;
				;
			}
			if (!executed)
			{
				fprintf(stderr, "L%i: unknown instruction %s\n", line_num, file_s.OP);
				free_all_node(stack);
				exit(EXIT_FAILURE);
			}
			counter = executed = 0;
		}
		line_num = line_num + 1;
	}
}
