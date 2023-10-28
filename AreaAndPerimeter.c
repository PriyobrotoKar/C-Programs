#include <stdio.h>

void main()
{
    int length, breadth, area, perimeter;
    printf("Enter lenght and breadth:\n");
    scanf("%d %d", &length, &breadth);
    area = length * breadth;
    perimeter = 2 * (length + breadth);
    printf("Area = %d and Perimeter = %d", area, perimeter);
}