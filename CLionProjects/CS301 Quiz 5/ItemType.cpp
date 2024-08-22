#include "ItemType.h"

using namespace std;

ItemType::ItemType() {
    value = 0;
}

ItemType::ItemType(int value) {
    this->value = value;
}

int ItemType::getValue() const {
    return value;
}

void ItemType::setValue(int value) {
    this->value = value;
}

bool ItemType::operator==(const ItemType& other) const {
    return this->value == other.getValue();
}
bool ItemType::operator<(const ItemType& other) const {
    return this->value < other.getValue();
}
bool ItemType::operator>(const ItemType& other) const {
    return this->value > other.getValue();
}

ostream& operator<<(ostream& os, const ItemType& item) {
    os << item.value;
    return os;
}

istream& operator>>(istream& is, ItemType& item) {
    is >> item.value;
    return is;
}
