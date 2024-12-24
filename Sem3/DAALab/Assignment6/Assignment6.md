## Question
**Write a C program to implement Breadth First Search on a Graph.**

## Diagram

## Algorithm
1. BEGIN
2. Initialize a queue Q and enqueue the starting node s.
3. Mark s as visited and set its distance to 0.
4. While Q is not empty:
    4.1. Dequeue a node u from Q.
    4.2. For each adjacent node v of u:
        4.2.1. If v has not been visited:
        4.2.2. Mark v as visited.
        4.2.3. Set distance[v] to distance[u] + 1.
        4.2.4. Enqueue v into Q.
    4.3. END FOR
5. END WHILE
6. END

## Complexity Analysis
### Time Complexity
Explanation: 

The time complexity of BFS is O(V + E), where:
V represents the number of vertices (nodes) in the graph.
E represents the number of edges (connections between nodes).

BFS explores every vertex and examines each edge once, resulting in this linear time complexity. This makes it efficient for traversing graphs, whether large or small.

Scenarios:

Best Case: BFS quickly finds the target node close to the start.

Worst Case: BFS needs to explore the entire graph before reaching the target node.

Average Case: BFS typically explores multiple levels of the graph.

### Space Complexity
Explanation: The space complexity of BFS is O(V), where V is the number of vertices.

This is because BFS uses
A queue to store vertices that are waiting to be explored.
A visited set to track which nodes have already been visited.
In the worst case, the size of the queue could be as large as the number of vertices at the largest level of the graph, leading to O(V) space usage.

Memory Usage: The memory needed for BFS depends on the graph size. In addition to the queue, BFS needs space for the visited set or array, which has a size of O(V).

## Source Code
``` C
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAX_NODES 100

// Structure to represent a queue
struct Queue {
    int items[MAX_NODES];
    int front;
    int rear;
};

// Function to create a queue
struct Queue* createQueue() {
    struct Queue* queue = (struct Queue*)malloc(sizeof(struct Queue));
    queue->front = -1;
    queue->rear = -1;
    return queue;
}

// Check if the queue is empty
bool isEmpty(struct Queue* queue) {
    return queue->front == -1;
}

// Enqueue an element
void enqueue(struct Queue* queue, int value) {
    if (queue->rear == MAX_NODES - 1) {
        printf("Queue is full\n");
        return;
    }
    if (queue->front == -1) queue->front = 0;
    queue->rear++;
    queue->items[queue->rear] = value;
}

// Dequeue an element
int dequeue(struct Queue* queue) {
    if (isEmpty(queue)) {
        printf("Queue is empty\n");
        return -1;
    }
    int item = queue->items[queue->front];
    if (queue->front >= queue->rear) {
        queue->front = queue->rear = -1;
    } else {
        queue->front++;
    }
    return item;
}

// BFS algorithm
void BFS(int graph[MAX_NODES][MAX_NODES], int numNodes, int startNode) {
    bool visited[MAX_NODES] = {false};
    int distance[MAX_NODES];

    for (int i = 0; i < numNodes; i++) {
        distance[i] = -1; // Initialize distances as -1 (unreachable)
    }

    struct Queue* queue = createQueue();

    visited[startNode] = true;
    distance[startNode] = 0;
    enqueue(queue, startNode);

    while (!isEmpty(queue)) {
        int currentNode = dequeue(queue);
        printf("Visited node: %d\n", currentNode);

        for (int i = 0; i < numNodes; i++) {
            if (graph[currentNode][i] == 1 && !visited[i]) { // Check adjacency and if not visited
                visited[i] = true;
                distance[i] = distance[currentNode] + 1;
                enqueue(queue, i);
            }
        }
    }

    // Print distances
    printf("\nDistances from start node %d:\n", startNode);
    for (int i = 0; i < numNodes; i++) {
        printf("Node %d: %d\n", i, distance[i]);
    }

    free(queue);
}

int main() {
    int numNodes = 4;
    int graph[MAX_NODES][MAX_NODES] = {
        {0, 1, 1, 0}, // Adjacency matrix representation
        {1, 0, 0, 1},
        {1, 0, 0, 1},
        {0, 1, 1, 0}
    };

    int startNode = 0; // Starting from node 0
    BFS(graph, numNodes, startNode);

    return 0;
}

```

## Output
```
BFS Traversal from node 0: 0 1 2 3 4 5
```

## Discussion
BFS guarantees the shortest path in an unweighted graph by exploring nodes in increasing order of distance from the start. This is particularly useful in network routing, such as finding the most efficient path in road networks (e.g., Google Maps uses BFS for unweighted roads).
Web crawlers use BFS to systematically explore web pages. Starting from a seed URL, the crawler visits all links on that page, then proceeds to follow links from those pages, layer by layer. This method ensures a comprehensive search across a defined depth.

## Question
**Write a C program to implement Depth First Search on a Graph.**

## Diagram

## Algorithm
1. BEGIN
2. Create an empty stack S and push the starting node s onto S.
3. Mark s as visited and set its distance to 0.
4. While S is not empty:
    4.1. Pop a node u from S. 
    4.2. For each adjacent node v of u: 
        4.2.1. If v has not been visited
        4.2.2. Mark v as visited.
        4.2.3. Set distance[v] to distance[u] + 1. 
        4.2.4. Push v onto S. 
    4.3. END FOR
5. END WHILE
6. END

## Complexity Analysis
### Time Complexity
Explanation:

The time complexity of DFS is O(V + E), where:
V represents the number of vertices (nodes) in the graph.
E represents the number of edges (connections between nodes).

DFS explores every vertex and examines each edge exactly once during the traversal. This linear time complexity holds true regardless of the size or structure of the graph.

Scenarios:
Best Case: DFS quickly finds the target node at the start of a branch.
Worst Case: DFS must explore all vertices and edges before finding the target or completing the traversal.
Average Case: DFS explores nodes deeply before backtracking, which depends on the structure of the graph.

### Space Complexity
Explanation:

The space complexity of DFS is O(V), where V is the number of vertices.

This is because DFS uses:
A stack (either an explicit stack if implemented iteratively or the call stack in recursion) to keep track of vertices.
A visited set or array to track which nodes have already been visited.

In the worst case, such as a graph structured like a linear chain, the space needed for the stack could be as large as the number of nodes, leading to O(V) space usage.

Memory Usage: The memory needed for DFS depends on the maximum depth of the recursion or the stack size, which could be up to O(V) in the worst case.

## Source Code
``` C
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


```

## Output
```
DFS Traversal from node 0: 0 2 5 1 4 3
```

## Discussion
Depth-first search (DFS) is an algorithm for searching a graph or tree data structure. The algorithm starts at the root (top) node of a tree and goes as far as it can down a given branch (path), then backtracks until it finds an unexplored path, and then explores it.Depth-first searches are often used as subroutines in other more complex algorithms. For example, the matching algorithm, Hopcroft–Karp, uses a DFS as part of its algorithm to help to find a matching in a graph. DFS is also used in tree-traversal algorithms, also known as tree searches, which have applications in the traveling-salesman problem and the Ford-Fulkerson algorithm.


