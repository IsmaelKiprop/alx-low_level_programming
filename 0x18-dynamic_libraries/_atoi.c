#include "main.h"

int _atoi(char *s)
{
    int sign = 1;
    int result = 0;
    int i = 0;

    if (s[0] == '-')
    {
        sign = -1;
        i++;
    }

    while (s[i] != '\0')
    {
        result = result * 10 + (s[i] - '0');
        i++;
    }

    return sign * result;
}
