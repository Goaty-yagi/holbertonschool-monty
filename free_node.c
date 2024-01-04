#include "monty.h"

void free_all_node(stack_type **stack)
{
    stack_type *current = stack[0];
    if (!stack[0])
        return;

    while (current != NULL)
    {
        if (current->next)
        {
            current = current->next;
            free(current->prev);
        }
        else
        {
            free(current);
            current = current->next;
        }
    }
}
