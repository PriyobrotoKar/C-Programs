#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

int *bellmanFord(int V, int graph[][V], int S)
{
    int *dist = (int *)malloc(sizeof(int) * V);

    for (int i = 0; i < V; i++)
    {
        dist[i] = INT_MAX;
    }

    dist[S] = 0;

    for (int i = 0; i < V; i++)
    {
        for (int j = 0; j < V; j++)
        {
            for (int k = 0; k < V; k++)
            {
                if (dist[j] != INT_MAX && graph[j][k] != 0 && dist[j] + graph[j][k] < dist[k])
                {
                    dist[k] = dist[j] + graph[j][k];
                }
            }
        }
    }

    for (int i = 0; i < V; i++)
    {
        for (int j = 0; j < V - 1; j++)
        {
            if (dist[j] != INT_MAX && graph[j][i] != 0 && dist[j] + graph[j][i] < dist[i])
            {
                printf("Graph contains a negative weight cycle\n");
                return 0;
            }
        }
    }

    return dist;
}

int main()
{
    int graph[5][5] = {
        {0, 1, 4, 0, 0},
        {0, 0, 3, 2, 0},
        {0, 0, 0, 0, 1},
        {0, 0, 0, 0, 4},
        {0, 0, 0, 0, 0}};

    int *dist = bellmanFord(5, graph, 0);

    printf("Shortest distances from vertex %d:\n", 0);
    for (int i = 0; i < 5; i++)
    {
        printf("%d -> %d: %d\n", 0, i, dist[i]);
    }

    return 0;
}
