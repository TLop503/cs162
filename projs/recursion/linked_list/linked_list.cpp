#include "linked_list.h"

/**************************************************
 * Name: get_length()
 * Description: simple getter
 ***********************************************/
int Linked_List::get_length() {
	// note: there is no set_length(unsigned int) (the reasoning should be intuitive)
	// Your code goes here:
	return length;
}


/**************************************************
 * Name: print
 * Description: pprints each value in the list
 * Parameters: n/a
 * Pre-conditions: list exists
 * Post-conditions: will just cout
 ***********************************************/
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


/**************************************************
 * Name: clear
 * Description: will delete each node, starting at the head
 * Parameters: none
 * Pre-conditions: can be called by destructor
 * Post-conditions: head will point to nullptr
 ***********************************************/
void Linked_List::clear() {
    //starts deleting from the front to the back

    Node* current = head;
    Node* nextNode = nullptr;

    while (current != nullptr) {
        nextNode = current->next;  // Save the next node before deleting the current one
        delete current;
        current = nextNode;
    }

    head = nullptr;
    length = 0;
}


/**************************************************
 * Name: push_front
 * Description: appends a new node to the front of the list
 * Parameters: val - the value to be stored in the new node
 * Pre-conditions: list exists
 * Post-conditions: size will be incremented
 ***********************************************/
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


/**************************************************
 * Name: push_back
 * Description: push front, but for back
 * Parameters: val - the value to be stored in the new node
 * Pre-conditions: list exists
 * Post-conditions: size will be incremented
 ***********************************************/
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


/**************************************************
 * Name: insert
 * Description: adds new value at specified index
 * Parameters: val - the value to be stored in the new node, index - where to insert
 * Pre-conditions: index is valid, otherwise fail
 * Post-conditions: new value will exist at specified index
 ***********************************************/
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


/**************************************************
 * Name: pop_back
 * Description: Deletes the last node in the list
 * Parameters: none
 * Pre-conditions: node exists, otherwise fail
 * Post-conditions: node will be removed
 ***********************************************/
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



/**************************************************
 * Name: pop_front
 * Description: identical to pop_back, but for front
 ***********************************************/
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


/**************************************************
 * Name: remove
 * Description: nuke node at given index
 * Parameters: index - where to remove
 * Pre-conditions: index must exist, else fail
 * Post-conditions: node will be removed
 ***********************************************/
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


/**************************************************
 * Name: get_middle
 * Description: find the middle node of a linked list
 * Parameters: head - the head node of the linked list
 * Pre-conditions: head must not be null
 * Post-conditions: returns the middle node of the linked list
 ***********************************************/
Node* get_middle(Node* head) {
    if (head == nullptr) {
        return head;
    }

    Node* slow = head;
    Node* fast = head;

    while (fast->next != nullptr && fast->next->next != nullptr) {
        slow = slow->next;
        fast = fast->next->next;
    }

    return slow;
}


/**************************************************
 * Name: merge
 * Description: merge two sorted linked lists
 * Parameters: head_a, head_b - the head nodes of the two sorted linked lists
 * Pre-conditions: head_a and head_b must not be null
 * Post-conditions: returns the head node of the merged linked list
 ***********************************************/
Node* merge(Node* head_a, Node* head_b) {
    Node dummy; //temp head for outputting later
    Node* merged = &dummy;

    while (head_a != nullptr && head_b != nullptr) {
        if (head_a->val <= head_b->val) {
            merged->next = head_a;
            head_a = head_a->next;
        } else {
            merged->next = head_b;
            head_b = head_b->next;
        }
        merged = merged->next;
    }

    if (head_a != nullptr) {
        merged->next = head_a;
    } else {
        merged->next = head_b;
    }

    return dummy.next;
}


/**************************************************
 * Name: sort
 * Description: sort a linked list using merge sort
 * Parameters: head - the head node of the linked list
 * Pre-conditions: head must not be null
 * Post-conditions: returns the head node of the sorted linked list
 ***********************************************/
Node* sort(Node* head) {
    //check for size 0 or 1
    if (!head || !head->next) {
        return head;
    }

    Node* middle = get_middle(head);
    Node* new_head = middle->next;
    middle->next = nullptr; //seperate 2 lists

    Node* out = merge(sort(head), sort(new_head));
    return out;
}


/**************************************************
 * Name: sort_ascending
 * Description: sort the nodes in ascending order
 * Parameters: n/a
 * Pre-conditions: list exists
 * Post-conditions: list will be sorted
 ***********************************************/
void Linked_List::sort_ascending(){
	// sort the nodes in ascending order. You must implement the recursive Merge Sort algorithm
	// Note: it's okay if sort_ascending() calls a recursive private function to perform the sorting.
	// Your code goes here:
	head = sort(head);
	return;
}


/**************************************************
 * Name: sort_descending
 * Description: sort the nodes in descending order by just inverting the ascending sort
 * Parameters: n/a
 * Pre-conditions: list exists
 * Post-conditions: list will be sorted
 ***********************************************/
void Linked_List::sort_descending(){
    // sort the nodes in ascending order
    sort_ascending();

    //and then invert the list

    Node* prev = nullptr;
    Node* current = head;
    Node* next_node = nullptr;

    while (current != nullptr) { //traverse list
        //"reverse" each link to invert order

        next_node = current->next; 
        current->next = prev;
        prev = current;
        current = next_node;
    }

    head = prev;
    return;
}
