#include <stdlib.h>
#include "lists.h"

/**
 * delete_dnodeint_at_index - Delete node at index in dlistint_t linked list
 * @head: Pointer to pointer the head of list
 * @index: Index of the node to deleted
 *
 * Return: 1 succeeded, -1 failed
 */
int delete_dnodeint_at_index(dlistint_t **head, unsigned int index)
{
dlistint_t *current = *head;
unsigned int i = 0;

if (head == NULL || *head == NULL)
return (-1);

if (index == 0)
{
*head = (*head)->next;
if (*head != NULL)
(*head)->prev = NULL;
free(current);
return (1);
}

while (current != NULL)
{
if (i == index)
{
current->prev->next = current->next;
if (current->next != NULL)
current->next->prev = current->prev;
free(current);
return (1);
}
current = current->next;
i++;
}

return (-1);
}
