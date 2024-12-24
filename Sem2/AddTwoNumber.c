#include <stdio.h>

void main()
{
    int a, b, sum = 0;
    printf("Enter two numbers:\n");
    scanf("%d %d", &a, &b);
    sum = a + b;
    printf("%d = %d + %d", sum, a, b);
}