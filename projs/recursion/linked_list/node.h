#ifndef NODE_H
#define NODE_H

#include <iostream>

class Node{
public:
	int val; // the value that this node stores
	Node* next; // a pointer to the next node in the list
	// you can add constructors or other functionality if you find it useful or necessary
	Node(){
		this->next = nullptr;
	}
	Node(int val) {
		//std::cout << "New node with value " << val << std::endl;
		this->val = val;
		//std::cout << "value: " << this->val << std::endl;
		this->next = nullptr;
	}
};

#endif