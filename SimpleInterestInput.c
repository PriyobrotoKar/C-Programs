#include <stdio.h>

void main()
{
    int P, t;
    float Si, r;
    printf("Enter the Principal Amount, Interest Rate and Time in years:\n");
    scanf("%d %f %d", &P, &r, &t);
    Si = P * r * t / 100;
    printf("Simple Interest : %f", Si);
}