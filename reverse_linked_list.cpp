#include <iostream>
#include <vector>

using namespace std;

/* Code Explanation

This C++ code defines a class `Solution` that contains a method `reverseList` for reversing a singly linked list. The linked list nodes are represented using the `ListNode` struct, which contains an integer value `val` and a pointer to the next node `next`. The `reverseList` method takes the head node of a linked list as input and iterates through the list, reversing the pointers of each node to point to the previous node. This is achieved by using two pointers, `prevNode` and `nextNode`, to keep track of the previous and next nodes as the iteration progresses. The method returns the new head of the reversed linked list (which was originally the last node of the input linked list).

*/

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        ListNode *nextNode, *prevNode = NULL;
        while (head) {
            nextNode = head->next;
            head->next = prevNode;
            prevNode = head;
            head = nextNode;
        }
        return prevNode;
    }
};