## Question
**Write a C program to implement the Heapsort Algorithm to sort elements in an array.**

## Algorithm
```bash
STEP 1: Start by building a max heap from the input array.
STEP 2: Set i to n / 2 - 1 (where n is the size of the array).
STEP 3: Perform the heapify operation on the array for each index from i down to 0.
STEP 4: After building the heap, start extracting the largest element from the heap.
STEP 5: Set i to n - 1 (last element of the array).
STEP 6: Swap the element at index 0 (root of the heap) with the element at index i.
STEP 7: Call heapify on the reduced heap (from index 0 to i-1).
STEP 8: Decrease i by 1 and repeat steps 6 and 7 until the entire array is sorted.
STEP 9: The array is now sorted in ascending order.bash
```
### Recurrence Mathematical Relation
Building the heap: This takes O(n) time.

Heapifying the array and extracting elements: For each of the n elements, heapify is called, and heapify takes O(log n) time since it operates on a tree of height log n.

Thus, the recurrence relation for Heap Sort can be written as:

```
T(n)=T(n−1)+O(logn)
```

Where:
T(n - 1) is the time to heapify the remaining n-1 elements after swapping the root with the last element.
O(log n) is the time taken to reheapify (or restore the heap property) after each extraction.
The overall time complexity for Heap Sort is O(n log n), as this process is repeated n times for log n heapify operations.

## Complexity Analysis
### Time to build the heap is O(n):
Although each individual heapify operation can take up to O(log n) time, the total time for building the heap is O(n), because the number of nodes at each level of the heap decreases exponentially, which balances out the logarithmic cost of each heapify call.

### Time to extract elements and reheapify:
There are n elements to extract, and for each extraction, the heapify operation takes O(log n) time.
Hence, the time complexity for this phase is O(n log n).

Thus, the total time complexity for Heap Sort is:
O(n)+O(nlogn)=O(nlogn)


### Space Complexity
Heap Sort is an in-place sorting algorithm, meaning it does not require any extra space apart from the input array and a constant amount of auxiliary space for temporary variables during the swap operations.

Thus, the space complexity is O(1).


## Source Code
```C
#include <stdio.h>

// Function to swap two elements
void swap(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

// Recursive function to heapify a subtree rooted at index i
void heapify(int arr[], int n, int i)
{
    int largest = i;       // Initialize largest as root
    int left = 2 * i + 1;  // Left child
    int right = 2 * i + 2; // Right child

    // If left child is larger than root
    if (left < n && arr[left] > arr[largest])
        largest = left;

    // If right child is larger than the largest so far
    if (right < n && arr[right] > arr[largest])
        largest = right;

    // If largest is not root
    if (largest != i)
    {
        swap(&arr[i], &arr[largest]);

        // Recursively heapify the affected subtree
        heapify(arr, n, largest);
    }
}

// Recursive function to implement heap sort
void heapSort(int arr[], int n)
{
    // Build heap (rearrange array)
    for (int i = n / 2 - 1; i >= 0; i--)
        heapify(arr, n, i);

    // Extract elements from heap one by one
    for (int i = n - 1; i > 0; i--)
    {
        // Move current root to end
        swap(&arr[0], &arr[i]);

        // Call heapify on the reduced heap
        heapify(arr, i, 0);
    }
}

// Function to print an array
void printArray(int arr[], int n)
{
    for (int i = 0; i < n; ++i)
        printf("%d ", arr[i]);
    printf("\n");
}

// Main function to test the heap sort
int main()
{
    int arr[] = {12, 11, 13, 5, 6, 7};
    int n = sizeof(arr) / sizeof(arr[0]);

    printf("Original array: \n");
    printArray(arr, n);

    heapSort(arr, n);

    printf("Sorted array: \n");
    printArray(arr, n);

    return 0;
}

```

## Output
```bash
Original array: 
12 11 13 5 6 7 
Sorted array: 
5 6 7 11 12 13 
```


## Discussion


## Question
**Write a C program to solve the N-Queens problem which prints a binary matrix that has 'Q's for the cells where Queens are placed.**

## Algorithm(solveNQueens)
```bash
STEP 1: Check if all queens are placed (row >= n), return true if so.
STEP 2: Loop through each column (col) in the current row.
STEP 3: For each column, check if placing a queen at position (row, col) is safe using isSafe.
STEP 4: If placing a queen is safe, set the queen's position at queens[row].row = row and queens[row].col = col.
STEP 5: Recursively call solveNQueens to place queens in the next row (row + 1).
STEP 6: If the recursive call returns true, propagate the success by returning true.
STEP 7: If placing the queen in the current column doesn't lead to a solution, backtrack by resetting queens[row].row = -1 and queens[row].col = -1.
STEP 8: If no columns in the current row lead to a solution, return false.
```

## Algorithm(isSafe)
```bash
STEP 1: Loop through all previously placed queens (i = 0 to i < row).
STEP 2: For each queen, check for column conflict (queens[i].col == col), major diagonal conflict (queens[i].row + queens[i].col == row + col), or minor diagonal conflict (queens[i].row - queens[i].col == row - col).
STEP 3: If any conflict is found, return false.
STEP 4: If no conflicts are found, return true.
```

### Recurrence Mathematical Equation
For each row, we attempt to place a queen in one of the n columns. Once a queen is placed in a column, we recursively solve the problem for the remaining n−1 rows. This results in trying n possible column positions, each leading to T(n−1).

For each attempt, we also check if placing a queen in a specific column is valid, which takes linear time 
O(n) because we need to verify the queen’s position against all previously placed queens.

Thus, the overall recurrence is:
```
T(n)=n⋅T(n−1)+O(n)
```
This reflects the recursive nature of trying to place queens row by row and checking for conflicts each time.

## Complexity Analysis

