#include <stdio.h>

int linearSerach(int arr[], int size, int key)
{
    for (int i = 0; i < size; i++)
    {
        if (arr[i] == key)
        {
            return i;
        }
    }
    return -1;
}

int main()
{
    int target, size;

    printf("Enter the size of array:");
    scanf("%d", &size);

    int arr[size];
    printf("Enter the elements:");
    for (int i = 0; i < size; i++)
    {
        scanf("%d", &arr[i]);
    }

    printf("Enter the element to find:");
    scanf("%d", &target);

    int ind = linearSerach(arr, size, target);

    if (ind != -1)
    {
        printf("%d is found at position %d", target, ind + 1);
    }
    else
    {
        printf("%d is not found", target);
    }

    return 0;
}
