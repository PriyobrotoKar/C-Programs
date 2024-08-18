#include <stdio.h>
#include <limits.h>

#define MIN(a, b) ((a < b) ? a : b)

int visited[5];
int dist[][4] = {{0, 10, 15, 20},
                 {5, 0, 9, 10},
                 {6, 13, 0, 12},
                 {8, 8, 9, 0}};
int start = 0;

int tsp(int s, int count)
{
    if (count == 4)
    {
        return dist[s][start];
    }
    int minCost = INT_MAX;
    for (int i = 0; i < 4; i++)
    {
        if (visited[i])
            continue;
        visited[i] = 1;

        int currCost = dist[s][i];
        currCost = currCost + tsp(i, count + 1);
        minCost = MIN(minCost, currCost);

        visited[i] = 0;
    }

    return minCost;
}

int main()
{
    int n = 4;

    int minCost = tsp(start, 0);

    printf("%d", minCost);
}
