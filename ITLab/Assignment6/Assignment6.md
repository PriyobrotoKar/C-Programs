## Questions
1. Write a C++ program to find the factorial of a number using class and object.
2. Write a C++ program to find the greatest of 3 numbers using class and object.
3. Write a C++ program to implement copy constructor using class and object

## Source Code (1)
```c++

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


```


## Output
```bash
Enter a number: 5
Factorial of 5 is 120
```

## Source Code (2)

```c++
#include <iostream>
using namespace std;

class Greatest
{
    int a, b, c, greatest;

public:
    Greatest()
    {
        a = 0;
        b = 0;
        c = 0;
    }

    void input()
    {
        cout << "Enter three numbers: ";
        cin >> a >> b >> c;
    }

    void findGreatest()
    {
        greatest = a > b ? (a > c ? a : c) : (b > c ? b : c);
    }

    void displayGreatest()
    {
        cout << "Greatest number is " << greatest << endl;
    }
};

int main()
{
    Greatest greatest;
    greatest.input();
    greatest.findGreatest();
    greatest.displayGreatest();
    return 0;
}


```

## Output
```bash
Enter three numbers: 32 11 90
Greatest number is 90
```

## Source Code (3)
```c++
#include <iostream>
using namespace std;

class Student
{
    int roll;
    string name;
    float marks;

public:
    Student(int r, string n, float m)
    {
        roll = r;
        name = n;
        marks = m;
    }

    Student(Student &s)
    {
        roll = s.roll;
        name = s.name;
        marks = s.marks;
    }

    void display()
    {
        cout << roll << " " << name << " " << marks << endl;
    }
};

int main()
{
    Student s1(112, "Priyobroto Kar", 90.0);
    Student s2(s1);
    s1.display();
    s2.display();
    return 0;
}


```

## Output
```bash
112 Priyobroto Kar 90
112 Priyobroto Kar 90
```
