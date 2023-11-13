//? Question :  To find whether a given year is a leap year or not
#include <stdio.h>

void main()
{
    int year;
    printf("Enter a year:");
    scanf("%d", &year);
    if (!(year % 4 || year % 400) || year % 100)
    {
        printf("%d is a leap year", year);
    }
    else
    {
        printf("%d is not a leap year", year);
    }
}