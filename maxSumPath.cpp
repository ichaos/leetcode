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
    int maxSum(TreeNode *root) {
        if (!root) return 0;
        int a = max(maxSum(root->left), maxSum(root->right));
        a += root->val;
        return a;
        if (a > 0) return a;
        else return 0;
    }
public:
    int maxPathSum(TreeNode *root) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        if (!root) return 0;
        int a = maxPathSum(root->left);
        int b = maxPathSum(root->right);
        
        //assume no negative value
        //int c = maxSum(root->left) + maxSum(root->right) + root->val;
        int c = 0;
        ///*
        int tmp = maxSum(root->left);
        if (tmp > 0)
            c += tmp;
        tmp = maxSum(root->right);
        if (tmp > 0)
            c += tmp;
        c += root->val;
        //*/
        if (root->right)
            a = max(a, b);
        if (root->left)
            c = max(a, c);
        return c;
    }
};