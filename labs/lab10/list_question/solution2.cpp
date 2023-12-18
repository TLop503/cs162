#include <iostream>

#include "list.h"
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
ListNode* removeNthFromEnd2(ListNode* head, int n) {
    ListNode* slow = head;
    ListNode* fast = head;

    for (int i = 0; i < n; i++) {
        if (fast) {
            fast = fast->next;
        }
    }

    // If n is equal to the length of the list
    if (fast == nullptr) {
        ListNode* temp = head;
        head = head->next;
        delete temp;
        return head;
    }

    while (fast->next) {
        fast = fast->next;
        slow = slow->next;
    }

    ListNode* temp = slow->next;
    slow->next = slow->next->next;
    delete temp;
    return head;
}

ListNode* removeNthFromEnd2(ListNode* head, int n) {
    //std::cout << "starting" << std::endl;
    
    // Traverse once to find size
    ListNode* itr = head;
    int size = 0;
    while (itr != nullptr) {
        itr = itr->next;
        size++;
    }

    // If n is equal to size, delete the head node
    if (n == size) {
        ListNode* temp = head->next;
        delete head;
        head = temp;
        //std::cout << "complete" << std::endl;
        return head;
    }

    // Go to target
    itr = head;
    for (int i = 0; i < size - n - 1; i++) {
        itr = itr->next;
    }

    // Delete the nth node from the end
    ListNode* temp = itr->next;
    itr->next = itr->next->next;
    delete temp;

    //std::cout << "complete" << std::endl;
    return head;
}
