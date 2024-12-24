/*
*******
*****
***
*
*/

#include <stdio.h>

void main()
{
    int i = 65, j, x = 0;
    for (int i = 0; i <= 3; i++)
    {
        static int l = 7;
        for (int k = 0; k < i; k++)
        {
            printf(" ");
        }
        for (int j = 0; j < l; j++)
        {
            printf("*");
        }
        l = l - 2;
        printf("\n");
    }
}