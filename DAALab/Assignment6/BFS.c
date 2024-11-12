
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAX_NODES 100

// Structure to represent a queue
struct Queue
{
    int items[MAX_NODES];
    int front;
    int rear;
};

// Function to create a queue
struct Queue *createQueue()
{
    struct Queue *queue = (struct Queue *)malloc(sizeof(struct Queue));
    queue->front = -1;
    queue->rear = -1;
    return queue;
}

// Check if the queue is empty
bool isEmpty(struct Queue *queue)
{
    return queue->front == -1;
}

// Enqueue an element
void enqueue(struct Queue *queue, int value)
{
    if (queue->rear == MAX_NODES - 1)
    {
        printf("Queue is full\n");
        return;
    }
    if (queue->front == -1)
        queue->front = 0;
    queue->rear++;
    queue->items[queue->rear] = value;
}

// Dequeue an element
int dequeue(struct Queue *queue)
{
    if (isEmpty(queue))
    {
        printf("Queue is empty\n");
        return -1;
    }
    int item = queue->items[queue->front];
    if (queue->front >= queue->rear)
    {
        queue->front = queue->rear = -1;
    }
    else
    {
        queue->front++;
    }
    return item;
}

// BFS algorithm
void BFS(int graph[MAX_NODES][MAX_NODES], int numNodes, int startNode)
{
    bool visited[MAX_NODES] = {false};
    int distance[MAX_NODES];

    for (int i = 0; i < numNodes; i++)
    {
        distance[i] = -1; // Initialize distances as -1 (unreachable)
    }

    struct Queue *queue = createQueue();

    visited[startNode] = true;
    distance[startNode] = 0;
    enqueue(queue, startNode);

    while (!isEmpty(queue))
    {
        int currentNode = dequeue(queue);
        printf("%d ", currentNode);

        for (int i = 0; i < numNodes; i++)
        {
            if (graph[currentNode][i] == 1 && !visited[i])
            { // Check adjacency and if not visited
                visited[i] = true;
                distance[i] = distance[currentNode] + 1;
                enqueue(queue, i);
            }
        }
    }

    free(queue);
}

int main()
{
    int numNodes = 6;

    int graph[MAX_NODES][MAX_NODES] = {
        // 0  1  2  3  4  5
        {0, 1, 1, 0, 0, 0}, // Node 0 is connected to 1 and 2
        {1, 0, 1, 1, 0, 0}, // Node 1 is connected to 0, 2, and 3
        {1, 1, 0, 0, 1, 0}, // Node 2 is connected to 0, 1, and 4
        {0, 1, 0, 0, 1, 1}, // Node 3 is connected to 1, 4, and 5
        {0, 0, 1, 1, 0, 1}, // Node 4 is connected to 2, 3, and 5
        {0, 0, 0, 1, 1, 0}  // Node 5 is connected to 3 and 4
    };

    int startNode = 0; // Starting from node 0
    printf("BFS Traversal from node %d: ", startNode);
    BFS(graph, numNodes, startNode);

    return 0;
}
