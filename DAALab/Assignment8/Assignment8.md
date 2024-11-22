## Question
**Write a C program to implement the Miller-Rabin Algorithm for checking if a number is Prime or not.**

## Algorithm
### Algorithm for `is_prime(n, iterations)`

1. Handle base cases for \( n <= 3 \):
   - If \( n <= 1 \), return false.
   - If \( n <= 3 \), return true.

2. If \( n \% 2 == 0 \), return false.

3. Find an odd \( d \) such that \( n-1 = d *= 2^r \):
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
   - Update \( d = d *= 2 \).
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
