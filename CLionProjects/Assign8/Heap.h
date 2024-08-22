#ifndef HEAP_H
#define HEAP_H

#include <vector>

using namespace std;

struct HeapNode {
    int key;
    int priority;
};

class Heap {
private:
    vector<HeapNode> data;
    int size;

public:
    Heap() {
        size = 0;
    }

    void insert(int key, int priority) {
        HeapNode newNode = {key, priority};
        data.push_back(newNode);
        up_heap(size);
        size++;
    }

    int extractMax() {
        int maxKey = data[0].key;
        swap(data[0], data[size - 1]);
        size--;
        down_heap(0);
        return maxKey;
    }

    void up_heap(int index) {
        while (index > 0 && data[index].priority > data[(index - 1) / 2].priority) {
            swap(data[index], data[(index - 1) / 2]);
            index = (index - 1) / 2;
        }
    }

    void down_heap(int index) {
        int leftChild = 2 * index + 1;
        int rightChild = 2 * index + 2;
        int largestChild = index;

        if (leftChild < size && data[leftChild].priority > data[largestChild].priority) {
            largestChild = leftChild;
        }

        if (rightChild < size && data[rightChild].priority > data[largestChild].priority) {
            largestChild = rightChild;
        }

        if (largestChild != index) {
            swap(data[index], data[largestChild]);
            down_heap(largestChild);
        }
    }

    [[nodiscard]] bool isEmpty() const {
        return size == 0;
    }
};

#endif