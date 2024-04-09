#include "lists.h"
#include <stdlib.h>

size_t free_listint_safe(listint_t **h)
{
    listint_t *current, *next_node;
    size_t count = 0;

    if (h == NULL || *h == NULL)
        return (0);

    current = *h;
    while (current != NULL)
    {
        next_node = current->next;
        free(current);
        count++;

        if (next_node >= current)
            break;

        current = next_node;
    }

    *h = NULL;
    return (count);
}
