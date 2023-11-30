#ifndef NODE_H
#define NODE_H

class Node{
public:
	int val; // the value that this node stores
	Node* next; // a pointer to the next node in the list
	// you can add constructors or other functionality if you find it useful or necessary
	Node(){
		this->next = nullptr;
	}
	Node(unsigned int val) {
		this->val = val;
		this->next = nullptr;
	}
};

#endif