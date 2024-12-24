// 3. Write a C++ program to implement copy constructor using class and object

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
