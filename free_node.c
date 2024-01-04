#include "monty.h"

void free_all_node(stack_type **stack)
{
    stack_type *current = stack[0];
    stack_type *next_node = NULL;

    if (!current)
        return;

    while (current != NULL) {
        next_node = current->next;

        free(current);

        current = next_node;
    }

    *stack = NULL;
}
