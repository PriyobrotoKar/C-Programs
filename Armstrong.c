#include <stdio.h>
#include <math.h>
int main()
{
    // int num, originalnum, remainder, n = 0, result = 0;
    // printf("Enter the three digit number:");
    // scanf("%d", &num);

    // for (originalnum = num; originalnum != 0; n++)
    // {
    //     originalnum /= 10;
    // }

    // for (originalnum = num; originalnum != 0; originalnum /= 10)
    // {
    //     remainder = originalnum % 10;
    //     result += pow(remainder, n);
    // }
    // if (result == num)
    //     printf("%d is the Amstrong no.\n", num);
    // else
    //     printf("%d is not Armstrong no.\n", num);

    int num, digits = 0, sum = 0, rem;
    printf("Enter a number:");
    scanf("%d", &num);
    int temp = num;
    while (temp > 0)
    {
        digits++;
        temp /= 10;
    }
    temp = num;
    while (temp > 0)
    {
        rem = temp % 10;
        sum += pow(rem, digits);
        temp /= 10;
    }
    if (sum == num)
        printf("%d is an Armstrong number", num);
    else
        printf("%d is not an Armstrong number", num);
}