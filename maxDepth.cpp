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
    int _maxDepth(TreeNode *root, int depth) {
        if (!root->left && !root->right) return depth;
        int dl = 0;
        int dr = 0;
        
        if (root->right && root->left) {
            dl = _maxDepth(root->left, depth + 1);
            dr = _maxDepth(root->right, depth + 1);
            return dl > dr ? dl : dr;
        } else if (root->left) {
            dl = _maxDepth(root->left, depth + 1);
            return dl;
        } else {
            dr = _maxDepth(root->right, depth + 1);
            return dr;
        }
        return depth;
    }
public:
    int maxDepth(TreeNode *root) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        if (!root) return 0;
        return _maxDepth(root, 1);
    }
};