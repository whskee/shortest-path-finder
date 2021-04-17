#pragma once

// struct elements for the head
struct Element {
    int u;
    int key;
};

// create a HEAP
class MinHeap {
public:
    int capacity;
    int size;
    Element **arr;
    MinHeap *Q;

    // function declarations to be defined in heap.cpp
    MinHeap(int n);
    void buildHeap(Element *arr, int size);
    void insert(int u, int key);
    int extractMin();
    void decreaseKey(int index, int newKey);
    void minHeapify(int index);
    void printHeap();

    // helper functions
    void swap(int x, int y);
    int getLeft(int i);
    int getRight(int i);
    int getParent(int i);
};
