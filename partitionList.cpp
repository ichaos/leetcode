/**
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
    ListNode *partition(ListNode *head, int x) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        ListNode *notless = new ListNode(0);
        ListNode *p = notless;
        ListNode *t, *pre;
        
        if (!head) return head;
        
        t = head;
        pre = NULL;

        while (t) {
            if (t->val >= x) {
                //remove t from old list
                if (pre) {
                    pre->next = t->next;
                } else {
                    head = t->next;
                }
                //add t into new list
                p->next = t;
                p = p->next;
                t = t->next;
            } else {
                pre = t;
                t = t->next;
            }
        }
        p->next = NULL;
        if (!pre) return notless->next;
        //merge two list
        pre->next = notless->next;
        delete notless;
        return head;
    }
};

int main() {
    //1->4->3->2->5->2
    ListNode node1(1);
    ListNode node2(4);
    ListNode node3(3);
    ListNode node4(2);
    ListNode node5(5);
    ListNode node6(2);

    node1.next = &node2;
    node2.next = &node3;
    node3.next = &node4;
    node4.next = &node5;
    node5.next = &node6;

    Solution s;
    ListNode *p;
    p = s.partition(&node1, 3);

    while(p) {
        cout << p->val << "->"; 
        p = p->next;
    }

    ;
}