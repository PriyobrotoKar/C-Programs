#include <stdio.h>
#include <stdlib.h>

struct Edge
{
    int src, dest, weight;
};

struct subset
{
    int parent;
    int rank;
};

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

int find(struct subset subsets[], int i)
{
    if (subsets[i].parent != i)
        subsets[i].parent = find(subsets, subsets[i].parent);
    return subsets[i].parent;
}

void Union(struct subset subsets[], int x, int y)
{
    int rootX = find(subsets, x);
    int rootY = find(subsets, y);

    if (subsets[rootX].rank < subsets[rootY].rank)
        subsets[rootX].parent = rootY;
    else if (subsets[rootX].rank > subsets[rootY].rank)
        subsets[rootY].parent = rootX;
    else
    {
        subsets[rootY].parent = rootX;
        subsets[rootX].rank++;
    }
}

int compareEdges(const void *a, const void *b)
{
    struct Edge *a1 = (struct Edge *)a;
    struct Edge *b1 = (struct Edge *)b;
    return a1->weight > b1->weight;
}

void kruskalMST(int V, int E, int graph[][3])
{
    struct Edge edges[E];
    for (int i = 0; i < E; i++)
    {
        edges[i].src = graph[i][0];
        edges[i].dest = graph[i][1];
        edges[i].weight = graph[i][2];
    }

    qsort(edges, E, sizeof(edges[0]), compareEdges);

    struct subset *subsets = (struct subset *)malloc(V * sizeof(struct subset));
    for (int v = 0; v < V; v++)
    {
        subsets[v].parent = v;
        subsets[v].rank = 0;
    }

    struct Edge result[V];
    int e = 0;
    int i = 0;

    while (e < V - 1 && i < E)
    {
        struct Edge next_edge = edges[i++];
        int x = find(subsets, next_edge.src);
        int y = find(subsets, next_edge.dest);

        if (x != y)
        {
            result[e++] = next_edge;
            Union(subsets, x, y);
        }
    }

    int parent[V];
    int mstGraph[V][V];
    for (int i = 0; i < V; i++)
        for (int j = 0; j < V; j++)
            mstGraph[i][j] = 0;

    for (i = 0; i < e; i++)
    {
        parent[result[i].dest] = result[i].src;
        mstGraph[result[i].src][result[i].dest] = result[i].weight;
        mstGraph[result[i].dest][result[i].src] = result[i].weight;
    }

    printMST(V, parent, mstGraph);
    free(subsets);
}

int main()
{
    int V = 5;
    int E = 7;
    int graph[][3] = {{0, 1, 2}, {0, 3, 6}, {1, 2, 3}, {1, 3, 8}, {1, 4, 5}, {2, 4, 7}, {3, 4, 9}};
    kruskalMST(V, E, graph);
    return 0;
}
