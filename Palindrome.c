#include <stdio.h>

void main()
{
    int num, revnum = 0, rem;
    printf("Enter a number:");
    scanf("%d", &num);
    int temp = num;
    while (temp > 0)
    {
        rem = temp % 10;
        revnum = revnum * 10 + rem;
        temp /= 10;
    }
    if (revnum == num)
        printf("%d is a palindrome number", num);
    else
        printf("%d is not a palindrome number", num);
}