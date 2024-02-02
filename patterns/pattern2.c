/*
ABCDE
BCDE
CDE
DE
E
*/

#include <stdio.h>

void main()
{
    int i, j;
    for (i = 65; i <= 69; i = i + 1)
    {

        for (j = i; j <= 69; j++)
        {
            char ch = (int)j;
            printf("%c", ch);
        }
        printf("\n");
    }
}