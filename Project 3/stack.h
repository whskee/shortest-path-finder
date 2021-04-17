#pragma once

#define MAX 0x7ffffff

// create a stack
class Stack {
    int top;

public:
    int *a; // Maximum size of Stack
    Stack();
    bool push(int x);
    int pop();
    int peek();
    bool isEmpty();
};