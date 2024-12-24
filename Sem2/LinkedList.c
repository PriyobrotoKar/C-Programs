#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node *next;
};

struct Node *head = NULL;

void insertAtHead(int data)
{
    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = NULL;

    if (head == NULL)
    {
        head = newNode;
    }
    else
    {
        newNode->next = head;
        head = newNode;
    }
    printf("%d has been successfully inserted at the end\n", data);
}
void insertAtTail(int data)
{
    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = NULL;

    if (head == NULL)
    {
        head = newNode;
    }
    else
    {
        struct Node *curr = head;
        while (curr->next)
        {
            curr = curr->next;
        }
        curr->next = newNode;
    }
    printf("%d has been successfully inserted at the tail\n", data);
}

void printNodes()
{
    if (head == NULL)
    {
        printf("List is empty!");
    }
    else
    {
        struct Node *curr = head;
        while (curr)
        {
            if (!curr->next)
            {
                printf("%d", curr->data);
            }
            else
            {
                printf("%d -> ", curr->data);
            }
            curr = curr->next;
        }
    }
}

int main()
{

    insertAtHead(34);
    insertAtHead(90);
    insertAtHead(22);

    insertAtTail(42);
    insertAtTail(52);

    printNodes();

    return 0;
}
