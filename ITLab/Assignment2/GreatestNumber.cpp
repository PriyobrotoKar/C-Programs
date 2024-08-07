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
