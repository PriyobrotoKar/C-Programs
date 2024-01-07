
#include <stdio.h>
#include <string.h>
int main()
{

    typedef struct Cricketer
    {
        char name[30];
        int age;
        int matches;
        float avgRun;
    } Cricketer;
    Cricketer arr[3];
    for (int i = 0; i < 3; i++)
    {

        printf("Enter the name of the cricketer = ");
        fgets(arr[i].name, 30, stdin);
        printf("Enter the age of the cricketer = ");
        scanf("%d", &arr[i].age);
        fflush(stdin);
        printf("Enter matches of the cricketer =");
        scanf("%d", &arr[i].matches);
        fflush(stdin);
        printf("Enter average run in each matches of the cricketer = ");
        scanf("%f", &arr[i].avgRun);

        fflush(stdin);
    }

    for (int i = 0; i < 3; i++)
    {

        printf(" \n%s ", arr[i].name);
        printf("\nmatches %d", arr[i].matches);
        printf("\naverage runs %f", arr[i].avgRun);
    }
    return 0;
}