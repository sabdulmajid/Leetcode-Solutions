#include <iostream>
#include <vector>

using namespace std;


/*
The function works by creating a new linked list and then iterating over the two input linked lists, node by node. For each node, the function adds the node with the smaller value to the new linked list. The function continues iterating until both input linked lists are empty. The function then returns the head of the new linked list.

Here is a more detailed explanation of the steps the function takes:

    1. The function creates a new linked list and sets its head to null.
    2. The function iterates over the two input linked lists, node by node.
    3. For each node, the function checks if the value of the node is smaller than the value of the node in the new linked list.
    4. If the value of the node is smaller, the function adds the node to the new linked list.
    5. The function continues iterating until both input linked lists are empty.
    6. The function returns the head of the new linked list.

*/

// Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        ListNode* ans = new ListNode();
        ListNode* ptr = ans;
        while(list1 != nullptr && list2 != nullptr){
            if(list1->val <= list2->val){
                ans->next = new ListNode(list1->val);
                list1 = list1->next;
            }
            else{
                ans->next = new ListNode(list2->val);
                list2 = list2->next;
            }
            ans = ans->next;
        }
        while(list1){
            ans->next = new ListNode(list1->val);
            list1 = list1->next;
            ans = ans->next;
        }
        while(list2){
            ans->next = new ListNode(list2->val);
            list2 = list2->next;
            ans = ans->next;
        }
        return ptr->next;
    }
};