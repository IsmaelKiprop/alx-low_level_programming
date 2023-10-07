#include "hash_tables.h"

/**
 * hash_table_create - creates a hash table
 * @size: size of the array of the hash table
 * Return: a pointer to the newly created hash table
 */
hash_table_t *hash_table_create(unsigned long int size)
{
    hash_table_t *hash;
    unsigned int i;

    if (size == 0)
        return (NULL);

    hash = malloc(sizeof(hash_table_t));
    if (!hash)
        return (NULL);

    hash->array = malloc(sizeof(hash_node_t *) * size);
    if (!hash->array)
    {
        free(hash); // Clean up previously allocated memory
        return (NULL);
    }

    hash->size = size;

    for (i = 0; i < size; i++)
        hash->array[i] = NULL;

    return (hash);
}