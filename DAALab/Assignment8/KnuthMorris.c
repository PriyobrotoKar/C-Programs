#include <stdio.h>
#include <string.h>

void computeLPSArray(const char *pattern, int M, int *lps)
{
    int length = 0;
    int i = 1;

    lps[0] = 0;

    while (i < M)
    {
        if (pattern[i] == pattern[length])
        {
            length++;
            lps[i] = length;
            i++;
        }
        else
        {
            if (length != 0)
            {
                length = lps[length - 1];
            }
            else
            {
                lps[i] = 0;
                i++;
            }
        }
    }
}

void KMP(const char *text, const char *pattern)
{
    int N = strlen(text);
    int M = strlen(pattern);

    int lps[M];
    computeLPSArray(pattern, M, lps);

    int i = 0;
    int j = 0;

    while (i < N)
    {
        if (pattern[j] == text[i])
        {
            i++;
            j++;
        }

        if (j == M)
        {
            printf("Pattern found at index %d\n", i - j);
            j = lps[j - 1];
        }
        else if (i < N && pattern[j] != text[i])
        {
            if (j != 0)
            {
                j = lps[j - 1];
            }
            else
            {
                i++;
            }
        }
    }
}

int main()
{
    const char *text = "ABABDABACDABABCABAB";
    const char *pattern = "ABABCABAB";

    printf("Text: %s\n", text);
    printf("Pattern: %s\n", pattern);

    KMP(text, pattern);

    return 0;
}
