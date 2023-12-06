#include "linked_list.h"

int Linked_List::get_length() {
	// note: there is no set_length(unsigned int) (the reasoning should be intuitive)
	// Your code goes here:
	return length;
}

void Linked_List::print(){
	// output a list of all integers contained within the list
	// Your code goes here:
	cout << "\n";
	cout << head.val << endl;
	Node* itr;
	while (itr.next != nullptr) {
		itr = itr.next;
		cout << itr.value << endl;
	}
	return;
}

void Linked_List::clear(){
	// delete the entire list (remove all nodes and reset length to 0)
	// Your code goes here:

	// O(n^2)?


	Node* itr = head;

	//while head's next exists
	while (itr.next != nullptr) {
		
		//go to back of list
		while (itr.next != nullptr) {
			itr = itr.next;
		}
		//delete last node
		delete *itr.next;
		//reset pointer
		itr.next = nullptr;
		//go to top of list
		itr = head;
	}
	delete *head;
	head = nullptr;
	length = 0;
	return;
}

void Linked_List::push_front(int val){
	// insert a new value at the front of the list 

	Node* new_head = new Node(val);
	new_head->next = nullptr; //probably redundant

	//set next of new head to be old head

	//then set head to be next in lines
	head = new_head;
	length++;
	return;
}

void Linked_List::push_back(int val){
	// insert a new value at the back of the list 
	node* new_node = new node(val);
	new_node->next = nullptr;

	//go to back
	Node* itr = head;
	while (itr.next != nullptr) {
		itr = itr->next;
	}
	//set next node to new node
	itr->next = new Node(val);
	length++;
	return;
}

void Linked_List::insert(int val, int index){
	// insert a new value in the list at the specified index 
	// Your code goes here:
	//make new node
	//go to node before target index
	//set node to next
	// set old next to new node
	return;
}

void Linked_List::pop_back(){
	// remove the node at the back of the list
	// Your code goes here:

	return;
}

void Linked_List::pop_front(){
	// remove the node at the front of the list
	// Your code goes here:
	Node* second = head->next;
	delete head;
	head = second;
	return;
}

void Linked_List::remove(int index){
	// remove the node at index of the list
	// Your code goes here:

	return;
}

void Linked_List::sort_ascending(){
	// sort the nodes in ascending order. You must implement the recursive Merge Sort algorithm
	// Note: it's okay if sort_ascending() calls a recursive private function to perform the sorting.
	// Your code goes here:

	return;
}

void Linked_List::sort_descending(){
	// sort the nodes in descending order
	// Your code goes here:

	return;
}
