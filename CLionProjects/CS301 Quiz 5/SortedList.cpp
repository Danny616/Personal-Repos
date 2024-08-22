#include "SortedList.h"

#include <iostream>

SortedList::SortedList() {
    maxItems = 100;
    length = 0;
    info = new ItemType[maxItems];
    currentPos = -1;
    listData = new ItemType[maxItems];
}

SortedList::SortedList(int maxItems) {
    this->maxItems = maxItems;
    length = 0;
    info = new ItemType[maxItems];
    currentPos = -1;
    listData = new ItemType[maxItems];
}

SortedList::~SortedList() {
    delete[] info;
}

bool SortedList::IsFull() const {
    return (length == maxItems);
}

int SortedList::GetLength() const {
    return length;
}

void SortedList::MakeEmpty() {
    length = 0;
}

ItemType SortedList::GetItem(ItemType item, bool& found) const {
    ItemType tempItem = item;
    int mid;
    int first = 0;
    int last = length - 1;
    found = false;
    while (first <= last && !found) {
        mid = (first + last) / 2;
        if (item < info[mid]) {
            last = mid - 1;
        } else if (item > info[mid]) {
            first = mid + 1;
        } else {
            found = true;
            tempItem = info[mid];
        }
    }
    return tempItem;
}

void SortedList::PutItem(ItemType item) {
    int location = 0;
    while (location < length && item > info[location]) {
        location++;
    }
    for (int i = length; i > location; i--) {
        info[i] = info[i - 1];
    }
    info[location] = item;
    length++;
}

void SortedList::DeleteItem(ItemType item) {
    int location = 0;
    while (location < length && item > info[location]) {
        location++;
    }
    for (int i = location; i < length - 1; i++) {
        info[i] = info[i + 1];
    }
    length--;
}

void SortedList::ResetList() {
    currentPos = -1;
}

ItemType SortedList::GetNextItem() {
    currentPos++;
    return listData[currentPos];
}

void SortedList::ReadDataFromFile(istream& input) {
    ItemType item;
    while (input >> item) {
        PutItem(item);
    }
}

void SortedList::WriteDataToFile(ostream& output) {
    ResetList();
    ItemType item;
    for (int i = 0; i < GetLength(); i++) {
        item = GetNextItem();
        output << item << endl;
    }
}