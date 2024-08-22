#include <iostream>
using namespace std;

const int SIZE = 11;

int searchList(char List[], int numElems, char value);

int main(){
    char letter, word[SIZE] = {'p', 'r', 'o', 'g', 'r', 'a', 'm', 'm', 'i', 'n', 'g'};

    cout << "Enter a letter to search for:\n";
    cin >> letter;

    cout << "The letter " << letter << " is in the ";
    cout << searchList(word, SIZE, letter);
    cout << " position of the list\n";

    return 0;
}

int searchList(char List[], int numElems, char value){
    for (int i = 0; i < numElems; ++i)
    {
        if (List[i] == value)
            return i;
    }
    return -1;
}