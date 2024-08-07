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
