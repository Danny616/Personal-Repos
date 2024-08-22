#include <iostream>
using namespace std;

class ListNode {
private:
    int data;
    ListNode* next;
public:
    ListNode(){
        data = 0;
        next = nullptr;
    }
    ListNode(int num){
        data = num;
        next = nullptr;
    }
    void insertNode(int);
    void printList() const;
};

ListNode* head = nullptr;

void ListNode::insertNode(int num)
{
    ListNode* newNode = new ListNode(num);

    if (head == nullptr)
        head = newNode;
    else{
        ListNode* temp = head;
        while(temp -> next != nullptr)
            temp = temp ->next;
        temp -> next = newNode;
    }
}

void ListNode::printList() const
{
    ListNode* temp = head;
    while (temp != nullptr){
        cout << temp -> data << " ";
        temp = temp -> next;
    }
}

int main()
{
    ListNode list;

    for (int i = 1; i < 5; ++i) {
        list.insertNode(i);
    }

    cout << "Elements of the list are: ";
    list.printList();
    cout << endl;

    return 0;
}