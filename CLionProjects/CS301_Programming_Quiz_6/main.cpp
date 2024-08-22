#include "Node.h"
#include <iostream>

using namespace std;

int main() {
    DoublyLinkedList list;

    cout << "How many nodes would you like to add to the list?:\n";
    int numNodes;
    cin >> numNodes;

    for (int i = 0; i < numNodes; i++) {
        int data;
        cout << "Enter data for node " << i + 1 << ":\n";
        cin >> data;
        list.append(data);
    }

    cout << "Do you want to insert a node at the head of the list? (y/n):\n";
    char choice;
    cin >> choice;

    if (choice == 'y' || choice == 'Y') {
        int data;
        cout << "Enter data for the new node:\n";
        cin >> data;
        list.insert(data);
        cout << "The list is:\n";
        list.print();
    } else {
        cout << "The list is:\n";
        list.print();
    }

    return 0;
}