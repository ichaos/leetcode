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
    ///*
    int _isBalanced(TreeNode *root, int depth) {
        if (!root->left && !root->right) return depth;
        int dl = 0;
        int dr = 0;
        if (root->left && root->right) {
            dl = _isBalanced(root->left, depth + 1);
            dr = _isBalanced(root->right, depth + 1);
            if (dl == -1 || dr == -1) return -1;
            if (dl > dr + 1 || dr > dl + 1) return -1;
            return dl > dr ? dl : dr; 
        } else if (root->left) {
            dl = _isBalanced(root->left, depth + 1);
            if (dl == -1 || dl > depth + 1) return -1;
            return dl;
        } else {
            dr = _isBalanced(root->right, depth + 1);
            if (dr == -1 || dr > depth + 1) return -1;
            return dr;
        }
        //return depth;
    }
    //*/
    
public:
    bool isBalanced(TreeNode *root) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        if (!root) return true;
        return (_isBalanced(root, 1) != -1);
    }
};