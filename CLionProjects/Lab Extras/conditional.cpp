#include <iostream>

using namespace std;

int main()
{
  double avg = 0;

  cout << "Input your average\n";
  cin >> avg;

  if (avg >= 60)
    cout << "You Pass\n";
  else
    cout << "You Fail\n";

  return 0;
}
