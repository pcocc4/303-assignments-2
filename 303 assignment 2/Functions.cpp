#include <iostream>
#include <string>
#include "Stack.h"
#include "Functions.h"  
#include <stdexcept>
#include <vector>
#include "SingleLinkedList.h"
using namespace std;
// Displays the Linked List menu options
void runLinkedListMenu() {
    cout << "\n===== Linked List Menu =====" << endl;
    cout << "1. Push Front (Add to front)" << endl;
    cout << "2. Push Back (Add to back)" << endl;
    cout << "3. Pop Front (Remove from front)" << endl;
    cout << "4. Pop Back (Remove from back)" << endl;
    cout << "5. Check if Empty" << endl;
    cout << "6. Access Front Element" << endl;
    cout << "7. Access Back Element" << endl;
    cout << "8. Insert at Position" << endl;
    cout << "9. Remove at Position" << endl;
    cout << "10. Find Item" << endl;
    cout << "11. Print List" << endl;
    cout << "0. Exit" << endl;
    cout << "=============================" << endl;
}

// Prompts the user for a valid integer input with error handling
int getValidInt(const std::string& prompt) {
    std::string input;
    int inputNum;

    while (true) {
        std::cout << prompt << " ";
        std::getline(std::cin, input);

        try {
            inputNum = std::stoi(input); // Convert string to int
            return inputNum;
        }
        catch (std::invalid_argument&) {
            std::cout << "Invalid input. Please enter a valid integer." << std::endl;
        }
        catch (std::out_of_range&) {
            std::cout << "Number out of range. Try again." << std::endl;
        }
    }
}

// Runs the Linked List interface and handles user interaction
void runLinkedListInterface() {
    SingleLinkedList list;
    int userChoice;
    int value;
    int index;
    size_t foundIndex;

    while (true) {
        runLinkedListMenu();
        userChoice = getValidInt("Enter your choice: ");

        switch (userChoice) {
        case 1: // Push to front
            value = getValidInt("Enter value to push to front: ");
            list.push_front(value);
            break;
        case 2: // Push to back
            value = getValidInt("Enter value to push to back: ");
            list.push_back(value);
            break;
        case 3: // Pop from front
            list.pop_front();
            break;
        case 4: // Pop from back
            list.pop_back();
            break;
        case 5: // Check if empty
            cout << (list.isEmpty() ? "List is empty." : "List is not empty.") << endl;
            break;
        case 6: // Access front element
            list.front();
            break;
        case 7: // Access back element
            list.back();
            break;
        case 8: // Insert at index
            cout << "Current index range: (0 to " << list.size() << ")" << endl;
            index = getValidInt("Enter index to insert at: ");
            value = getValidInt("Enter value to insert: ");
            list.insert(index, value);
            break;
        case 9: // Remove at index
            cout << "Current index range: (0 to " << list.size() - 1 << ")" << endl;
            index = getValidInt("Enter index to remove at: ");
            cout << (list.remove(index) ? "Element removed successfully." : "Failed to remove element.") << endl;
            break;
        case 10: // Find item
            value = getValidInt("Enter value to find: ");
            foundIndex = list.find(value);
            if (foundIndex != list.size()) {
                cout << "Element found at index: " << foundIndex << endl;
            }
            else {
                cout << "Element not found in the list." << endl;
            }
            break;
        case 11: // Print list
            list.printList();
            break;
        case 0: // Exit
            cout << "Exiting program." << endl;
            return;
        default: // Invalid input
            cout << "Invalid choice. Please try again." << endl;
        }
    }
}

// Displays the Stack menu options
void displayMenuStack() {
    cout << "\n===== Stack Menu =====" << endl;
    cout << "1. Push an element" << endl;
    cout << "2. Pop the top element" << endl;
    cout << "3. View the top element" << endl;
    cout << "4. Display the stack" << endl;
    cout << "5. Check if stack is empty" << endl;
    cout << "6. Calculate avg" << endl;
    cout << "0. Exit" << endl;
}

// Runs the Stack interface and handles user interaction
void runStack() {
    Stack myStack;
    int choice;
    int value;

    while (true) {
        displayMenuStack();
        choice = getValidInt("Enter your choice: ");

        switch (choice) {
        case 1: // Push element
            value = getValidInt("Enter a number to add to the stack: ");
            myStack.push(value);
            break;

        case 2: // Pop element
            if (!myStack.pop())
                cout << "Stack is empty, cannot pop." << endl;
            break;

        case 3: // View top element
            try {
                cout << "Top element: " << myStack.top() << endl;
            }
            catch (const runtime_error& e) {
                cout << e.what() << endl;
            }
            break;

        case 4: // Display stack
            myStack.display();
            break;

        case 5: // Check if empty
            if (myStack.isEmpty())
                cout << "Stack is empty." << endl;
            else
                cout << "Stack is not empty." << endl;
            break;

        case 6: // Calculate average
        {
            double avg = myStack.average();
            if (avg != 0.0) {
                cout << "Average of stack elements: " << avg << endl;
            }
            break;
        }

        case 0: // Exit
            cout << "Exiting program." << endl;
            return;

        default: // Invalid input
            cout << "Invalid choice. Please try again." << endl;
        }
    }
}