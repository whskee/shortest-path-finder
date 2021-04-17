#pragma once

#define MAX 0x7ffffff

// create a stack
class Stack {
    int top;

public:
    // constructor and destructor
    Stack();
    ~Stack();

    // functions to be implemented in stack.cpp
    int *a;
    bool push(int x);
    int pop();
    int peek();
    bool isEmpty();
};