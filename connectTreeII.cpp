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
        
        if (root->left) {
            if (root->right) {
                root->left->next = root->right;
            } else {
                if (root->next) {
                    if (root->next->left) {
                        root->left->next = root->next->left;
                    } else
                        root->left->next = root->next->right;
                } else {
                    root->left->next = NULL;
                }
            }
        }
        
        if (root->right) {
            if (root->next) {
                if (root->next->left) {
                    root->right->next = root->next->left;
                } else {
                    root->right->next = root->next->right;
                }
            }
        }
        
        connect(root->left);
        connect(root->right);
    }
};