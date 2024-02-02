/*
A

*/

#include <stdio.h>

void main()
{
    int i = 65, j, x = 0;
    while (i <= 69)
    {
        for (j = i; j >= 65; j--)
        {
            char ch = (char)j;
            printf("%c", ch);
        }
        i = i + 1 * x;
        x = 1;
        printf("\n");
    }
}