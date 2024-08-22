#ifndef SORTEDLIST_H
#define SORTEDLIST_H

#include "ItemType.h"

class SortedList {
public:
    SortedList();
    SortedList(int maxItems);
    ~SortedList();
    bool IsFull() const;
    int GetLength() const;
    void MakeEmpty();
    ItemType GetItem(ItemType item, bool& found) const;
    void PutItem(ItemType item);
    void DeleteItem(ItemType item);
    void ResetList();
    ItemType GetNextItem();
    void ReadDataFromFile(istream& input);
    void WriteDataToFile(ostream& output);
private:
    int length;
    int maxItems;
    ItemType* info;
    int currentPos;
    ItemType* listData;
};

#endif
