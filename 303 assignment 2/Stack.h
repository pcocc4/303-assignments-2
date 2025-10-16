#pragma once
#ifndef STACK_H
#define STACK_H

#include <string>
#include <vector>
#include <iostream>
using namespace std;

class Stack {
private:
    std::vector<int> data;

public:
    Stack();
    ~Stack();
    // Adds an element to the top of the stack
    void push(int value);

    // Removes the top element from the stack
    // Returns true if successful, false if the stack is empty
    bool pop();

    // Returns the top element of the stack without removing it
    // Throws runtime_error if the stack is empty
    int top() const;

    // Checks whether the stack is empty
    bool isEmpty() const;

    // Displays all elements in the stack from bottom to top
    void display() const;

    // Returns the number of elements currently in the stack
    size_t size() const;

    // Calculates and returns the average of all stack elements
    // Returns 0.0 if the stack is empty
    double average() const;
};

#endif // STACK_H