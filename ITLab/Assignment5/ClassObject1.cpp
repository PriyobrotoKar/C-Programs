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
