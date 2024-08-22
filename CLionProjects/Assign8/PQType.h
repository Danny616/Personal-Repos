#ifndef PQTYPE_H
#define PQTYPE_H

#include "Heap.h"

class PQType {
private:
    Heap heap;

public:
    void insert(int key, int priority) {
        heap.insert(key, priority);
    }

    int extractMax() {
        return heap.extractMax();
    }

    bool isEmpty() {
        return heap.isEmpty();
    }
};

#endif