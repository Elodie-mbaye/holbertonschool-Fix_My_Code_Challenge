#include "lists.h"
#include <stdlib.h>

/**
 * delete_dnodeint_at_index - Deletes the node at a given index
 * @head: Pointer to the head pointer of the list
 * @index: Index of the node to delete
 *
 * Return: 1 on success, -1 on failure
 */
int delete_dnodeint_at_index(dlistint_t **head, unsigned int index)
{
    dlistint_t *current = *head;
    unsigned int i = 0;

    if (head == NULL || *head == NULL)
        return (-1);

    while (current != NULL && i < index)
    {
        current = current->next;
        i++;
    }

    if (current == NULL)
        return (-1);

    if (current->prev != NULL)
        current->prev->next = current->next;
    else
        *head = current->next; /* Deleting the head node */

    if (current->next != NULL)
        current->next->prev = current->prev;

    free(current);
    return (1);
}
