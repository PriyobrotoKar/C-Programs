#include <stdio.h>
#include <limits.h>

#define V 4 // Number of vertices

int tsp(int graph[V][V])
{
    int dp[1 << V][V];
    int i, j, k, subset;

    // Initialize the dp table
    for (i = 0; i < (1 << V); i++)
    {
        for (j = 0; j < V; j++)
        {
            dp[i][j] = INT_MAX;
        }
    }

    // Start from the first city, so set dp[1][0] = 0
    dp[1][0] = 0;

    // Fill the dp table
    for (subset = 1; subset < (1 << V); subset++)
    {
        for (i = 0; i < V; i++)
        {
            if (subset & (1 << i))
            { // If i is in the subset
                for (j = 0; j < V; j++)
                {
                    if (subset & (1 << j) && i != j && dp[subset ^ (1 << i)][j] != INT_MAX)
                    {
                        dp[subset][i] = dp[subset][i] < dp[subset ^ (1 << i)][j] + graph[j][i]
                                            ? dp[subset][i]
                                            : dp[subset ^ (1 << i)][j] + graph[j][i];
                    }
                }
            }
        }
    }

    // Find the minimum path to return to the starting point
    int res = INT_MAX;
    for (i = 1; i < V; i++)
    {
        if (dp[(1 << V) - 1][i] + graph[i][0] < res)
        {
            res = dp[(1 << V) - 1][i] + graph[i][0];
        }
    }

    return res;
}

int main()
{
    int graph[V][V] = {
        {0, 10, 15, 20},
        {10, 0, 35, 25},
        {15, 35, 0, 30},
        {20, 25, 30, 0}};

    printf("The minimum cost is %d\n", tsp(graph));

    return 0;
}
