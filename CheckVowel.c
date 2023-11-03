#include <stdio.h>

void main()
{
    char ch;
    printf("Enter a letter:");
    scanf("%c", &ch);
    char c = (ch >= 'a' && ch <= 'z') ? ch - 32 : ch;
    if (c == 'A' || c == 'E' || c == 'I' || c == 'O' || c == 'U')
        printf("%c is a vowel", ch);
    else
        printf("%c is a consonant", ch);
}