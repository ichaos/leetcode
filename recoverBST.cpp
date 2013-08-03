/**
 * Recover Binary Search Tree
 * Two elements of a binary search tree (BST) are swapped by mistake.

Recover the tree without changing its structure.

Note:
A solution using O(n) space is pretty straight forward. Could you devise a constant space solution?
 *
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
    //inorder traverse the tree and store its nodes into vector
    void traverseTree(TreeNode *root, vector<TreeNode *> &ret) {
        if (!root) return;
        if (root->left) {
            traverseTree(root->left, ret);
        }
        ret.push_back(root);
        if (root->right) {
            traverseTree(root->right, ret);
        }
    }
public:
    void recoverTree(TreeNode *root) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        TreeNode *left = NULL;
        TreeNode *right = NULL;
        vector<TreeNode *> ret;
        traverseTree(root, ret);
        
        for (vector<TreeNode *>::iterator iter = ret.begin(); iter + 1 != ret.end(); iter++) {
            if ((*iter)->val >= (*(iter + 1))-> val) {
                if (!left) {
                    left = (*iter);
                    right = *(iter + 1);
                } else {
                    right = *(iter + 1);
                }
            }
        }
        
        if (left && right) {
            int tmp = left->val;
            left->val = right->val;
            right->val = tmp;
        }
    }
};