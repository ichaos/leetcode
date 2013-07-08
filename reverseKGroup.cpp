/**
 * Reverse Nodes in k-Group
 * Given a linked list, reverse the nodes of a linked list k at a time and return its modified list.

If the number of nodes is not a multiple of k then left-out nodes in the end should remain as it is.

You may not alter the values in the nodes, only nodes itself may be changed.

Only constant memory is allowed.

For example,
Given this linked list: 1->2->3->4->5

For k = 2, you should return: 2->1->4->3->5

For k = 3, you should return: 3->2->1->4->5
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
    ListNode *_reverseKGroup(ListNode *head, int k) {
        if (!head) return NULL;
        ListNode *t = head->next;
        ListNode *tail;
        //check
        int i = 0;
        while (t) {
            i++;
            t = t->next;
        }
        if (i < k) return NULL;
        
        ListNode r(0);
        ListNode *rp = &r;
        t = head->next;
        ListNode *tmp;
        i = 0;
        while (i < k) {  
            tmp = t;
            t = t->next;
            tmp->next = r.next;
            r.next = tmp;
            i++;
        }
        //set tail
        head->next = r.next;
        tmp = r.next;
        while (tmp->next) {
            tmp = tmp->next;
        }
        tmp->next = t;
        return tmp;
    }
public:
    ListNode *reverseKGroup(ListNode *head, int k) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        ListNode ret(0);
        ListNode *tail;

        ret.next = head;
        tail = _reverseKGroup(&ret, k);
        while ((tail = _reverseKGroup(tail, k)))
            ;
        return ret.next;
    }
};
