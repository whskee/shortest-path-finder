#include "heap.h"
#include <cmath>
#include <fstream>
#include <iomanip>
#include <iostream>
#include <string>

using namespace std;

// function to intialize the heap
MinHeap::MinHeap(int n) {
    H = new HeapNode[n + 1];
    capacity = n;
    size = 0;
}

// function to build heap
void MinHeap::buildHeap(HeapNode *H, int size) {
    size = 0;
    for (int x = 1; x <= size; x++) {
        H[x] = H[x];
        size++;
    }
    for (int i = floor(size / 2); i >= 1; i--) {
        minHeapify(i);
    }
}

// function to insert an element into heap
void MinHeap::insert(HeapNode *element) {
    size++;
    decreaseKey(size, element->key);
}

// function to delete minimum from heap
void MinHeap::extractMin() {
    H[1].key = H[size].key;
    size--;
    minHeapify(1);
}

// function to perform DecreaseKey on heap with index and value
void MinHeap::decreaseKey(int index, int value) {
    H[index].key = value;
    while (index > 1 && H[getParent(index)].key > H[index].key) {
        swap(index, getParent(index));
        index = getParent(index);
    }
}

// function to make sure MinHeap property is maintained
void MinHeap::minHeapify(int index) {
    int l = getLeft(index);
    int r = getRight(index);
    int smallest;

    if (l <= size && H[l].key < H[index].key) {
        smallest = l;
    } else {
        smallest = index;
    }

    if (r <= size && H[r].key < H[smallest].key) {
        smallest = r;
    }
    if (smallest != index) {
        swap(index, smallest);
        minHeapify(smallest);
    }
}

// function to print contents of the heap
void MinHeap::printHeap() {
    cout << "capacity=" << capacity << ", "
         << "size=" << size << endl;
    if (size != 0) {
        for (int i = 1; i <= size; i++) {
            cout << H[i].key;
            if (i != size) {
                cout << ", ";
            }
        }
        cout << endl;
    }
}

// function to swap two elements
void MinHeap::swap(int x, int y) {
    HeapNode temp = H[x];
    H[x] = H[y];
    H[y] = temp;
}

// function to return the left child index of the specified index i
int MinHeap::getLeft(int i) {
    return 2 * i;
}

// function to return the right child index of the specified index i
int MinHeap::getRight(int i) {
    return 2 * i + 1;
}

// function to return the parent index of the specified index i
int MinHeap::getParent(int i) {
    return floor(i / 2);
}