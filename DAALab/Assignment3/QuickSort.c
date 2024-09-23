#include <stdio.h>

void swap(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

int partition(int arr[], int low, int high)
{
    int pivot = arr[low];
    int i = low + 1;
    int j = high;

    while (i <= j)
    {
        while (i <= high && arr[i] <= pivot)
        {
            i++;
        }

        while (j >= low && arr[j] > pivot)
        {
            j--;
        }

        if (i < j)
        {
            swap(&arr[i], &arr[j]);
        }
    }
    swap(&arr[low], &arr[j]);
    return j;
}

void recursiveQuickSort(int arr[], int low, int high)
{
    if (low < high)
    {
        int pi = partition(arr, low, high);

        recursiveQuickSort(arr, low, pi - 1);
        recursiveQuickSort(arr, pi + 1, high);
    }
}

void iterativeQuickSort(int arr[], int low, int high)
{
    int stack[high - low + 1];
    int top = -1;

    stack[++top] = low;
    stack[++top] = high;

    while (top >= 0)
    {
        high = stack[top--];
        low = stack[top--];

        int pi = partition(arr, low, high);

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

int main()
{
    int arr[] = {4, 5, 1, 2, 8};

    recursiveQuickSort(arr, 0, 4);

    printf("Sorted Array using recursion:");
    for (int i = 0; i < 5; i++)
    {
        printf("%d ", arr[i]);
    }
    printf("\n");

    int arr2[] = {4, 5, 1, 2, 8};

    iterativeQuickSort(arr2, 0, 4);

    printf("Sorted Array using iteration:");
    for (int i = 0; i < 5; i++)
    {
        printf("%d ", arr2[i]);
    }
    printf("\n");
}
