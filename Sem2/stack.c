#include <stdio.h>
#include <stdlib.h>
#define MAX_SIZE 10

int stack[MAX_SIZE];
int ch, top = -1;

void push(int n)
{
    if (top == MAX_SIZE - 1)
    {
        printf("OVERFLOW\n");
    }
    else
    {
        top++;
        stack[top] = n;
    }
}
void pop()
{
    if (top == -1)
    {
        printf("STACK IS EMPTY\n");
    }
    else
    {
        printf("Popped Element: %d\n", stack[top]);
        top--;
    }
}
void display()
{
    if (top == -1)
    {
        printf("STACK IS EMPTY");
    }
    else
    {
        printf("The elements are: ");

        for (int i = 0; i <= top; i++)
        {
            printf("%d ", stack[i]);
        }
    }
    printf("\n");
}

void main()
{
    int ch;
    while (1)
    {
        printf("1.Push \n2.Pop \n3.Display \n4.Exit\n");
        scanf("%d", &ch);

        switch (ch)
        {
        case 1:
            int n;
            printf("Enter a number:");
            scanf("%d", &n);
            push(n);
            break;
        case 2:
            pop();
            break;
        case 3:
            display();
            break;
        case 4:
            exit(0);
            break;

        default:
            printf("INVALID CHOICE\n");
        }
    }
}
