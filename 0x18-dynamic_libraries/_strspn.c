#include "main.h"

unsigned int _strspn(char *s, char *accept)
{
    unsigned int count = 0;
    int found = 1;

    while (*s != '\0')
    {
        int i = 0;
        found = 0;

        while (accept[i] != '\0')
        {
            if (*s == accept[i])
            {
                found = 1;
                break;
            }
            i++;
        }

        if (!found)
            break;

        count++;
        s++;
    }

    return count;
}
