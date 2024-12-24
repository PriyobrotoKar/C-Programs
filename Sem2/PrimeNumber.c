//? To find whether a giver number is a prime number or not

#include <stdio.h>

void main()
{
    int n, isPrime = 1;
    printf("Enter a number:");
    scanf("%d", &n);
    for (int i = 2; i <= n / 2; i++)
    {
        if (!(n % i))
        {
            isPrime = 0;
            break;
        }
    }
    if (isPrime)
    {
        printf("%d is a prime number", n);
    }
    else
    {
        printf("%d is not a prime number", n);
    }
}