#include <stdio.h>

void main()
{
    int a, b, temp;
    printf("Enter two numbers:");
    scanf("%d %d", &a, &b);
    temp = b;
    b = a;
    a = temp;
    printf("%d %d", a, b);
}