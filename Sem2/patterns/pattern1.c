/*
ABCDE
CDEF
EFG
HI
I
*/

#include <stdio.h>

void main()
{
    int i, j;
    int l = 4;
    for (i = 65; i <= 73; i = i + 2)
    {

        for (j = 0; j <= l; j++)
        {
            char ch = (int)i + j;
            printf("%c", ch);
        }
        printf("\n");
        l--;
    }
}