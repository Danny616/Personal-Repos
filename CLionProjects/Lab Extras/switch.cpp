#include <iostream>

using namespace std;

int main ()
{
    char grade;

    cout << "What grade did you earn in Programming I ?\n";
    cin >> grade;
    
    switch (grade) {
        case 'A':
            cout << "an A - excellent work !\n";
            break;
        case 'B':
            cout << "you got a B - good job\n";
            break;
        case 'C':
            cout << "earning a C is satisfactory\n";
            break;
        case 'D':
            cout << "while D is passing, there is a problem\n";
            break;
        case 'F':
            cout << "you failed - better luck next time\n";
            break;
        default:
            cout << "You did not enter an A, B, C, D, or F\n";
            break;
    }
    
    return 0;
}
