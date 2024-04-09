#include "lists.h"
#include <stdlib.h>
int delete_nodeint_at_index(listint_t **head, unsigned int index)
{
    listint_t *current, *previous;
    unsigned int i;
    if (*head == NULL)
        return (-1);
    if (index == 0)
    {
        current = *head;
        *head = (*head)->next;
        free(current);
        return (1);
    }
    previous = *head;
    current = (*head)->next;

    for (i = 1; current != NULL && i < index; i++)
    {
        previous = current;
        current = current->next;
    }
    if (current == NULL)
        return (-1);
    previous->next = current->next;
    free(current);
    return (1);
}
