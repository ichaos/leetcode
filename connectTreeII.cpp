/**
 * Follow up for problem "Populating Next Right Pointers in Each Node".

What if the given tree could be any binary tree? Would your previous solution still work?

Note:

You may only use constant extra space.
For example,
Given the following binary tree,

         1
       /  \
      2    3
     / \    \
    4   5    7
After calling your function, the tree should look like:

         1 -> NULL
       /  \
      2 -> 3 -> NULL
     / \    \
    4-> 5 -> 7 -> NULL
 *
 */

/**
 * Definition for binary tree with next pointer.
 * struct TreeLinkNode {
 *  int val;
 *  TreeLinkNode *left, *right, *next;
 *  TreeLinkNode(int x) : val(x), left(NULL), right(NULL), next(NULL) {}
 * };
 */
class Solution {
public:
    void connect(TreeLinkNode *root) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        if (!root) return;
        
        queue<TreeLinkNode *> q;
        q.push(root);
        
        TreeLinkNode *tmp, *cur;
        
        while (!q.empty()) {
            cur = q.front();
            q.pop();
            
            if (cur->left) {
                if (cur->right) {
                    cur->left->next = cur->right;
                } else {
                    tmp = cur->next;
                    while (!cur->left->next) {
                        if (tmp) {
                            if (tmp->left) {
                                cur->left->next = tmp->left;
                            } else
                                cur->left->next = tmp->right;
                            tmp = tmp->next;
                        } else {
                            cur->left->next = NULL;
                            break;
                        }
                    }
                }
                q.push(cur->left);
            }
        
            if (cur->right) {
                tmp = cur->next;
                while (!cur->right->next) {
                    if (tmp) {
                        if (tmp->left) {
                            cur->right->next = tmp->left;
                        } else {
                            cur->right->next = tmp->right;
                        }
                        tmp = tmp->next;
                    } else {
                        cur->right->next = NULL;
                        break;
                    }
                }
                q.push(cur->right);
            }            
            
        }
    }
};