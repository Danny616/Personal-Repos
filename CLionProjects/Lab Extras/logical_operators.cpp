#include <iostream>

using namespace std;

int main ()
{
    int year;
    double gpa;

    cout << "What year student are you ?\n";
    cout << "Enter 1 (freshman), 2 (sophmore), 3 (junior), 4 (senior)\n\n";
    cin >> year;

    cout << "Now enter your GPA\n";
    cin >> gpa;
  
    if (gpa >= 2.0 && year == 4)
        cout << "It is time to graduate soon\n";
    else if (gpa < 2.0 || year != 4)
        cout << "You need more schooling\n";

  return 0;
}
