## Question
**Write a C program to implement the Bellman Ford ALgorithm.**

## Diagram
// Draw the graph which represents the graph array in source code.

## Algorithm
```bash
STEP 1: Initialize an array dist of size V to hold distances from the source node S.

STEP 2: Set all elements of dist to INT_MAX (infinity), except for the source node S, which is set to 0.

STEP 3: Repeat the following steps 4-6 relaxation process for V-1 times:

STEP 4: For each node u in the graph, consider all its neighbors v.

STEP 5: If the distance to node u is not INT_MAX and the edge u -> v exists, check if a shorter path to v can be found through u.

STEP 6: If dist[u] + weight(u, v) < dist[v], update dist[v] to the new minimum distance.

STEP 7: After V-1 iterations, check for negative-weight cycles with step 8 and 9

STEP 8: For each node u, check all its neighbors v again.

STEP 9: If dist[u] + weight(u, v) < dist[v], it indicates a negative-weight cycle, and the algorithm reports it.

STEP 10: Return the dist array containing the shortest distances from the source to all other nodes, or report if a negative-weight cycle is detected.
```

## Complexity Analysis

[Geeks For Geeks](https://www.geeksforgeeks.org/time-and-space-complexity-of-bellman-ford-algorithm/)

## Source Code
```c
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
```

## Output
```bash
Shortest distances from vertex 0:
0 -> 0: 0
0 -> 1: 1
0 -> 2: 4
0 -> 3: 3
0 -> 4: 5
```

## Discussion
The Bellman-Ford algorithm’s primary principle is that it starts with a single source and calculates the distance to each node. The distance is initially unknown and assumed to be infinite, but as time goes on, the algorithm relaxes those paths by identifying a few shorter paths. Hence it is said that Bellman-Ford is based on “Principle of Relaxation“.
The Bellman-Ford algorithm is used in networking for efficient routing, GPS for calculating optimal routes, and in transportation to minimize travel costs. It also aids in path planning in robotics and game development by handling variable path costs. However, its drawback is the inability to handle graphs with negative-weight cycles.

### Why Relaxing Edges N-1 times, gives us Single Source Shortest Path?
Relaxing edges N-1 times in the Bellman-Ford algorithm guarantees that the algorithm has explored all possible paths of length up to N-1, which is the maximum possible length of a shortest path in a graph with N vertices. This allows the algorithm to correctly calculate the shortest paths from the source vertex to all other vertices, given that there are no negative-weight cycles.

### Why Does the Reduction of Distance in the N’th Relaxation Indicates the Existence of a Negative Cycle?
As previously discussed, achieving the single source shortest paths to all other nodes takes N-1 relaxations. If the N’th relaxation further reduces the shortest distance for any node, it implies that a certain edge with negative weight has been traversed once more. It is important to note that during the N-1 relaxations, we presumed that each vertex is traversed only once. However, the reduction of distance during the N’th relaxation indicates revisiting a vertex.

## Question
**Write a C program to implement the Prim's ALgorithm to find the minimum spanning tree and print it's cost.**

## Algorithm
```bash
Step 1: Initialize parent, key, and mstSet arrays for n vertices.
Step 2: Set all keys to infinity (INT_MAX) and mstSet values to 0 (not included in MST).
Step 3: Set the key of the starting vertex (vertex 0) to 0 and its parent to -1.
Step 4: Repeat the steps 5-7 n-1 times to construct the MST:
Step 5: Find a vertex u that is not in mstSet and has the smallest key value.
Step 6: Mark vertex u as included in the MST (mstSet[u] = 1).
Step 7: For each adjacent vertex v of u, if an edge exists between u and v, and v is not in the MST, update the parent and key of v if the edge weight is smaller than the current key.
Step 8: After the loop, call the printMST function to print the MST using the parent array.
```
## Complexity Analysis
### 1. Initializing the Arrays (key, mstSet, parent):
This takes O(n) time, where n is the number of vertices in the graph.
### 2. Main Loop (for (count = 0; count < n - 1; count++)):
This loop runs n-1 times, as we need to include n-1 edges in the MST for a graph with n vertices. For each iteration:

**Finding the minimum key vertex (Step 5):**
 This is done using a linear search, which takes O(n) time.Since this step is repeated n-1 times, the total time for this is O(n^2).

**Updating adjacent vertices (Step 7):**
For each vertex u, we check all vertices v to see if an edge exists (graph[u][v] != 0), and if so, update the key and parent arrays. This operation takes O(n) for each vertex u.
Since this step is performed n-1 times, the total time for this is also O(n^2).

### 3. Total Time Complexity:
Initialization: O(n).

Main Loop (Finding minimum + updating keys): O(n^2)

**Thus, the overall time complexity is O(n^2).**

### Space Complexity:
O(n) for the key, parent, and mstSet arrays.
O(n^2) for the adjacency matrix graph[n][n] since it stores the edge weights.
Thus, the space complexity is O(n^2) due to the adjacency matrix.

### Source Code
```c
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

```

### Output
```bash
0 - 1 2 
1 - 2 3 
0 - 3 6 
1 - 4 5 
Total Cost: 16
```

## Discussion
Chatgpt kore nao plis r parchi na raat 2:19 baje


## Question
**Write a C program to implement the Kruskal's ALgorithm to find the minimum spanning tree and find the cost.**

## Algorithm
```bash

```
