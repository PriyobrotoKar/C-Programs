## Question
**Write a C program to solve the fractional knapsack problem.**

## Algorithm
The weights (Wi) and profit values (Vi) of the items to be added in the knapsack are taken as an input for the fractional knapsack algorithm and the maximum profit that can be achieved as the output.

STEP 1: Use the quickSort function to sort items[] from index 0 to n-1 in descending order of the value-to-weight ratio.

STEP 2: Initialize totalValue = 0.0 to store the total value in the knapsack. Set remaining = W, which is the initial capacity of the knapsack.

STEP 3: Iterate through each item and execute Steps 4-5. 

STEP 4: If the weight of the item is less than or equal to the remaining capacity,
add the entire value of the item to knapsack_value and subtract the item's weight from the remaining capacity.

STEP 5: If the weight of the item is greater than the remaining capacity:
Take a fraction of the item such that it fills the remaining capacity. Stop the loop as the knapsack is now full.

STEP 6: Return the totalValue as the maximum value that can be achieved with the given knapsack capacity W.

## Complexity Analysis
### QuickSort:

The quickSort function is used to sort the items based on the value-to-weight ratio which typically has a time complexity of 𝑂(𝑛log𝑛).

### Partition Function:

The partitioning process in QuickSort takes linear time 𝑂(𝑛) for each call. The partition function is called recursively, leading to the overall 𝑂(𝑛log⁡𝑛) complexity in the average case.

### Fractional Knapsack:
After sorting, the fractional knapsack function iterates over the sorted list of items. This loop runs 𝑛n times, so the complexity of this part is 𝑂(𝑛).

### Overall Time Complexity:
The dominant term is the time required for sorting the items, which is 𝑂(𝑛log𝑛) on average. The fractional knapsack computation is 𝑂(𝑛), but since this is after sorting, the overall time complexity remains 𝑂(𝑛log𝑛)
Thus, the overall time complexity of the code is:𝑂(𝑛log𝑛)

### Space Complexity:
The space complexity is primarily due to the stack used for non-recursive quicksort, which can hold at most 𝑂(log𝑛) elements in the average case and 𝑂(𝑛)in the worst case. The rest of the space used is for storing the items array, which is 𝑂(𝑛). So, the space complexity is:𝑂(𝑛).


## Source Code
```c++
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
```

## Output:
```bash
Max value: 240.000000
```

## Discussion
The fractional knapsack problem is a classic greedy algorithm problem where the objective is to maximize the total value of items packed into a knapsack with a fixed weight capacity, 𝑊. Unlike the 0/1 knapsack problem, where items must either be taken completely or left out, the fractional knapsack allows taking a fraction of an item, making it more efficient to maximize the total value.
The fractional knapsack problem has practical applications in various fields where resource allocation and optimization under constraints are important. Since it models situations where divisible resources are involved, it can be applied to investment portfolios, resource allocation in cloud computing, bandwidth allocation in networks, ad placement in marketing, etc.


## Question
**Implement Quicksort recursively and non-recursively**

## Algorithm
Partition Function
```bash
STEP 1 : Set the pivot as the first element: pivot = arr[low] and two pointers: i = low + 1 and j = high.
STEP 2 : While i is less than or equal to j, repeat steps 4 to 8.
STEP 3 : Increment i while arr[i] <= pivot and i <= high.
STEP 4 : Decrement j while arr[j] > pivot and j >= low.
STEP 5 : If i is less than j, swap arr[i] and arr[j].
STEP 6 : Swap arr[low] and arr[j].
STEP 7 : Return the final position of the pivot, j.
```

Recursive Quicksort
```bash
STEP 1 : If low is less than high, proceed to step 2. Otherwise, return.
STEP 2 : Call the partition function to get the pivot index pi.
STEP 3 : Recursively call recursiveQuickSort on the left subarray, from low to pi - 1.
STEP 4 : Recursively call recursiveQuickSort on the right subarray, from pi + 1 to high.
```



Iterative Quicksort
```bash
STEP 1 : Initialize a stack of size high - low + 1.
STEP 2 : Push low and high onto the stack.
STEP 3 : Pop high and low from the stack.
STEP 4 : Call the partition function to get the pivot index pi.
STEP 5 : If pi - 1 is greater than low, push low onto the stack, then push pi - 1 onto the stack.
STEP 6 : If pi + 1 is less than high, push pi + 1 onto the stack, then push high onto the stack.
STEP 7 : Repeat steps 5 to 9 until the stack is empty.
```

### Recursive Mathematical Equation
The general recurrence relation for QuickSort can be expressed as:
T(n)=T(k)+T(n−k−1)+O(n)
Where:
T(n) is the time complexity for sorting an array of size 
k is the size of one partition, and n−k−1 is the size of the other partition.
O(n) represents the time taken for partitioning the array (scanning the array once to rearrange elements around the pivot).

## Complexity Analysis
### Time complexity
Using the above general recursive relation, we can calculate the average-case time complexity.

//derive the time complexity from the recurrence relation
If the pivot divides the array approximately into two equal halves, 
k=n/2, then the recurrence relation simplifies to:
T(n)=2T(n/2)+O(n)

Using the Master Theorem, for 
T(n)=2T(n/2​)+O(n), the solution is T(n)=O(nlogn)

### Space Complexity
The space complexity is primarily due to the recursive function call stack or the auxilary stack.
In the worst case (when the array is already sorted or sorted in reverse), the partitioning will divide the array into one large part and one empty part, leading to a recursion depth of O(n), where n is the number of elements.
In the average case, the array is divided into two equal parts, and the recursion depth will be O(logn). No additional data structures are used except for the recursion stack or the auxilary stack.


### Source Code
```C
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
```

### Output
```bash
Sorted Array using recursion:1 2 4 5 8 
Sorted Array using iteration:1 2 4 5 8 
```

### Discussion
QuickSort is a highly efficient, divide-and-conquer sorting algorithm that operates by selecting a pivot element and partitioning the array around it. The key to its performance lies in choosing a good pivot, ideally one that splits the array evenly. Its in-place nature makes it memory-efficient, requiring minimal extra space compared to other algorithms like Merge Sort. 

QuickSort is widely used in practice due to its speed and efficiency, especially for large datasets. It is commonly used in system libraries and for sorting arrays in languages like C and Java. It excels in environments where memory efficiency is important, and its average-case time complexity of O(nlogn) makes it ideal for applications such as database sorting, file systems, and search algorithms.

QuickSort is fast with an average-case time complexity of O(nlogn), making it one of the fastest sorting algorithms in practice. Additionally, QuickSort is versatile, working well on a wide range of inputs and with different data types, and can be optimized to handle both small and large datasets efficiently.


## Question
**Implement Merge Sort recursively and non-recursively**

## Algorithm
merge
```bash
STEP 1 : Initialize indices i = low, j = mid + 1, and k = 0.
STEP 2 :Allocate memory for a temporary array temp of size high - low + 1.
STEP 3 : Compare elements from both halves while i <= mid and j <= high.
STEP 4 : If arr[i] < arr[j], store arr[i] in temp[k] and increment both i and k.
STEP 5 : If arr[j] < arr[i], store arr[j] in temp[k] and increment both j and k.
STEP 6 : Copy remaining elements from the left half of the array (arr[low] to arr[mid]) to temp if any.
STEP 7 : Copy remaining elements from the right half of the array (arr[mid + 1] to arr[high]) to temp if any.
STEP 8 : Copy the elements from the temporary array temp back to the original array arr[low] to arr[high].
```

RecursiveMergeSort
```bash
STEP 1 : If low is equal to high, return (base case for recursion).
STEP 2 : Calculate the midpoint: mid = (low + high) / 2.
STEP 3 : Recursively call recursiveMergeSort on the left half of the array (arr[low] to arr[mid]).
STEP 4 : Recursively call recursiveMergeSort on the right half of the array (arr[mid + 1] to arr[high]).
STEP 5 : Call the merge function to combine the two sorted halves (arr[low] to arr[mid] and arr[mid + 1] to arr[high]).
```
IterativeMergeSort
```bash
STEP 1 : Initialize a variable p to 2, which represents the size of the subarrays to be merged.
STEP 2 : While p is less than or equal to size, repeat steps 3 to 6.
STEP 3 : Loop through the array with an index i, ensuring i + p - 1 is within bounds.
STEP 4 : Set low to i, high to i + p - 1, and calculate mid as (low + high) / 2.
STEP 5 : Call the merge function to combine the two sorted subarrays from low to mid and from mid + 1 to high.
STEP 6 : After the outer loop, if (p / 2) < size, merge the remaining elements from index 0 to size - 1.
STEP 7 : Return from the function after all merging is complete.
```

The recursive merge sort algorithm divides the array into two halves and sorts each half recursively. The recurrence relation can be expressed as follows:

### Recurrence Relation:
T(n)=2T(n/2)+O(n)
Where:
T(n) is the time complexity for sorting an array of size n.
2T(n/2) accounts for the two recursive calls made on halves of the array.
O(n) represents the time taken to merge the two halves.

## Complexity Analysis
[ChatGPT solution](https://chatgpt.com/c/66efc5e0-be94-800c-b84c-47381ec8f7a8)

## Source Code
```c
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

void merge(int arr[], int low, int mid, int high)
{
    int i = low, j = mid + 1, k = 0;
    int *temp = malloc(((high - low) + 1) * sizeof(int));

    while (i <= mid && j <= high)
    {
        if (arr[i] < arr[j])
            temp[k++] = arr[i++];
        else if (arr[j] < arr[i])
            temp[k++] = arr[j++];
    }
    while (i <= mid)
    {
        temp[k++] = arr[i++];
    }

    while (j <= high)
    {
        temp[k++] = arr[j++];
    }

    for (int i = low; i <= high; i++)
    {
        arr[i] = temp[i - low];
    }
}

void recursiveMergeSort(int arr[], int low, int high)
{
    if (low == high)
    {
        return;
    }

    int mid = (low + high) / 2;
    recursiveMergeSort(arr, low, mid);
    recursiveMergeSort(arr, mid + 1, high);
    merge(arr, low, mid, high);
}

void iterativeMergeSort(int arr[], int size)
{
    int p, i, low, high, mid;

    for (p = 2; p <= size; p = p * 2)
    {
        for (int i = 0; i + p - 1 < size; i = i + p)
        {
            low = i;
            high = i + p - 1;
            mid = (low + high) / 2;

            merge(arr, low, mid, high);
        }
    }

    if ((p / 2) < size)
    {
        merge(arr, 0, (p / 2) - 1, size - 1);
    }
}

int main()
{
    int arr[] = {3, 4, 1, 5, 2};
    int size = sizeof(arr) / sizeof(int);
    recursiveMergeSort(arr, 0, size - 1);

    printf("Sorted array using recursion:");
    for (int i = 0; i < size; i++)
    {
        printf("%d ", arr[i]);
    }
    printf("\n");
    int arr2[] = {3, 4, 1, 5, 2};
    iterativeMergeSort(arr2, size);

    printf("Sorted array using iteration:");
    for (int i = 0; i < size; i++)
    {
        printf("%d ", arr2[i]);
    }
    printf("\n");
}
```

### Output
```bash
Sorted array using recursion:1 2 3 4 5 
Sorted array using iteration:1 2 3 4 5 
```

## Discussion
MergeSort is a stable, comparison-based algorithm that divides the array into two halves, sorts each recursively, and merges them. It consistently operates in O(nlogn) time, making it efficient across all cases. However, it requires additional O(n) space, which can be a drawback in memory-limited environments.

MergeSort is useful where data stability matters, such as in databases. It works well with large datasets, especially when stored on external devices, due to its efficient handling of sequential access. It’s also favored for predictable performance, making it ideal for concurrent programming and external sorting.

MergeSort guarantees O(nlogn) performance, while QuickSort can degrade to O(n^ 2) in the worst case but is often faster in practice. MergeSort requires extra space, whereas QuickSort is in-place and more memory-efficient. QuickSort is faster for arrays, while MergeSort excels in linked lists and external sorting tasks.
