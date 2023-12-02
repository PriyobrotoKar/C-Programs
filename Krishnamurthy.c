#include <stdio.h>

void main()
{
    int sum = 0, num, digit, fact;
    printf("Enter a number:");
    scanf("%d", &num);
    int temp = num;
    while (temp > 0)
    {
        fact = 1;
        digit = temp % 10;
        for (int i = 2; i <= digit; i++)
        {
            fact = fact * i;
        }
        sum += fact;
        temp /= 10;
    }
    if (sum == num)
        printf("%d is Krishnamurthy number", num);
    else
        printf("%d is not Krishnamurthy number", num);
}