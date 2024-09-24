
// 2. Write a C++ program to find the greatest of 3 numbers using class and object.

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
