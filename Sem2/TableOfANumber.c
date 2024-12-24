#include <stdio.h>

void main()
{
    int n;
    printf("Enter a number:");
    scanf("%d", &n);
    for (int i = 0; i <= 10; i++)
    {
        printf("%d x %d = %d\n", n, i, n * i);
    }
}