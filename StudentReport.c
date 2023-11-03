#include <stdio.h>

void main()
{
    int a, b, c, d, e;
    float per;
    printf("Enter the marks of all the subjects:");
    scanf("%d %d %d %d %d", &a, &b, &c, &d, &e);
    per = (a + b + c + d + e) / 5.0;

    if (per >= 60)
        printf("1st Position");
    else if (per >= 50)
        printf("2nd Position");
    else if (per >= 40)
        printf("3rd Position");
    else
        printf("Fail");
}