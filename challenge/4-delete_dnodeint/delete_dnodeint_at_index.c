#include "lists.h"
#include <stdlib.h>

/**
 * delete_dnodeint_at_index - Deletes the node at index of a dlistint_t linked list
 * @head: Double pointer to the head of the list
 * @index: Index of the node to delete
 * Return: 1 if it succeeded, -1 if it failed
 */
int delete_dnodeint_at_index(dlistint_t **head, unsigned int index)
{
    dlistint_t *current = *head;
    unsigned int i;

    if (*head == NULL)
        return (-1);

    /* Deleting the head node */
    if (index == 0)
    {
        *head = current->next;
        if (*head)
            (*head)->prev = NULL;
        free(current);
        return (1);
    }

    /* Traverse to the node at index */
    for (i = 0; current != NULL && i < index; i++)
        current = current->next;

    /* If index is out of range */
    if (current == NULL)
        return (-1);

    /* Remove current node */
    if (current->prev)
        current->prev->next = current->next;
    if (current->next)
        current->next->prev = current->prev;

    free(current);
    return (1);
}
