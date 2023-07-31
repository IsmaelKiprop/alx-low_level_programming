#include "lists.h"
#include <stdlib.h>
#include <stdio.h>

/**
 * free_listint_safe - Frees a listint_t linked list, even if there's a loop.
 * @h: Double pointer to the head of the list.
 *
 * Return: The size of the list that was freed.
 */
size_t free_listint_safe(listint_t **h)
{
    size_t count = 0;
    listint_t *current, *next;

    current = *h;

    while (current != NULL)
    {
        next = current->next;
        printf("[%p] %d\n", (void *)current, current->n);
        free(current);
        current = next;
        count++;

        if (current == *h)
            break;
    }

    *h = NULL;
    return (count);
}
