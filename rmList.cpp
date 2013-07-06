/**
 * Remove Nth Node From End of List
 * Given a linked list, remove the nth node from the end of list and return its head.

For example,

   Given linked list: 1->2->3->4->5, and n = 2.

   After removing the second node from the end, the linked list becomes 1->2->3->5.
Note:
Given n will always be valid.
Try to do this in one pass.
 * 
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */

#include <iostream>

using namespace std;

struct ListNode {
     int val;
     ListNode *next;
     ListNode(int x) : val(x), next(NULL) {} 
     };
 
class Solution {
public:
    ListNode *removeNthFromEnd(ListNode *head, int n) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        if (n < 1 || !head) return head;
        ListNode *lp = head;
        int l = 0;
        while (lp) {
            l++;
            lp = lp->next;
        }
        
        int r = l - n;
        if (r < 0) return head;
        
        if (r == 0) {
            head = head->next;
            return head;
        }
        l = 0;        
        lp = head;
        while (lp->next) {      
            l++;
            if (l == r) {
                lp->next = lp->next->next;
                return head;
            }
            lp = lp->next;
        }
        return head;
    }
};

int main () {
    Solution s;
    ListNode h(1);
    s.removeNthFromEnd(&h, 1);
    int i = 0;
    cin >> i;
}
