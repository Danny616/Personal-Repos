#ifndef ITEMTYPE_H
#define ITEMTYPE_H

#include <fstream>

using namespace std;

class ItemType {
public:
    ItemType();
    ItemType(int value);
    int getValue() const;
    void setValue(int value);
    bool operator==(const ItemType& other) const;
    bool operator<(const ItemType& other) const;
    bool operator>(const ItemType& other) const;
    friend ostream& operator<<(ostream& os, const ItemType& item);
    friend istream& operator>>(istream& is, ItemType& item);
private:
    int value;
};

#endif
