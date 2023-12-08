#include "linked_list.h"

int Linked_List::get_length() {
	// note: there is no set_length(unsigned int) (the reasoning should be intuitive)
	// Your code goes here:
	return length;
}

void Linked_List::print(){
	// output a list of all integers contained within the list
	// Your code goes here:
	if (head == nullptr) {
		return;
	}
	cout << "\n";
	Node* itr = head;
	//cout << itr->next << "!!!!!!!!!!!!";
	while (itr != nullptr) {
		//cout << "test" << endl;
		cout << itr->val << " ";
		itr = itr->next;
	}
	cout << "\n";
	return;
}

void Linked_List::clear(){
	// delete the entire list (remove all nodes and reset length to 0)
	// Your code goes here:

	// O(n^2)?


	Node* itr = head;

	//while head's next exists
	while (itr != nullptr) {

		//go to back of list
		while (itr->next != nullptr) {
			itr = itr->next;
		}
		//delete last node
		delete itr->next;
		//reset pointer
		itr->next = nullptr;
		//go to top of list
		itr = head;
	}
	delete head;
	head = nullptr;
	length = 0;
	return;
}

void Linked_List::push_front(int val){
	// insert a new value at the front of the list


	Node* new_head = new Node(val);
	//cout << "New node value: " << new_head->val << endl;
	new_head->next = nullptr; //probably redundant

	//set next of new head to be old head
	//then set head to be next in lines
	new_head->next = head;
	head = new_head;
	//cout << "updated head value: " << head->val << endl;
	length++;
	return;
}

void Linked_List::push_back(int val){

	//cout << "pushing back: " << val << endl;

    Node* new_node = new Node(val);
    new_node->next = nullptr;

    if (head == nullptr) {
		//cout << "head was nullptr" << endl;
        head = new_node;
    } else {
        Node* itr = head;
        while (itr->next != nullptr) {
            itr = itr->next;
        }
        itr->next = new_node;
    }
    length++;
	return;
}

void Linked_List::insert(int val, int index){
    if (index > this->length) { //if trying to access oob just pushback
        //push_back(val); //but for assignment it's supposed to just fail
        return;
    }

    Node* new_node = new Node(val);

    if (head == nullptr || index == 0) { //if first value just set head
        new_node->next = head;
        head = new_node;
    } else {
        Node* itr = head;
        for (int i = 0; i < index - 1; i++) {
            itr = itr->next;
        }
        new_node->next = itr->next;
        itr->next = new_node;
    }
    length++;
    return;
}

void Linked_List::pop_back(){
    if (head == nullptr) {
        return;
    }

    // If the list only contains one element
    if (head->next == nullptr) {
        delete head;
        head = nullptr;
    } else {
        Node* itr = head;
        while (itr->next->next != nullptr) {
            itr = itr->next;
        }
        delete itr->next;
        itr->next = nullptr;
    }
    length--;
}

void Linked_List::pop_front(){
	// remove the node at the front of the list
	// Your code goes here:
	// if (head->next != nullptr) {
	// 	Node* second = head->next;
	// }

	Node* second = nullptr;
	if (head != nullptr) {
		second = head->next;
		if (length != 0) {
			length--;
		}
		delete head;
		head = second;
	}
	return;
}

void Linked_List::remove(int index){
    if (index > this->length || head == nullptr) { //if trying to access oob just pushback
        //push_back(val); //but for assignment it's supposed to just fail
        return;
    }
	if (index == 0) {
		pop_front();
		return;
	}
	else if (index == length - 1) {
		pop_back();
		return;
    } else {
        Node* itr = head;
		Node* temp;
        for (int i = 0; i < index - 1; i++) {
            itr = itr->next;
        }
		temp = itr->next->next;
		delete itr->next;
        itr->next = temp;
    }
    length--;
    return;
}

Node* get_middle(Node* head) {
    Node* slow_ptr = head;
    Node* fast_ptr = head;

    if (head != nullptr) {
        while (fast_ptr != nullptr && fast_ptr->next != nullptr) {
            fast_ptr = fast_ptr->next->next;
            slow_ptr = slow_ptr->next;
        }
    }

    return slow_ptr;
}


//merge 2 sorted lists
Node* merge(Node* head_a, Node* head_b) {
    Node* merged = new Node(); // Initialize merged node
    Node* out = merged; // so merged can be accessed later

    // for each node in list
    while (head_a != nullptr && head_b != nullptr) {
        if (head_a->val <= head_b->val) {
            merged->next = head_a; // add to merged
            head_a = head_a->next; // and then iterate
        } else {
            merged->next = head_b;
            head_b = head_b->next;
        }
        // then iterate merged list
        merged = merged->next;
    }

    // cleanup what's left
    while (head_a != nullptr) {
        merged->next = head_a;
        head_a = head_a->next;
        merged = merged->next;
    }
    while (head_b != nullptr) {
        merged->next = head_b;
        head_b = head_b->next;
        merged = merged->next;
    }

	delete merged; //free memory, and the contents are accessible from out
    return out->next; // return first node from heads. 
    // this isn't just out b/c that stores garbage
}

Node* sort(Node* head) {
	//check for size 1
	if (!head->next) {
		return head;
	}

	Node* middle = get_middle(head);
	Node* new_head = middle->next;
	middle->next = nullptr; //seperate 2 lists

	Node* out = merge(sort(head), sort(new_head));
	return out;
}

void Linked_List::sort_ascending(){
	// sort the nodes in ascending order. You must implement the recursive Merge Sort algorithm
	// Note: it's okay if sort_ascending() calls a recursive private function to perform the sorting.
	// Your code goes here:
	sort(head);
	return;
}

void Linked_List::sort_descending(){
	// sort the nodes in descending order
	// Your code goes here:

	return;
}
