#pragma once
#ifndef LINKEDLIST_H
#define LINKEDLIST_H

#include "Node.h" // Include shared Node definition

class SingleLinkedList {
private:
	Node* headptr; // Pointer to the head node
	Node* tailptr; // Pointer to the tail node
	size_t num_items; // number of items in the list

public:
	SingleLinkedList(); // Constructor
	~SingleLinkedList(); // Destructor
	void push_front(const int& value); // Add to front
	void push_back(const int& value); // Add to back
	void pop_front(); // Remove from front
	void pop_back(); // Remove from back
	bool isEmpty() const; // Check if empty
	void front() const; // Access front element
	void back() const; // Access back element
	void insert(size_t index, const int& item); // Insert at position
	bool remove(size_t index); // Remove at position
	size_t find(const int& item); // Find item
	size_t size() const { return num_items; } // Get size of the list
	void printList() const; // Print the list (for debugging)
};

#endif 
