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
        
        TreeLinkNode *tmp;
        
        if (root->left) {
            if (root->right) {
                root->left->next = root->right;
            } else {
                tmp = root->next;
                while (!root->left->next) {
                    if (tmp) {
                        if (tmp->left) {
                            root->left->next = tmp->left;
                        } else
                            root->left->next = tmp->right;
                        tmp = tmp->next;
                    } else {
                        root->left->next = NULL;
                        break;
                    }
                }
            }
        }
        
        if (root->right) {
            tmp = root->next;
            while (!root->right->next) {
                if (tmp) {
                    if (tmp->left) {
                        root->right->next = tmp->left;
                    } else {
                        root->right->next = tmp->right;
                    }
                    tmp = tmp->next;
                } else {
                    root->right->next = NULL;
                    break;
                }
            }
        }
        
        connect(root->left);
        connect(root->right);
    }
};