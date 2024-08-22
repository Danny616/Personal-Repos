#include <iostream>
using namespace std;

const int SIZE = 16;

int binarySearch(int array[], int numElems, int value);

int main()
{
    int num, array[] = { 34, 20, 19, 18, 17, 15, 16, 13, 12, 11, 9, 5, 4,2, 1, 0 };

    cout << "Enter an integer to search for:\n";
    cin >> num;

    cout << "The value " << num << " is in position number ";
    cout << binarySearch(array, SIZE, num) << " of the list\n";

    return 0;
}

int binarySearch(int array[], int numElems, int value)
{
    for (int i = 0; i < numElems; ++i)
    {
        if (array[i] == value)
            return i;
    }
    return -1;
}
