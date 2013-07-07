/**
 * Merge k Sorted Lists
 * Merge k sorted linked lists and return it as one sorted list. Analyze and describe its complexity.
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
    struct Listcomp {
        bool operator() (ListNode *a, ListNode *b) {
            return a->val < b->val;
        }
    };
public:
    ListNode *mergeKLists(vector<ListNode *> &lists) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        multiset<ListNode *, Listcomp> s;
        int n = lists.size();
        if (n < 1) return NULL;
        
        for (int i = 0; i < n; i++) {
            if (lists[i]) {
                s.insert(lists[i]);
            }
        }
        ListNode h(0), *head;
        head = &h;
        
        while (!s.empty()) {   
            ListNode *tmp = *s.begin();
            s.erase(s.begin());   
            if (tmp->next) {
                s.insert(tmp->next);
            }
            head->next = tmp;
            head = tmp;
        }
        
        return h.next;
    } 
};
