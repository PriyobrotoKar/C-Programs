#include <stdio.h>

void main()
{
    int a, b;
    printf("Enter two numbers:");
    scanf("%d %d", &a, &b);
    a = a - b;
    b = b + a;
    a = b - a;
    printf("%d %d", a, b);
}