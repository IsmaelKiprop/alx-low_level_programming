#include <stdlib.h>
#include "lists.h"

/**
 * insert_dnodeint_at_index - Inserts a new node at a given position.
 * @h: Pointer to the pointer to the head of the list.
 * @idx: Index at which the new node should be added.
 * @n: Integer value to store in the new node.
 *
 * Return: Address of the new node on success, or NULL on failure.
 */
dlistint_t *insert_dnodeint_at_index(dlistint_t **h, unsigned int idx, int n)
{
dlistint_t *new_node, *current = *h;
unsigned int i = 0;

if (h == NULL)
return (NULL);

if (idx == 0)
return (add_dnodeint(h, n));
new_node = malloc(sizeof(dlistint_t));
if (new_node == NULL)
return (NULL);

new_node->n = n;

while (current != NULL)
{
if (i == idx - 1)
{
new_node->next = current->next;
new_node->prev = current;
if (current->next != NULL)
current->next->prev = new_node;
current->next = new_node;
return (new_node);
}
current = current->next;
i++;
}

free(new_node);
return (NULL);
}
