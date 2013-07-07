/**
 * Swap Nodes in Pairs
 * Given a linked list, swap every two adjacent nodes and return its head.

For example,
Given 1->2->3->4, you should return the list as 2->1->4->3.

Your algorithm should use only constant space. You may not modify the values in the list, only nodes itself can be changed.
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
private:
    ListNode *_swapTwo(ListNode *head) {
        if (!head || !head->next)
            return head;
        else {
            ListNode *res = head->next;
            head->next = head->next->next;
            res->next = head;
            return res;
        }
        // or we have a smart cheat way
        // int tmp = head->val;
        // head->val = head->next->val;
        // head->next->val = tmp;
    }
public:
    ListNode *swapPairs(ListNode *head) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        ListNode *ret = _swapTwo(head);
        head = ret;
        if (!head || !head->next) return ret;
        head = head->next;//->next;
        while (head) {
            head->next = _swapTwo(head->next);
            if (head->next && head->next->next) {
                head = head->next->next;
            } else
                return ret;
        }
        return ret;
    }
};
