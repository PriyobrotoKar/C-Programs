// Dynamic memory allocation for the array of strings
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define BUFFER_SIZE 200

int main()
{
    char **strings;
    int total = 0;
    printf("Enter the number of strings:");
    scanf("%d", &total);

    strings = malloc(total * sizeof(char *));
    char buffer[BUFFER_SIZE];
    int length = 0;

    while (getchar() != '\n')
        ;

    for (int i = 0; i < total; i++)
    {
        printf("Enter string %d: ", i + 1);
        fgets(buffer, BUFFER_SIZE, stdin);
        length = strlen(buffer);
        buffer[length - 1] = '\0';
        strings[i] = malloc(length * sizeof(char));
        strcpy(strings[i], buffer);
    }
    // print the strings
    for (int i = 0; i < total; i++)
    {
        printf("String %d is %s\n", i + 1, strings[i]);
    }

    return 0;
}
