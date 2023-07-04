#include <iostream>
using namespace std;

/*

The function has two pointers, slow and fast, that start at the head of the linked list. The slow pointer moves one node at a time, while the fast pointer moves two nodes at a time. If the two pointers ever meet, then there is a cycle in the linked list. If the two pointers never meet, then there is no cycle in the linked list.

The function works by repeatedly moving the slow and fast pointers until one of the following two conditions is met:

• The fast pointer is NULL, which means that the end of the linked list has been reached. In this case, there is no cycle in the linked list.
• The slow pointer and the fast pointer point to the same node, which means that there is a cycle in the linked list.

In either case, the function returns the appropriate boolean value.

*/

// Definition for singly-linked list
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    bool hasCycle(ListNode *head) {
        ListNode* slow = head;
        ListNode* fast = head;

        while (fast != NULL && fast->next != NULL) {
        	slow = slow->next;
        	fast = fast->next->next;
        	if (slow == fast)  return true; // found the cycle
        }
        return false;
    }
};