/**
 * Validate Binary Search Tree
 * Given a binary tree, determine if it is a valid binary search tree (BST).

Assume a BST is defined as follows:

The left subtree of a node contains only nodes with keys less than the node's key.
The right subtree of a node contains only nodes with keys greater than the node's key.
Both the left and right subtrees must also be binary search trees.
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
    bool _isValidBST(TreeNode *root, int k, int &minv, int &maxv) {        
        //find maximum of left subtree;
        int lmax = INT_MAX;
        int lmin = INT_MAX;
        if (root->left) {
            if (_isValidBST(root->left, 0, lmin, lmax) == false) return false;
            if (lmax >= root->val) return false;
        }
        //find minimum of right subtree;
        int rmax = INT_MIN;
        int rmin = INT_MIN;
        if (root->right) {
            if (_isValidBST(root->right, 1, rmin, rmax) == false) return false;
            if (rmin <= root->val) return false;
        }        
        minv = min(lmin, root->val);
        maxv = max(root->val, rmax);
        return true;
    }
public:
    bool isValidBST(TreeNode *root) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        if (!root) return true;
        int minv = 0;
        int maxv = 0;
        return _isValidBST(root, 0, minv, maxv);
    }
};