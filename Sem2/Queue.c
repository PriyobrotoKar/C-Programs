#include <stdio.h>
#include <stdlib.h>

int queue[10];
int front = -1, rear = -1;



void insert(int data)
{
    if (front == -1 && rear == -1)
    {
        front++;
        rear++;
    }
    else
    {
        rear = (rear + 1) % 10;
        if (rear == front)
        {
            printf("OVERFLOW\n");
            return;
        }
    }
    queue[rear] = data;
}

void delete()
{

    if (front == -1 && rear == -1)
    {
        printf("Queue is empty\n");
    }
    else if (front == rear)
    {
        int data = queue[front];
        front = rear = -1;
        printf("%d has been deleted\n", data);
    }
    else
    {
        int data = queue[front];
        front = (front + 1) % 10;
        printf("%d has been deleted\n", data);
    }
}

void display()
{
    if (front == -1 && rear == -1)
    {
        printf("Queue is empty\n");
        return;
    }

    printf("The elements in queue are:\n");

    int i = front;
    while (i != rear + 1)
    {
        printf("%d ", queue[i]);
        i = (i + 1) % 10;
    }
    printf("\n");
}

int main()
{

    while (1)
    {
        int ch;

        printf("1.Insert\n");
        printf("2.Delete\n");
        printf("3.Display\n");
        printf("4.Exit\n");
        printf("Enter the choice:");
        scanf("%d", &ch);

        switch (ch)
        {
        case 1:
        {
            int n;
            printf("Enter a no.:");
            scanf("%d", &n);
            insert(n);
            break;
        }

        case 2:
            delete ();
            break;

        case 3:
            display();
            break;

        case 4:
            exit(1);

        default:
            printf("Wrong choice!!");
        }
    }

    return 0;
}
