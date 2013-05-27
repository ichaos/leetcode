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
    bool _hasPathSum(TreeNode *root, int sum) {
        if (!root->left && !root->right && root->val == sum) return true;
        bool res = false;
        if (root->left) {
            res = res || _hasPathSum(root->left, sum - root->val);
        }
        if (res) return true;
        if (root->right) {
            res = res || _hasPathSum(root->right, sum - root->val);
        }
        return res;
    }    
public:
    bool hasPathSum(TreeNode *root, int sum) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        if (!root) return false;
        return _hasPathSum(root, sum);
    }
};