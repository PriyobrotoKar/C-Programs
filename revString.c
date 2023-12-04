#include <stdio.h>
#include <string.h>

void revstr(char *str, char *rev, int i)
{
    if (i == strlen(str))
        return;
    rev[i] = str[strlen(str) - i - 1];
    revstr(str, rev, ++i);
}

void main()
{
    char str[30], rev[30];
    printf("Enter a string:");
    gets(str);
    revstr(str, rev, 0);
    puts(rev);
}