#pragma once

#include <string>
using namespace std;

// struct elements for the head
struct HeapNode {
    int key;
};

// create a HEAP
struct MinHeap {
    int capacity;
    int size;
    HeapNode* arr;
};

// function declarations to be defined in heap.cpp
MinHeap* initialize(int n);
void buildHeap(MinHeap* element, int size);
void insert(MinHeap* heap, HeapNode* element);
void extractMin(MinHeap* heap);
void decreaseKey(MinHeap* heap, int index, int value);
void minHeapify(MinHeap* heap, int index);
void writeHeap(MinHeap* heap);
void printHeap(MinHeap* heap);
void swap(int x, int y);
int getLeft(int i);
int getRight(int i);
int getParent(int i);
int getHeapifyCalls();
