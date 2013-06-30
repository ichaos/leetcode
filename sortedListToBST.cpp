/**
 * Given an array where elements are sorted in ascending order, convert it to a height balanced BST.
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
private:
    TreeNode *_sortedListToBST(ListNode * &list, int i, int j) {
        if (i > j) return NULL;
        int mid = (i + j) / 2;
        
        TreeNode *left = _sortedListToBST(list, i, mid - 1);
        TreeNode *parent = new TreeNode(list->val);
        parent->left = left;
        list = list->next;
        parent->right = _sortedListToBST(list, mid + 1, j);
        return parent;
    }
public:
    TreeNode *sortedListToBST(ListNode *head) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        ListNode *list = head;
        int i = 0;
        while (list) {
            list = list->next;
            i++;
        }
        list = head;
        return _sortedListToBST(list, 1, i);
    }
};