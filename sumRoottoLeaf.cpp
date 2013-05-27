/**
 * Sum Root to Leaf Numbers
 * Given a binary tree containing digits from 0-9 only, each root-to-leaf path could represent a number.
 * An example is the root-to-leaf path 1->2->3 which represents the number 123.
 * Find the total sum of all root-to-leaf numbers.
 * For example,
 *   1
 *  / \
 * 2   3
 * The root-to-leaf path 1->2 represents the number 12. 
 * The root-to-leaf path 1->3 represents the number 13.
 * Return the sum = 12 + 13 = 25.
 * /
 
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
    int _sumNumbers(TreeNode *root, long long prefix, long long &sum) {
        if (!root) {
            //sum += prefix;
            return 0;
        }
        if (!root->left && !root->right) {
            sum += (prefix * 10) + root->val;
            return 0;
        }
        
        _sumNumbers(root->left, prefix * 10 + root->val, sum);
        _sumNumbers(root->right, prefix * 10 + root->val, sum);
        
        return 0;
    }
public:
    int sumNumbers(TreeNode *root) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        long long sum = 0;
        //long long prefix = 0;
        _sumNumbers(root, 0, sum);
        return sum;
    }
};