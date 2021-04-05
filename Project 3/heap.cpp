#include "heap.h"
#include <cmath>
#include <fstream>
#include <iomanip>
#include <iostream>
#include <string>

using namespace std;

MinHeap *heap;
int heapifyCalls;

// function to intialize the heap
MinHeap *initialize(int n) {
    heap = new MinHeap;
    heap->arr = new HeapNode[n + 1];
    heap->capacity = n;
    heap->size = 0;
    return heap;
}

// function to build heap
void buildHeap(HeapNode *element, int size) {
    heapifyCalls = 0;
    heap->size = 0;
    for (int x = 1; x <= size; x++) {
        heap->arr[x] = element[x];
        heap->size++;
    }
    for (int i = floor(size / 2); i >= 1; i--) {
        minHeapify(heap, i);
    }
}

// function to insert an element into heap
void insert(MinHeap *heap, HeapNode *H) {
    heap->size++;
    decreaseKey(heap, heap->size, H->key);
}

// function to delete minimum from heap
void extractMin(MinHeap *heap) {
    heapifyCalls = 0;
    heap->arr[1].key = heap->arr[heap->size].key;
    heap->size--;
    minHeapify(heap, 1);
}

// function to perform DecreaseKey on heap with index and value
void decreaseKey(MinHeap *heap, int index, int value) {
    heap->arr[index].key = value;
    while (index > 1 && heap->arr[getParent(index)].key > heap->arr[index].key) {
        swap(index, getParent(index));
        index = getParent(index);
    }
}

// function to make sure MinHeap property is maintained
void minHeapify(MinHeap *heap, int index) {
    heapifyCalls++;
    int l = getLeft(index);
    int r = getRight(index);
    int smallest;

    if (l <= heap->size && heap->arr[l].key < heap->arr[index].key) {
        smallest = l;
    } else {
        smallest = index;
    }

    if (r <= heap->size && heap->arr[r].key < heap->arr[smallest].key) {
        smallest = r;
    }
    if (smallest != index) {
        swap(index, smallest);
        minHeapify(heap, smallest);
    }
}

// function to write to a file
void writeHeap(MinHeap *heap) {
    // create output stream and open the file
    ofstream outFile;
    outFile.open("HEAPoutput.txt");

    if (outFile.is_open()) {
        outFile << heap->size << endl;
        for (int i = 1; i <= heap->size; i++) {
            outFile << heap->arr[i].key << endl;
        }
        outFile.close();
    } else {
        cout << "Error: cannot write\n";
    }
}

// function to print contents of the heap
void printHeap(MinHeap *heap) {
    cout << "capacity=" << heap->capacity << ", "
         << "size=" << heap->size << endl;
    if (heap->size != 0) {
        for (int i = 1; i <= heap->size; i++) {
            cout << heap->arr[i].key;
            if (i != heap->size) {
                cout << ", ";
            }
        }
        cout << endl;
    }
}

// function to swap two elements
void swap(int x, int y) {
    HeapNode temp = heap->arr[x];
    heap->arr[x] = heap->arr[y];
    heap->arr[y] = temp;
}

// function to return the left child index of the specified index i
int getLeft(int i) {
    return 2 * i;
}

// function to return the right child index of the specified index i
int getRight(int i) {
    return 2 * i + 1;
}

// function to return the parent index of the specified index i
int getParent(int i) {
    return floor(i / 2);
}

// function that returns the number of times MinHeapify is called
int getHeapifyCalls() {
    return heapifyCalls;
}
