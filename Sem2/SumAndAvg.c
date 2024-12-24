//? Question: Print the sum and average of n natural numbers

#include <stdio.h>

void main()
{
    int n, sum = 0;
    float avg;
    printf("Enter the number of natural numbers:");
    scanf("%d", &n);
    for (int i = 1; i <= n; i++)
    {
        sum += i;
    }
    avg = (float)sum / n;
    printf("Sum = %d and Average = %f", sum, avg);
}