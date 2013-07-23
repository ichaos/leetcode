/**
 * Rotate List
 * Given a list, rotate the list to the right by k places, where k is non-negative.

For example:
Given 1->2->3->4->5->NULL and k = 2,
return 4->5->1->2->3->NULL.


 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode *rotateRight(ListNode *head, int k) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        if (k == 0 || !head) return head;
        ListNode *begin = head;
        int l = 1;
        while (begin->next) {
            l++;
            begin = begin->next;
        }
        begin->next = head;
        begin = head;
        ListNode *nh = head;
        int m = l - (k % l);
        while (m > 0) {
            nh = nh->next;
            m--;
        }
        begin = nh;
        while (--l > 0) {
            begin = begin->next;
            //l--;
        }
        begin->next = NULL;
        return nh;
    }
};