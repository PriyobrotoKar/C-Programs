#include <stdio.h>
#include <string.h>
#include <stdlib.h>

void sortStringslexicographically(char (*words)[50], int size)
{
    char temp[50];
    for (int j = 0; j < size - 1; j++)
    {
        int minStrInd = j;
        for (int i = 1; i < size; i++)
        {
            if (strcmp(words[i], words[minStrInd]) < 0)
            {
                minStrInd = i;
            }
        }
        strcpy(temp, words[j]);
        strcpy(words[j], words[minStrInd]);
        strcpy(words[minStrInd], temp);
    }
}

void main()
{
    int total;
    printf("Enter the no. words:");
    scanf("%d", &total);
    char(*words)[50] = malloc(total * sizeof(char *));

    int i = 0;
    while (i < total)
    {
        printf("Enter a word: ");
        scanf("%s", words[i]);
        i++;
    }
    sortStringslexicographically(words, total);
    i = 0;
    while (i < total)
    {
        printf("%s ", words[i]);
        i++;
    }
}