/**
 * Binary Tree Level Order Traversal II
 * Given a binary tree, return the bottom-up level order traversal of its nodes' values. (ie, from left to right, level by level from leaf to root).

For example:
Given binary tree {3,9,20,#,#,15,7},

    3
   / \
  9  20
    /  \
   15   7
return its bottom-up level order traversal as:

[
  [15,7]
  [9,20],
  [3],
]

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
    void _levelOrderBottom(TreeNode *root, int level, vector<vector<int> > &v) {
        if (!root) return;
        if (v.size() < level) {
            vector<int> t;
            v.push_back(t);
        }
        v[level - 1].push_back(root->val);
        _levelOrderBottom(root->left, level + 1, v);
        _levelOrderBottom(root->right, level + 1, v);
    }
public:
    vector<vector<int> > levelOrderBottom(TreeNode *root) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        vector<vector<int> > res;
        if (!root) return res;
        _levelOrderBottom(root, 1, res);
        
        vector<vector<int> > ret;
        for (int i = res.size() - 1; i >= 0; i--) {
            ret.push_back(res[i]);
        }
        return ret;
    }
};
