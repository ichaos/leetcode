/**
 * Merge Two Sorted Lists
 * Merge two sorted linked lists and return it as a new list. The new list should be made by splicing together the nodes of the first two lists.
 *
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode *mergeTwoLists(ListNode *l1, ListNode *l2) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        ListNode *head = NULL, *cur = NULL;
        if (!l1) return l2;
        if (!l2) return l1;

        while (l1 && l2) {
            if (l1->val < l2->val) {
                if (!head) {
                    head = l1;
                }
                if (!cur) {
                    cur = l1;
                } else {
                    cur->next = l1;
                    cur = cur->next ? cur->next : cur;
                }
                l1 = l1->next;
            } else {
                if (!head) {
                    head = l2;
                }
                if (!cur) {
                    cur = l2;
                } else {
                    cur->next = l2;
                    cur = cur->next ? cur->next : cur;
                }
                l2 = l2->next;
            }
        }
        if (l1) cur->next = l1;
        else if (l2) cur->next = l2;
        return head;
    }
};