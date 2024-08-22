#include "Node.h"
#include <iostream>

using namespace std;

Node::Node(int n) {
    data = n;
    next = nullptr;
    prev = nullptr;
}

DoublyLinkedList::DoublyLinkedList() {
    head = nullptr;
}

void DoublyLinkedList::append(int n) {
    Node* newNode = new Node(n);
    if (head == nullptr) {
        head = newNode;
        head->next = head;
        head->prev = head;
    }
    else {
        Node* tail = head->prev;
        tail->next = newNode;
        newNode->prev = tail;
        newNode->next = head;
        head->prev = newNode;
    }
}

void DoublyLinkedList::insert(int n) {
    Node* newNode = new Node(n);
    if (head == nullptr) {
        head = newNode;
        head->next = head;
        head->prev = head;
    }
    else {
        Node* tail = head->prev;
        newNode->next = head;
        head->prev = newNode;
        newNode->prev = tail;
        tail->next = newNode;
        head = newNode;
    }
}

void DoublyLinkedList::print() {
    if (head == nullptr) {
        cout << "The list is empty.\n";
    }
    else {
        Node* current = head;
        do {
            cout << current->data << " ";
            current = current->next;
        } while (current != head);
        cout << endl;
    }
}