## Assignment 5:
1. Write a sample program 1 in C++ to create a class - myClass and object- myObj.
2. ⁠Write a sample program 2 in C++ to create a class - Car and object- carobj1 and carobj2.
3. ⁠Write a sample program of constructor in C++. 

### Software: CodeBlocks v17.2.0

### Source Code(1):
```C++
#include <iostream>
using namespace std;

class MyClass
{
public:
    int myNum;
    string myString;
};

int main()
{
    MyClass myObj;
    myObj.myNum = 112;
    myObj.myString = "Priyobroto";
    cout << myObj.myNum << "\n";
    cout << myObj.myString << "\n";
    return 0;
}
```

### Output:
```bash
112
Priyobroto
```

### Source Code(2):

```C++
#include <iostream>
using namespace std;

class Car
{
public:
    string brand;
    string model;
    int year;
};

int main()
{
    Car carObj1;
    carObj1.brand = "BMW";
    carObj1.model = "X5";
    carObj1.year = 1999;

    Car carObj2;
    carObj2.brand = "Porshe";
    carObj2.model = "X15";
    carObj2.year = 2000;

    cout << "Car brand 1 :" << carObj1.brand << "\n";
    cout << "Car model 1 :" << carObj1.model << "\n";
    cout << "Car year 1 :" << carObj1.year << endl;

    cout << "Car brand 2 :" << carObj2.brand << "\n";
    cout << "Car model 2 :" << carObj2.model << "\n";
    cout << "Car year 2 :" << carObj2.year << endl;

    return 0;
}
```

### Output:
```bash
Car brand 1 :BMW
Car model 1 :X5
Car year 1 :1999
Car brand 2 :Porshe
Car model 2 :X15
Car year 2 :2000
```

## Source Code(3):
```C++
#include <iostream>
using namespace std;

class Car
{
public:
    string brand;
    string model;
    int year;

    Car(string x, string y, int z)
    {
        brand = x;
        model = y;
        year = z;
    }
};

int main()
{
    Car carObj1("BMW", "X5", 1999);
    Car carObj2("Porshe", "X15", 2000);

    cout << carObj1.brand << " " << carObj1.model << " " << carObj1.year << endl;
    cout << carObj2.brand << " " << carObj2.model << " " << carObj2.year << endl;

    return 0;
}
```

### Ouput:
```bash
BMW X5 1999
Porshe X15 2000
```
