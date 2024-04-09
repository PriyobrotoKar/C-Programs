#include <stdio.h>

int binarySearch(int arr[], int size, int target)
{
    int s = 0;
    int e = size - 1;
    int mid;
    while (s <= e)
    {
        mid = s + (e - s) / 2;

        if (arr[mid] == target)
        {
            return mid;
        }
        else if (arr[mid] > target)
        {
            e = mid - 1;
        }
        else
        {
            s = mid + 1;
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

    int ind = binarySearch(arr, size, target);

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
