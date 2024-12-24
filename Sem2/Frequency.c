#include <stdio.h>
#include <string.h>

void main()
{
    char str[30];
    char ch;
    int freq = 0;
    printf("Enter a sentence:");
    gets(str);
    printf("Enter a character to find it's frequency:");
    scanf("%c", &ch);

    int i = 0;
    while (i < strlen(str))
    {
        if (str[i] == ch)
        {
            freq++;
        }
        i++;
    }

    printf("The frequency of %c is : %d", ch, freq);
}