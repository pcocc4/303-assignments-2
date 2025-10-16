#include "SingleLinkedList.h"
#include <iostream>
#include "string"
using namespace std;
// Constructor to initialize an empty list
SingleLinkedList::SingleLinkedList() : headptr(nullptr), tailptr(nullptr), num_items(0) {}

// Destructor to clean up the list
SingleLinkedList::~SingleLinkedList() {
	Node* current = headptr;
	while (current != nullptr) {
		Node* temp = current;
		current = current->nextNode;
		delete temp;
	}
}

// Adds a new node with the given value to the end of the list
void SingleLinkedList::push_back(const int& value) {
	Node* newNode = new Node{ value, nullptr };
	if (headptr == nullptr) { // List is empty
		headptr = newNode;
		tailptr = newNode;
	}
	else { // Append to tail
		tailptr->nextNode = newNode;
		tailptr = newNode;
	}
	num_items++;
}

// Adds a new node with the given value to the front of the list
void SingleLinkedList::push_front(const int& value) {
	Node* newNode = new Node{ value, nullptr };
	if (headptr == nullptr) { // List is empty
		headptr = newNode;
		tailptr = newNode;
	}
	else { // Insert before head
		newNode->nextNode = headptr;
		headptr = newNode;
	}
	num_items++;
}

// Removes the last node from the list
void SingleLinkedList::pop_back() {
	if (headptr == nullptr) { // List is empty
		cout << "List is empty, element cannot be removed." << endl;
		return;
	}
	if (headptr == tailptr) { // Only one node
		delete headptr;
		headptr = nullptr;
		tailptr = nullptr;
		num_items--;
	}
	else { // Traverse to second-to-last node
		Node* current = headptr;
		while (current->nextNode != tailptr) {
			current = current->nextNode;
		}
		delete tailptr;
		tailptr = current;
		tailptr->nextNode = nullptr;
		current = nullptr;
		num_items--;
	}
}

// Removes the first node from the list
void SingleLinkedList::pop_front() {
	if (headptr == nullptr) { // List is empty
		cout << "List is empty, element cannot be removed." << endl;
		return;
	}
	if (headptr == tailptr) { // Only one node
		delete headptr;
		headptr = nullptr;
		tailptr = nullptr;
		num_items--;
	}
	else { // Move head forward
		Node* temp = headptr;
		headptr = headptr->nextNode;
		delete temp;
		num_items--;
	}
}

// Displays the value of the first node
void SingleLinkedList::front() const {
	if (headptr == nullptr) {
		cout << "List is empty, no front element." << endl;
		return;
	}
	cout << "First element: " << headptr->currNode << endl;
}

// Displays the value of the last node
void SingleLinkedList::back() const {
	if (tailptr == nullptr) {
		cout << "List is empty, no back element." << endl;
		return;
	}
	cout << "Last element: " << tailptr->currNode << endl;
}

// Returns true if the list is empty
bool SingleLinkedList::isEmpty() const {
	if (num_items == 0) {
		return true;
	}
	else {
		return false;
	}
}

// Inserts a new node with the given value at the specified index
void SingleLinkedList::insert(size_t index, const int& item) {
	if (index > num_items) {
		cout << "Index out of bounds, cannot insert." << endl;
		return;
	}
	else {
		if (headptr == nullptr && tailptr == nullptr) { // Empty list
			cout << "List is empty, inserting the first element." << endl;
			Node* newNode = new Node{ item, nullptr };
			headptr = newNode;
			tailptr = newNode;
			num_items++;
			return;
		}
		else if (index == 0) { // Insert at front
			Node* newNode = new Node{ item, nullptr };
			newNode->nextNode = headptr;
			headptr = newNode;
			num_items++;
			return;
		}
		else { // Insert in middle or end
			int i;
			Node* currNode = headptr;
			Node* newNode = new Node{ item, nullptr };
			for (i = 0; i < index - 1; ++i) {
				currNode = currNode->nextNode;
			}
			if (currNode == tailptr) { // Insert at end
				tailptr->nextNode = newNode;
				tailptr = newNode;
				num_items++;
				return;
			}
			else { // Insert in middle
				newNode->nextNode = currNode->nextNode;
				currNode->nextNode = newNode;
				num_items++;
				return;
			}
		}
	}
}

// Removes the node at the specified index
bool SingleLinkedList::remove(size_t index) {
	if (index >= num_items) {
		cout << "Index out of bounds, cannot remove." << endl;
		return false;
	}

	if (index == 0) { // Remove front
		Node* temp = headptr;
		headptr = headptr->nextNode;
		if (temp == tailptr) {
			tailptr = nullptr;
		}
		delete temp;
		num_items--;
		return true;
	}

	Node* currNode = headptr;

	if (index == num_items - 1) { // Remove back
		if (headptr == tailptr) {
			delete headptr;
			headptr = tailptr = nullptr;
		}
		else {
			while (currNode->nextNode != tailptr) {
				currNode = currNode->nextNode;
			}
			delete tailptr;
			tailptr = currNode;
			currNode->nextNode = nullptr;
		}
		num_items--;
		return true;
	}

	// Remove from middle
	for (size_t i = 0; i < index - 1; ++i) {
		currNode = currNode->nextNode;
	}

	Node* temp = currNode->nextNode;
	currNode->nextNode = temp->nextNode;
	delete temp;
	num_items--;
	return true;
}

// Searches for the given value and returns its index, or num_items if not found
size_t SingleLinkedList::find(const int& item) {
	size_t index = 0;
	if (headptr == nullptr && tailptr == nullptr) { // Empty list
		cout << "List is empty, cannot find element." << endl;
		return num_items;
	}
	else if (headptr == tailptr) { // Single node
		if (headptr->currNode == item || tailptr->currNode == item) {
			return index;
		}
		else {
			cout << "Element not found in the list." << endl;
			return num_items;
		}
	}
	else { // Traverse list
		Node* curr = headptr;
		while (curr != nullptr) {
			if (curr->currNode == item) {
				cout << "Element found at index: " << index << endl;
				return index;
			}
			curr = curr->nextNode;
			index++;
		}
		cout << "Element not found in the list." << endl;
		return num_items;
	}
}

// Prints all elements in the list
void SingleLinkedList::printList() const {
	Node* current = headptr;
	cout << "Linked List: ";

	if (current == nullptr) {
		cout << "Empty" << endl;
		return;
	}

	while (current != nullptr) {
		cout << current->currNode;
		if (current->nextNode != nullptr) {
			cout << " -> ";
		}
		current = current->nextNode;
	}

	cout << endl;
}