#include "Stack.h"
#include <iostream>
#include <stdexcept>
#include "string"
#include <vector>
using namespace std;

Stack::Stack() = default;
Stack::~Stack() = default;

// Adds a value to the top of the stack
void Stack::push(int value) {
    data.push_back(value);
}

// Removes the top value from the stack
// Returns true if successful, false if the stack is empty
bool Stack::pop() {
    if (data.empty()) {
        return false;
    }
    data.pop_back();
    return true;
}

// Returns the top value of the stack
// Throws runtime_error if the stack is empty
int Stack::top() const {
    if (data.empty()) {
        throw runtime_error("Stack is empty. No top element.");
    }
    return data.back();
}

// Displays all elements in the stack from bottom to top
void Stack::display() const {
    cout << "Stack contents: ";
    if (data.empty()) {
        cout << "Empty" << endl;
        return;
    }

    for (int value : data) {
        cout << value << " ";
    }
    cout << endl;
}

// Checks if the stack is empty
bool Stack::isEmpty() const {
    return data.empty();
}

// Calculates and returns the average of all stack elements
// Returns 0.0 if the stack is empty
double Stack::average() const {
    if (data.empty()) {
        cout << "Stack is empty. Cannot compute average." << endl;
        return 0.0;
    }

    int sum = 0;
    for (int value : data) {
        sum += value;
    }

    return static_cast<double>(sum) / data.size();
}