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
    ListNode *reverseBetween(ListNode *head, int m, int n) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        if (!head) return head;
        ListNode *cur = head;
        int i = 0;        
        ListNode ret(0);
        ListNode *p = NULL;
        if (m == 1) {            
            p = &ret;
            p->next = head;
        }

        ListNode *post = cur;
        ListNode *tail = NULL;
        ListNode *tmp;
        while (cur) {
            i++;
            tmp = cur->next;
            if (i >= n) {
                break;
            }
            if (i == m - 1) { //prepare
                p = cur;
            } else if (i == m) {
                tail = cur;
            } else if (i > m) {
                tail->next = cur->next;
                cur->next = p->next;
                p->next = cur;
            }
            cur = tmp;
        }
        if (m == 1) return p->next;
        else return head;
    }
};