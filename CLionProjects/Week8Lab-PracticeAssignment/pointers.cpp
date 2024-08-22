#include <iostream>
using namespace std;

int doSomething(int* x, int* y)
{
    int temp = *x;
    *x = *y * 10;
    *y = temp * 10;
    return *x + *y;
}

int main()
{
    int a = 5, b = 10;

    cout << "a=" << a << endl;
    cout << "b=" << b << endl;
    cout << "after using function value of a + b = " << doSomething(&a, &b) << endl;
    cout << "a=" << a << endl;
    cout << "b=" << b << endl;

    return 0;
}
