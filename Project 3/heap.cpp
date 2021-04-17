#include "heap.h"
#include "Graph.h"
#include <cmath>
#include <iostream>

using namespace std;

// parameterized constructor
MinHeap::MinHeap(int n) {
    arr = (Element **)calloc(n + 1, sizeof(Element *));
    capacity = n;
    size = 0;
}

// destructor
MinHeap::~MinHeap() {
    delete arr;
    delete Q;
}

// function to build heap
void MinHeap::buildHeap(Element *arr, int size) {
    size = 0;
    for (int x = 1; x <= size; x++) {
        arr[x] = arr[x];
        size++;
    }
    for (int i = floor(size / 2); i >= 1; i--) {
        minHeapify(i);
    }
}

// function to insert an element into heap
void MinHeap::insert(int u, int key) {
    if (size == capacity) {
        cout << "Overflow\n";
    } else {
        Element *newElement = new Element;
        newElement->u = u;
        newElement->key = key;
        size++;
        arr[size] = newElement;
        //printHeap();
        decreaseKey(size, key);
    }
}

// function to delete minimum from heap
int MinHeap::extractMin() {
    arr[1]->key = arr[size]->key;
    //cout << arr[1]->key;
    size--;
    minHeapify(1);
    return arr[1]->key;
}

// function to perform DecreaseKey on heap with index and value
void MinHeap::decreaseKey(int index, int newKey) {
    if (index < 1 || index > size || index >= arr[index]->key) {
        printf("Error in DecreaseKey\n");
    } else {
        arr[index]->key = newKey;
        while (index > 1 && arr[getParent(index)]->key > arr[index]->key) {
            swap(index, getParent(index));
            
            // V[arr[index]->u]->index = index;
            // V[arr[index]->u]->pos = getParent(index);
            index = getParent(index);
        }
    }
}

// function to make sure MinHeap property is maintained
void MinHeap::minHeapify(int index) {
    int l = getLeft(index);
    int r = getRight(index);
    int smallest;

    if (l <= size && arr[l]->key < arr[index]->key) {
        smallest = l;
    } else {
        smallest = index;
    }

    if (r <= size && arr[r]->key < arr[smallest]->key) {
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
            cout << arr[i]->key;
            if (i != size) {
                cout << ", ";
            }
        }
        cout << endl;
    }
}

// function to swap two elements
void MinHeap::swap(int x, int y) {
    Element *temp = arr[x];
    arr[x] = arr[y];
    arr[y] = temp;
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