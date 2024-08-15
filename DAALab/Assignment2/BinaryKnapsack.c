#include <stdio.h>
#include <math.h>
#include <limits.h>
#define MAX(a, b) (((a) > (b)) ? (a) : (b))

int knapSack(int ind, int W, int w[], int val[])
{
    if (ind == 0)
    {
        if (w[ind] <= W)
            return val[ind];
        else
            return 0;
    }
    int take = INT_MIN;
    // not-taking it
    int notTake = 0 + knapSack(ind - 1, W, w, val);
    if (w[ind] <= W)
        // taking it
        take = val[ind] + knapSack(ind - 1, W - w[ind], w, val);

    return MAX(notTake, take);
}

int main()
{
    int w[3] = {3, 4, 5};
    int v[3] = {30, 50, 60};
    int maxWeight = 8;

    int dp[3][maxWeight + 1];

    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j <= maxWeight; j++)
        {
            dp[i][j] = 0;
        }
    }

    for (int W = w[0]; W <= maxWeight; W++)
        dp[0][W] = v[0];

    for (int ind = 1; ind < 3; ind++)
    {
        for (int W = 0; W <= maxWeight; W++)
        {
            int take = INT_MIN;
            // not-taking it
            int notTake = 0 + dp[ind - 1][W];
            if (w[ind] <= W)
                // taking it
                take = v[ind] + dp[ind - 1][W - w[ind]];

            dp[ind][W] = MAX(notTake, take);
        }
    }

    printf("%d\n", dp[2][maxWeight]);
}
