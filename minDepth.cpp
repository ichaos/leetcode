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
    int _minDepth(TreeNode *root, int depth) {
        if (!root->left && !root->right) return depth;
        int dl = 0;
        int dr = 0;
        if (root->left && root->right) {
            dl = _minDepth(root->left, depth + 1);
            dr = _minDepth(root->right, depth + 1);
            return dl < dr ? dl : dr;
        } else if (root->left) { 
            dl = _minDepth(root->left, depth + 1);
            return dl;
        } else {
            dr = _minDepth(root->right, depth + 1);
            return dr;
        }
    }
public:
    int minDepth(TreeNode *root) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        if (!root) return 0;
        return _minDepth(root, 1);
    }
};