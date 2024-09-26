#include <stdio.h>

#define INT_MAX 999999

void printMST(int n, int parent[], int graph[n][n])
{
    int totalCost = 0;
    for (int i = 1; i < n; i++)
    {
        totalCost += graph[i][parent[i]];
        printf("%d - %d %d \n", parent[i], i, graph[i][parent[i]]);
    }
    printf("Total Cost: %d\n", totalCost);
}

void primsMST(int n, int graph[n][n])
{
    int parent[n];
    int key[n];
    int mstSet[n];

    for (int i = 0; i < n; i++)
    {
        key[i] = INT_MAX;
        mstSet[i] = 0;
    }

    key[0] = 0;
    parent[0] = -1;

    for (int count = 0; count < n - 1; count++)
    {
        int u = -1;
        for (int i = 0; i < n; i++)
        {
            if (!mstSet[i] && (u == -1 || key[i] < key[u]))
                u = i;
        }

        mstSet[u] = 1;

        for (int v = 0; v < n; v++)
        {
            if (graph[u][v] && !mstSet[v] && graph[u][v] < key[v])
            {
                parent[v] = u;
                key[v] = graph[u][v];
            }
        }
    }

    printMST(n, parent, graph);
}

int main()
{
    int graph[5][5] = {
        {0, 2, 0, 6, 0},
        {2, 0, 3, 8, 5},
        {0, 3, 0, 0, 7},
        {6, 8, 0, 0, 9},
        {0, 5, 7, 9, 0}};

    primsMST(5, graph);

    return 0;
}
