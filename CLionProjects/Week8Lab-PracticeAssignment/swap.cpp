#include <iostream>
using namespace std;

void swapnum(int* x, int* y)
{
    int temp = *x;
    *x = *y;
    *y = temp;
}
int main()
{
    int a, b;

    cout << "Enter the first number :";
    cin >> a;
    cout << "Enter the second number :";
    cin >> b;

    swapnum (&a,&b);

    cout << a << " " << b;

    return 0;
}