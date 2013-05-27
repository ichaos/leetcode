/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode *addTwoNumbers(ListNode *l1, ListNode *l2) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        int si = 0;
        ListNode *p1 = l1;
        ListNode *p2 = l2;
        ListNode *res = new ListNode(0);
        ListNode *pr = res;
        if (!l1)
            return l2;
        if (!l2)
            return l1;
        int sum = 0;
        while (p1 && p2) {
            pr->next = new ListNode(0);
            pr = pr->next;
            sum = p1->val + p2->val + si;
            if (sum >= 10) {
                sum -= 10;
                si = 1;
            } else {
                si = 0;
            }
            pr->val = sum;
            p1 = p1->next;
            p2 = p2->next;
            
        }
        if (!p1) {
            p1 = p2;
        }
        while (p1) {
            pr->next = new ListNode(0);
            pr = pr->next;
            sum = si + p1->val;
            if (sum >= 10) {
                sum -= 10;
                si = 1;
            } else {
                si = 0;
            }
            pr->val = sum;
            p1 = p1->next;
        }
        if (si) {
            pr->next = new ListNode(0);
            pr = pr->next;
            pr->val = si;
        }
        return res->next;
    }
};