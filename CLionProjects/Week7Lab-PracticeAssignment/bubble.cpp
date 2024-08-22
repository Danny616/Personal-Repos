#include <iostream>
using namespace std;

const int SIZE = 5;

void displayArray(int array[], int elems);
void bubbleSortArray(int array[], int elems);

int main()
{
    int values[SIZE] = { 9, 2, 0, 11, 5 };

    cout << "The values before the bubble sort is performed are:\n";
    displayArray(values, SIZE);

    bubbleSortArray(values, SIZE);

    cout << "The values after the bubble sort is performed are:\n";
    displayArray(values, SIZE);

    return 0;
}

void displayArray(int array[], int elems)
{
    for (int i = 0; i < elems; ++i) {
        cout << array[i] << "\n";
    }
}
void bubbleSortArray(int array[], int elems)
{
    for (int i = 0; i < elems - 1; ++i)
    {
        for (int j = 0; j < elems - i - 1; ++j)
        {
            if (array[j] > array[j + 1])
                swap(array[j], array[j+1]);
        }
    }
}