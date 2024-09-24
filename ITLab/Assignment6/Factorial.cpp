// Write a C++ program to find the factorial of a number using class and object.

#include <iostream>
using namespace std;

class Factorial
{
    int n;
    int fact;

public:
    Factorial()
    {
        n = 0;
        fact = 1;
    }

    void input()
    {
        cout << "Enter a number: ";
        cin >> n;
    }

    void calculateFactorial()
    {
        for (int i = 1; i <= n; i++)
        {
            fact *= i;
        }
    }

    void displayFactorial()
    {
        cout << "Factorial of " << n << " is " << fact << endl;
    }
};

int main()
{
    Factorial fact;
    fact.input();
    fact.calculateFactorial();
    fact.displayFactorial();
    return 0;
}
