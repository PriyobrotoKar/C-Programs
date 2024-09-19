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
