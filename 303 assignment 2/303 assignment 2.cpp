#include <iostream>
#include <string>
#include "Functions.h"     // For getValidInt()
#include "Stack.h"         // Your simplified Stack class
#include "SingleLinkedList.h" // Your linked list class
#include <vector>
using namespace std;



int main() {
    cout << "Welcome! Please choose a data structure to work with:" << endl;
    cout << "1. Stack" << endl;
    cout << "2. Linked List" << endl;

    int choice = getValidInt("Enter your choice (1 or 2): ");

    switch (choice) {
    case 1:
        runStack();
        break;
    case 2:
        runLinkedListInterface();
        break;
    default:
        cout << "Invalid choice. Exiting program." << endl;
        break;
    }

    return 0;
}