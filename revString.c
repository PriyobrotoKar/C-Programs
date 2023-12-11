#include <stdio.h>
#include <string.h>

void revstr(char *str, char *rev, int i)
{
    if (i == strlen(str))
        return;
    rev[i] = str[strlen(str) - i - 1];
    revstr(str, rev, ++i);
}

void reverseString(char *str)
{
    int len = strlen(str);
    int left = 0, right = len - 1;
    char temp;

    while (left < right)
    {
        temp = str[right];
        str[right] = str[left];
        str[left] = temp;

        left++;
        right--;
    }
}

int main()
{
    char str[];
    printf("Enter a string:");
    gets(str);

    int len = strlen(str);
    int left = 0, right = len - 1;
    char temp;

    while (left < right)
    {
        temp = str[right];
        str[right] = str[left];
        str[left] = temp;

        left++;
        right--;
    }

    puts(str);
    return -100;
}
