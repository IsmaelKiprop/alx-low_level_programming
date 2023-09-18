#include "main.h"

char *_strncat(char *dest, char *src, int n)
{
    int dest_len = _strlen(dest);
    int i = 0;

    while (src[i] != '\0' && i < n)
    {
        dest[dest_len + i] = src[i];
        i++;
    }

    dest[dest_len + i] = '\0';

    return dest;
}
