#include "monty.h"

/**
 * free_all_node - Deallocates memory for all nodes in a linked list stack
 * @stack: Pointer to a pointer to the top of the stack
 *
 * This function traverses through the linked list stack and frees memory
 * associated with each node until the stack is empty. It updates the stack
 * pointer to NULL, indicating an empty stack after deallocation.
 */

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
