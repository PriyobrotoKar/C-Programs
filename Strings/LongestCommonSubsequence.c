#include <stdio.h>
#include <string.h>
#include <stdlib.h>

char *slice(const char str[], int start)
{
    int len = strlen(str);
    if (start >= len)
    {
        return "";
    }
    char *slicedStr = (char *)malloc((len - start + 1) * sizeof(char));
    if (slicedStr == NULL)
    {
        printf("Memory allocation failed\n");
        exit(1);
    }
    strcpy(slicedStr, str + start);
    return slicedStr;
}

char *LongestCommonSubsequence(char word1[], char word2[])
{
    if (strlen(word1) == 0 || strlen(word2) == 0)
    {
        return "";
    }

    if (word1[0] == word2[0])
    {
        char *remainderLCS = LongestCommonSubsequence(slice(word1, 1), slice(word2, 1));
        char *result = (char *)malloc((strlen(remainderLCS) + 2) * sizeof(char));
        if (result == NULL)
        {
            printf("Memory allocation failed\n");
            exit(1);
        }
        result[0] = word1[0];
        strcpy(result + 1, remainderLCS);
        return result;
    }
    else
    {
        char *seq1 = LongestCommonSubsequence(slice(word1, 1), word2);
        char *seq2 = LongestCommonSubsequence(word1, slice(word2, 1));

        if (strlen(seq1) >= strlen(seq2))
        {
            return seq1;
        }
        else
        {
            return seq2;
        }
    }
}

int main()
{
    char str1[] = "abcdef";
    char str2[] = "abe";
    char *ans = LongestCommonSubsequence(str1, str2);
    printf(ans, "%s");
    return 0;
}
