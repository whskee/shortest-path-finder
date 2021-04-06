#pragma once

#include <string>
using namespace std;

// struct elements for the head
struct HeapNode {
    int key;
};

// create a HEAP
class MinHeap {
public:
int capacity;
    int size;
    HeapNode *H;

    // function declarations to be defined in heap.cpp
    MinHeap(int n);
    void buildHeap(HeapNode *H, int size);
    void insert(HeapNode *element);
    void extractMin();
    void decreaseKey(int index, int value);
    void minHeapify(int index);
    void printHeap();

    // helper functions
    void swap(int x, int y);
    int getLeft(int i);
    int getRight(int i);
    int getParent(int i);
};