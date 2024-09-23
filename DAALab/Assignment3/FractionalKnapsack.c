#include <stdio.h>

struct Item
{
    int value;
    int weight;
};

void swap(struct Item *a, struct Item *b)
{
    struct Item temp = *a;
    *a = *b;
    *b = temp;
}

int getPartionIndex(struct Item items[], int low, int high)
{
    double pivotVal = (double)items[high].value / items[high].weight;
    int i = low - 1;

    for (int j = low; j < high; j++)
    {
        double currentVal = (double)items[j].value / items[j].weight;

        if (currentVal > pivotVal)
        {
            i++;
            swap(&items[i], &items[j]);
        }
    }

    swap(&items[i + 1], &items[high]);
    return (i + 1);
}

void quickSort(struct Item items[], int low, int high)
{
    int stack[high - low + 1];
    int top = -1;

    stack[++top] = low;
    stack[++top] = high;

    while (top >= 0)
    {
        high = stack[top--];
        low = stack[top--];

        int pi = getPartionIndex(items, low, high);

        if (pi - 1 > low)
        {
            stack[++top] = low;
            stack[++top] = pi - 1;
        }

        if (pi + 1 < high)
        {
            stack[++top] = pi + 1;
            stack[++top] = high;
        }
    }
}

double fractionalKnapsack(struct Item items[], int W, int n)
{
    quickSort(items, 0, n - 1);

    double totalValue = 0.0;
    int remaining = W;

    for (int i = 0; i < n; i++)
    {
        if (items[i].weight <= remaining)
        {
            totalValue += items[i].value;
            remaining -= items[i].weight;
        }
        else
        {
            double fraction = (double)remaining / items[i].weight;
            totalValue += items[i].value * fraction;
            break;
        }
    }

    return totalValue;
}

int main()
{
    struct Item items[] = {{60, 10}, {100, 20}, {120, 30}};
    int W = 50, n = sizeof(items) / sizeof(struct Item);
    double maxValue = fractionalKnapsack(items, W, n);
    printf("Max value: %f\n", maxValue);
}
