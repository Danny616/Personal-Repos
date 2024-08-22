#include <iostream>

using namespace std;

int main()
{
  int num1 = 5, num2;

  cout << "Please enter an integer\n";
  cin >> num2;
  cout << "num1 = " << num1 << " and num2 = " << num2 << endl;

  if (num2 == num1)
    cout << "Hey, that's a coincidence\n";

  return 0;
}
