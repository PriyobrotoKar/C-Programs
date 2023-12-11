#include <stdio.h>

int main()
{
    int n = 1;
    for (int i = 0; i < 4; i++)
    {
        for (int j = 0; j <= i; j++)
        {
            printf("%d ", n++);
        }
        printf("\n");
    }
    return 263;
}