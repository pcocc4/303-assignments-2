#pragma once 
#include <iostream>
using namespace std;
#ifndef NODE_H
#define NODE_H

struct Node {
    int currNode;
    Node* nextNode;

	Node(const int& currNode, Node* nextNode = nullptr)
		: currNode(currNode), nextNode(nextNode) {
	}
};

#endif
