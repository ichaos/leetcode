/**
 * Remove Duplicates from Sorted List II
 * Given a sorted linked list, delete all nodes that have duplicate numbers, leaving only distinct numbers from the original list.

For example,
Given 1->2->3->3->4->4->5, return 1->2->5.
Given 1->1->1->2->3, return 2->3.
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
    ListNode *deleteDuplicates(ListNode *head) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        ListNode *cur = head ? head->next : NULL;
        ListNode *prev = head;
        ListNode *lst = NULL;
        ListNode *ret = NULL;
        bool dup = false;
        while (cur) {
            if (cur->val == prev->val) {
                dup = true;
            } else {
                if (dup) {                    
                    prev = cur;
                    dup = false;
                } else {
                    if (!lst) {
                        ret = prev;
                        lst = prev;
                    } else {
                        lst->next = prev;
                        lst = prev;
                    }
                    prev = cur;
                }
            }
            cur = cur->next;
        }
        if (lst) {
            if (dup == false) {
                lst->next = prev;
            } else {
                lst->next = NULL;
            }
        } else {
            if (dup == false) {
                //lst = prev;
                ret = prev;
            }
        }
        //if (prev) prev->next = NULL;
        return ret;
    }
};