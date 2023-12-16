#include <stdio.h>
#include <string.h>

void sortStringslexicographically(char words[][50], int size)
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
    int r;
    printf("Enter the no. words:");
    scanf("%d", &r);
    char words[r][50];

    int i = 0;
    while (i < r)
    {
        printf("Enter a word: ");
        scanf("%s", words[i]);
        i++;
    }
    sortStringslexicographically(words, r);
    i = 0;
    while (i < r)
    {
        printf("%s ", words[i]);
        i++;
    }
}