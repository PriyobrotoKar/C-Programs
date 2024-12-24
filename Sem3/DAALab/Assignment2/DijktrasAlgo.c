#include <stdio.h>
#include <limits.h>

int minDistance(int dist[], int visited[], int V)
{
    // Initialize min value
    int min = INT_MAX, min_index;

    for (int v = 0; v < V; v++)
        if (visited[v] == 0 && dist[v] <= min)
            min = dist[v], min_index = v;

    return min_index;
}

void printSolution(int dist[], int V)
{
    printf("Vertex \t\t Distance from Source\n");
    for (int i = 0; i < V; i++)
        printf("%d \t\t\t\t %d\n", i, dist[i]);
}

void dijkstra(int V, int src, int graph[V][V])
{
    int dist[V];

    int visited[V];
    for (int i = 0; i < V; i++)
        dist[i] = INT_MAX, visited[i] = 0;

    dist[src] = 0;

    for (int count = 0; count < V - 1; count++)
    {
        int u = minDistance(dist, visited, V);

        visited[u] = 1;

        for (int v = 0; v < V; v++)

            if (!visited[v] && graph[u][v] && dist[u] != INT_MAX && dist[u] + graph[u][v] < dist[v])
                dist[v] = dist[u] + graph[u][v];
    }

    printSolution(dist, V);
}

int main()
{
    int graph[5][5] = {{0, 10, 0, 0, 5},
                       {0, 0, 1, 0, 2},
                       {0, 0, 0, 4, 0},
                       {7, 0, 6, 0, 0},
                       {0, 3, 9, 2, 0}};

    dijkstra(5, 0, graph);
}
