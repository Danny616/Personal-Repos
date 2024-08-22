#ifndef CS301_PROGRAMMING_QUIZ_6_NODE_H
#define CS301_PROGRAMMING_QUIZ_6_NODE_H

class Node {
public:
    int data;
    Node* next;
    Node* prev;
    Node(int n);
};

class DoublyLinkedList {
private:
    Node* head;
public:
    DoublyLinkedList();
    void append(int n);
    void insert(int n);
    void print();
};

#endif