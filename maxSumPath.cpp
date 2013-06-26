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
    int maxSum(TreeNode *root, int *maxChild) {
        int lm = 0;
        int rm = 0;
        
        *maxChild = 0;
        if (!root) return 0;
        int left = maxSum(root->left, &lm);
        int right = maxSum(root->right, &rm);
        
        int a = max(lm, rm);
        *maxChild = root->val;
        if (a > 0)
            *maxChild += a;
        
        a = 0;
        if (lm > 0)
            a += lm;
        if (rm > 0)
            a += rm;
        a += root->val;
        
        if (root->left)
            a = max(a, left);
        if (root->right)
            a = max(a, right);
        
        return a;
    }
public:
    int maxPathSum(TreeNode *root) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        //if (!root) return 0;
        int c = 0;
        int r = maxSum(root, &c);
        return r;
    }
};