#include <stdio.h>
#include <stdlib.h>

#define MAX_NODES 6
void dfs(int graph[MAX_NODES][MAX_NODES], int visited[MAX_NODES], int startNode)
{
    int stack[MAX_NODES], top = -1;

    // Push the starting node onto the stack
    stack[++top] = startNode;
    visited[startNode] = 1; // Mark the start node as visited

    // While the stack is not empty
    while (top != -1)
    {
        // Pop a node from the stack
        int node = stack[top--];
        printf("%d ", node); // Print the node

        // Visit all the adjacent nodes of the popped node
        for (int i = 0; i < MAX_NODES; i++)
        {
            if (graph[node][i] == 1 && !visited[i])
            {
                stack[++top] = i; // Push unvisited adjacent nodes onto the stack
                visited[i] = 1;   // Mark them as visited
            }
        }
    }
}

int main()
{
    int visited[MAX_NODES] = {0}; // Array to keep track of visited nodes

    int graph[MAX_NODES][MAX_NODES] = {
        {0, 1, 1, 0, 0, 0}, // Node 0 is connected to 1, 2
        {1, 0, 0, 1, 1, 0}, // Node 1 is connected to 0, 3, 4
        {1, 0, 0, 0, 0, 1}, // Node 2 is connected to 0, 5
        {0, 1, 0, 0, 0, 0}, // Node 3 is connected to 1
        {0, 1, 0, 0, 0, 0}, // Node 4 is connected to 1
        {0, 0, 1, 0, 0, 0}  // Node 5 is connected to 2
    };
    // Start DFS from node 0
    printf("DFS Traversal from node 0: ");
    dfs(graph, visited, 0);

    return 0;
}
