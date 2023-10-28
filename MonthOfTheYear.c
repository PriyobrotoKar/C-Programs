#include <stdio.h>

int main()
{
    int days, month;
    printf("CHOOSE MONTH FORMAT(31 DAYS/30 DAYS/28 OR 29 DAYS):");
    scanf("%d", &days);
    switch (days)
    {
    case 31:
        printf("January, March, May, July, August, October, December");
        break;
    case 30:
        printf("April, June, September, November");
        break;
    case 28:
    case 29:
        printf("February");
        break;

    default:
        printf("Input is invalid");
        break;
    }
}