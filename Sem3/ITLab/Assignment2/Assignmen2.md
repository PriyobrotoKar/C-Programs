# C++ Assignments for 8-08-24

## Question 1
**Write a program to check the time and output a greeting**

## Algorithm

## Source Code

```C
#include <iostream>
using namespace std;

int main()
{
    int time = 19;

    if (time < 10)
        cout << "Good Morning" << endl;
    else if (time < 20)
        cout << "Good Afternoon" << endl;
    else
        cout << "Good Night" << endl;

    return 0;
}

```

## Output
```
Good Afternoon
```

## Question 2
**Write a program to display the name of the day (Monday to Sunday) based on an integer input (1 to 7).**

## Algorithm

## Source Code
```C
#include <iostream>
using namespace std;

int main()
{
    int day = 6;

    switch (day)
    {
    case 1:
        cout << "Monday" << endl;
        break;
    case 2:
        cout << "Tuesday" << endl;
        break;
    case 3:
        cout << "Wednesday" << endl;
        break;
    case 4:
        cout << "Thursday" << endl;
        break;
    case 5:
        cout << "Friday" << endl;
        break;
    case 6:
        cout << "Saturday" << endl;
        break;
    case 7:
        cout << "Sunday" << endl;
        break;
    default:
        cout << "Wrong choice" << endl;
    }
    return 0
}
```
## Output
```
Saturday
```


## Question 3
**Write a program that calculates and displays the factorial of a given integer.**

## Algorithm

## Source Code
```C
#include <iostream>
using namespace std;

int main()
{
    int fact = 1, n;

    cout << "Enter n:";
    cin >> n;

    for (int i = 1; i <= n; i++)
    {
        fact *= i;
    }

    cout << "The factorial of " << n << " is " << fact << endl;
    return 0;
}

```

## Output
```
Enter n:4
The factorial of 4 is 24
```

## Question 4
**Write a program that displays the greatest of three given numbers.**

## Algorithm

## Source Code
```C
#include <iostream>
using namespace std;

int main()
{
    int a, b, c;
    cout << "Enter 3 numbers:";
    cin >> a >> b >> c;

    int greatest = a > b ? a > c ? a : c : b > c ? b
                                                 : c;
    cout << greatest << endl;
    return 0;
}

```

## Output
```
Enter 3 numbers:4 7 1
7
```

## Question 5
**Write a program that displays the first n numbers in the Fibonacci sequence.**

## Algorithm

## Source Code
```C
#include <iostream>
using namespace std;

int main()
{
    int num1 = 0, num2 = 1, num, n;
    cout << "Enter n:";
    cin >> n;

    if (n >= 1)
    {
        cout << num1 << " ";
    }

    if (n >= 2)
    {
        cout << num2 << " ";
    }

    for (int i = 3; i <= n; i++)
    {
        num = num1 + num2;
        num1 = num2;
        num2 = num;
        cout << num << " ";
    }
    return 0;
}
```

## Output
```
Enter n:5
0 1 1 2 3
```
