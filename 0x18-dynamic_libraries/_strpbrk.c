#include "main.h"

char *_strpbrk(char *s, char *accept)
{
    while (*s != '\0')
    {
        int i = 0;

        while (accept[i] != '\0')
        {
            if (*s == accept[i])
                return s;
            i++;
        }

        s++;
    }

    return NULL;
}
