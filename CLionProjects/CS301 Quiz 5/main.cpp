#include <iostream>
#include "SortedList.h"
#include "ItemType.h"

using namespace std;

//Driver to test program

void printList(SortedList& list) {
    list.ResetList();
    for (int i = 0; i < list.GetLength(); i++) {
        cout << list.GetNextItem() << " ";
    }
    cout << endl;
}

int main() {
    SortedList list;

    // Read data from file
    ifstream inputFile("input.txt");
    if (inputFile.fail()) {
        cerr << "Error: Could not open input file" << endl;
        return 1;
    }
    list.ReadDataFromFile(inputFile);
    inputFile.close();

    // Print original list
    cout << "Original List: ";
    printList(list);

    // Insert items into list
    ItemType item1(25);
    ItemType item2(15);
    ItemType item3(35);
    list.PutItem(item1);
    list.PutItem(item2);
    list.PutItem(item3);

    // Print list after inserting items
    cout << "List after inserting items: ";
    printList(list);

    // Delete item from list
    ItemType item4(10);
    list.DeleteItem(item4);

    // Print list after deleting item
    cout << "List after deleting item: ";
    printList(list);

    // Write data to file
    ofstream outputFile("output.txt");
    list.WriteDataToFile(outputFile);
    outputFile.close();

    return 0;
}