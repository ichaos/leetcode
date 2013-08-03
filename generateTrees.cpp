/**
 * Unique Binary Search Trees II
 * Given n, generate all structurally unique BST's (binary search trees) that store values 1...n.

For example,
Given n = 3, your program should return all 5 unique BST's shown below.

   1         3     3      2      1
    \       /     /      / \      \
     3     2     1      1   3      2
    /     /       \                 \
   2     1         2                 3
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
    vector<TreeNode *> _generateTrees(int start, int end) {
        if (start > end) return vector<TreeNode *>(1);
        
        vector<TreeNode *> ret;
        
        for (int i = start; i <= end; i++) {
            vector<TreeNode *> leftTree = _generateTrees(start, i - 1);
            vector<TreeNode *> rightTree = _generateTrees(i + 1, end);
            
            for (int j = 0; j < leftTree.size(); j++) {
                for (int k = 0; k < rightTree.size(); k++) {
                    TreeNode *root = new TreeNode(i);
                    root->left = leftTree[j];
                    root->right = rightTree[k];
                    ret.push_back(root);
                }
            }
        }
        return ret;
    }
public:
    vector<TreeNode *> generateTrees(int n) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        return _generateTrees(1, n);
    }
};