#include <iostream>

using namespace std;

/* Code explanation

This code implements addition of two numbers represented by two linked lists. Each node contains a single digit and the digits are stored in reverse order, meaning that 1->2->3 represents the number 321. The Solution class contains a method addTwoNumbers that takes pointers to the heads of the two linked lists (l1 and l2) as arguments. A new list is initialized with a dummy head, and a pointer cur iterates through the lists, summing corresponding digits along with any carry from the previous sum. The sum's digit is stored in a new node appended to cur, and the carry (if any) is updated for the next iteration. The summing continues until both lists are exhausted and there's no remaining carry. The method returns the sum list starting from the first actual digit, skipping the dummy head.

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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* head = new ListNode(0);
        ListNode* cur = head;
        int carry = 0;
        while (l1 || l2 || carry) {
            int num = (l1 ? l1->val : 0) + (l2 ? l2->val : 0) + carry;
            carry = num / 10;
            cur->next = new ListNode(num % 10);
            cur = cur->next;
            if (l1) l1 = l1->next;
            if (l2) l2 = l2->next;
        }
        return head->next;
    }
};