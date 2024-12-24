## Question

**Write a C program to implement the Miller-Rabin Algorithm for checking if a number is Prime or not.**

## Algorithm

### Algorithm for `is_prime(n, iterations)`

1. Handle base cases for \( n <= 3 \):

   - If \( n <= 1 \), return false.
   - If \( n <= 3 \), return true.

2. If \( n \% 2 == 0 \), return false.

3. Find an odd \( d \) such that \( n-1 = d \*= 2^r \):

   - Set \( d = n-1 \).
   - While \( d \% 2 == 0 \), divide \( d \) by 2.

4. Repeat \( iterations \) times:

   - Pick a random \( a \) in \([2, n-2]\).
   - If `miller_test(n, d, a)` returns false, return false.

5. Return true.

---

### Algorithm for `miller_test(n, d, a)`

1. Compute \( x = (a^d) \% n \).

2. If \( x == 1 \) or \( x == n-1 \), return true.

3. While \( d != n-1 \):

   - Compute \( x = (x^2) \% n \).
   - Update \( d = d \*= 2 \).
   - If \( x == 1 \), return false.
   - If \( x == n-1 \), return true.

4. Return false.

## Complexity Analysis

## Time Complexity

1. Preprocessing in is_prime:

   - Handling base cases takes O(1).

   - Finding d (halving n−1 repeatedly) takes O(logn).

2. Single miller_test Execution:

   - Modular exponentiation :

     Computing x=a d mod n using modular exponentiation involves:

     - Exponentiation: d can be at most n−1, so the number of bits in d is O(logn).
     - Each multiplication operation is O(log 2 n) for numbers up to n (using basic arithmetic).
     - Modular exponentiation has a time complexity of O(logn⋅log 2 n).

   - While-loop iterates O(logn) times, with each iteration involving modular arithmetic of O(log 2 n).

   - Total time: O(logn⋅log 2 n).

3. Total Complexity for k Iterations:

   - O(k⋅logn⋅log 2 n)=O(k⋅log 3 n).

## Source Code

```C
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

// Function to perform modular exponentiation
// (base^exp) % mod
int modular_exponentiation(int base, int exp, int mod)
{
    int result = 1;
    base = base % mod;

    while (exp > 0)
    {
        if (exp % 2 == 1)
        {
            result = (result * base) % mod;
        }
        exp = exp >> 1;
        base = (base * base) % mod;
    }
    return result;
}

// Function to perform Miller-Rabin test for a given base 'a'
int miller_test(int n, int d, int a)
{
    int x = modular_exponentiation(a, d, n);

    if (x == 1 || x == n - 1)
    {
        return 1; // probably prime
    }

    while (d != n - 1)
    {
        x = (x * x) % n;
        d *= 2;

        if (x == 1)
        {
            return 0; // composite
        }
        if (x == n - 1)
        {
            return 1; // probably prime
        }
    }
    return 0; // composite
}

// Function to check if n is a prime using Rabin-Miller test
int is_prime(int n, int iterations)
{
    if (n <= 1)
        return 0; // 0 and 1 are not prime
    if (n <= 3)
        return 1; // 2 and 3 are prime
    if (n % 2 == 0)
        return 0; // even numbers greater than 2 are not prime

    // Find d such that n-1 = d * 2^r, where d is odd
    int d = n - 1;
    while (d % 2 == 0)
    {
        d /= 2;
    }

    // Perform the Miller-Rabin test `iterations` times
    for (int i = 0; i < iterations; i++)
    {
        int a = 2 + rand() % (n - 4); // Random base in range [2, n-2]
        if (!miller_test(n, d, a))
        {
            return 0; // composite
        }
    }
    return 1; // probably prime
}

int main()
{
    int n;
    int iterations = 5; // Higher value increases accuracy

    printf("Enter a number to check if it's prime: ");
    scanf("%d", &n);

    if (is_prime(n, iterations))
    {
        printf("%d is a prime number.\n", n);
    }
    else
    {
        printf("%d is not a prime number.\n", n);
    }

    return 0;
}


```

## Output

```
Enter a number to check if it's prime: 13
13 is a prime number.
```

## Discussion

## Question

**Write a C program to implement the KnuthMorris algorithm for string matching.**

## Algorithm

### computeLPSArray

1.  Initialize length = 0 (tracks the length of the previous longest prefix suffix).
2.  Set lps[0] = 0 (base case: no prefix for a single character).
3.  Start a loop with i = 1 while i < M:

    3.1. If pattern[i] == pattern[length]:

        3.1.1. Increment length by 1.
        3.1.2. Set lps[i] = length.
        3.1.3. Increment i by 1.

    3.2: Else (mismatch case):

        3.2.1. If length != 0,Update length = lps[length - 1] (use previous LPS value).
        3.2.2. Else,Set lps[i] = 0 and Increment i by 1.

4.  Exit the loop when i == M. The lps array is complete.

### KMP

1.  Compute N = strlen(text) and M = strlen(pattern).
2.  Initialize:
    2.1. i = 0 (index for the text).
    2.2. j = 0 (index for the pattern).
3.  Start a loop while i < N:

    3.1. If pattern[j] == text[i], Increment both i and j.
    3.2: If j == M (a match is found):

        3.2.1. Print the starting index of the match as i - j.
        3.2.2. Update j = lps[j - 1] (reset j using LPS).

    3.3: If i < N and pattern[j] != text[i]:

        3.3.1 If j != 0, Update j = lps[j - 1] (use previous LPS value).
        3.3.2. Else, Increment i by 1.

4.  Exit the loop when i == N.

## Complexity Analysis

### Time Complexity

The overall complexity of Knuth Morris Algorithm is O(N+M), where N is the length of the text and M is the length of the pattern.

This is because The two steps (LPS computation and text matching) are performed sequentially.

**Explaination**:

Preprocessing the Pattern (LPS Array Calculation):

- The computeLPSArray function processes each character of the pattern exactly once.
- For each character, there are two possible actions:
  - Advance to the next character (i++).
  - Backtrack using the lps array (length = lps[length - 1]).
- Since each backtrack reduces length and no character is processed more than twice, the overall complexity of this step is O(M), where M is the length of the pattern.

Pattern Matching in the Text:

- In the KMP function, the algorithm processes each character of the text exactly once.
- Similar to the LPS calculation, when a mismatch occurs, the algorithm uses the lps array to skip comparisons and avoid unnecessary character checks.
- This ensures each character of the text is checked at most twice (once during initial comparison and potentially once after backtracking using the lps array).
- Therefore, the complexity of this step is O(N), where N is the length of the text.

### Space Complexity

The overall Space Complexity is O(M).

**Explaination**

1. LPS Array Storage: The algorithm requires an array lps of size M to store the LPS values.
2. Other Variables: A few integer variables are used (i, j, length), which require O(1) space.

## Source Code

```c
#include <stdio.h>
#include <string.h>

void computeLPSArray(const char *pattern, int M, int *lps)
{
    int length = 0;
    int i = 1;

    lps[0] = 0;

    while (i < M)
    {
        if (pattern[i] == pattern[length])
        {
            length++;
            lps[i] = length;
            i++;
        }
        else
        {
            if (length != 0)
            {
                length = lps[length - 1];
            }
            else
            {
                lps[i] = 0;
                i++;
            }
        }
    }
}

void KMP(const char *text, const char *pattern)
{
    int N = strlen(text);
    int M = strlen(pattern);

    int lps[M];
    computeLPSArray(pattern, M, lps);

    int i = 0;
    int j = 0;

    while (i < N)
    {
        if (pattern[j] == text[i])
        {
            i++;
            j++;
        }

        if (j == M)
        {
            printf("Pattern found at index %d\n", i - j);
            j = lps[j - 1];
        }
        else if (i < N && pattern[j] != text[i])
        {
            if (j != 0)
            {
                j = lps[j - 1];
            }
            else
            {
                i++;
            }
        }
    }
}

int main()
{
    const char *text = "ABABDABACDABABCABAB";
    const char *pattern = "ABABCABAB";

    printf("Text: %s\n", text);
    printf("Pattern: %s\n", pattern);

    KMP(text, pattern);

    return 0;
}

```

## Output

```
Text: ABABDABACDABABCABAB
Pattern: ABABCABAB
Pattern found at index 10
```

## Discussion

## Question

**Write a C program to implement Hamiltonian Cycle using Backtracking to determine if a Hamiltonian Cycle is present or not and if it does, then print the cycle.**

## Algorithm

### hamiltonianCycle

1. Initialize an array path[] of size V to store the Hamiltonian path. Set all elements in path[] to -1 to indicate they are not visited yet.

2. Set path[0] = 0 (starting vertex).

3. Call the utility function hamiltonianCycleUtil(graph, path, pos = 1) to recursively build the cycle, starting from the next position.

4. If hamiltonianCycleUtil returns true, a Hamiltonian Cycle exists. Print the cycle stored in path[] by calling printSolution(path).

5. If hamiltonianCycleUtil returns false, print "No Hamiltonian Cycle exists."

### hamiltonianCycleUtil

1.  Check if all vertices are included in the path:

    - If `pos == V`, check if the last vertex in `path[]` is connected to the starting vertex:
      - If `graph[path[pos - 1]][path[0]] == 1`, return `true` (Hamiltonian Cycle found).
      - Otherwise, return `false` (no cycle exists).

2.  For each vertex `v` (from 1 to `V-1`):

    2.1. Check if vertex `v` can be added to the cycle:

         - Call `isSafe(v, graph, path, pos)` to verify:
           - Vertex `v` is adjacent to the last vertex in the current path.
           - Vertex `v` has not been visited yet.

    2.2. If `isSafe` returns `true`:

         - Add `v` to the current path by setting `path[pos] = v`.

    2.3. Recursively call `hamiltonianCycleUtil(graph, path, pos + 1)`:

         - If this call returns `true`, propagate `true` upward (solution found).

    2.4. If the recursive call returns `false`:

         - Backtrack by removing `v` from the path (`path[pos] = -1`).

3.  If no vertex can be added to the cycle, return `false`.

## Mathematical Recurrance Relation

## Complexity Analysis

## Source Code

```c
#include <stdio.h>
#include <stdbool.h>

#define V 5

void printSolution(int path[])
{
    printf("Hamiltonian Cycle: ");
    for (int i = 0; i < V; i++)
    {
        printf("%d -> ", path[i]);
    }
    printf("%d\n", path[0]);
}

bool isSafe(int v, int graph[V][V], int path[], int pos)
{
    if (graph[path[pos - 1]][v] == 0)
    {
        return false;
    }

    for (int i = 0; i < pos; i++)
    {
        if (path[i] == v)
        {
            return false;
        }
    }

    return true;
}

bool hamiltonianCycleUtil(int graph[V][V], int path[], int pos)
{
    if (pos == V)
    {
        if (graph[path[pos - 1]][path[0]] == 1)
        {
            return true;
        }
        else
        {
            return false;
        }
    }

    for (int v = 1; v < V; v++)
    {
        if (isSafe(v, graph, path, pos))
        {
            path[pos] = v;

            if (hamiltonianCycleUtil(graph, path, pos + 1))
            {
                return true;
            }

            path[pos] = -1;
        }
    }

    return false;
}

bool hamiltonianCycle(int graph[V][V])
{
    int path[V];

    for (int i = 0; i < V; i++)
    {
        path[i] = -1;
    }

    path[0] = 0;

    if (hamiltonianCycleUtil(graph, path, 1) == false)
    {
        printf("No Hamiltonian Cycle exists.\n");
        return false;
    }

    printSolution(path);
    return true;
}

int main()
{
    int graph[V][V] = {
        {0, 1, 0, 1, 0},
        {1, 0, 1, 1, 1},
        {0, 1, 0, 0, 1},
        {1, 1, 0, 0, 1},
        {0, 1, 1, 1, 0}};

    hamiltonianCycle(graph);
    return 0;
}

```

## Output

```
Hamiltonian Cycle: 0 -> 1 -> 2 -> 4 -> 3 -> 0
```

## Discussion
