/**
 * Binary Tree Level Order Traversal
 * Given a binary tree, return the level order traversal of its nodes' values. (ie, from left to right, level by level).

For example:
Given binary tree {3,9,20,#,#,15,7},

    3
   / \
  9  20
    /  \
   15   7
return its level order traversal as:

[
  [3],
  [9,20],
  [15,7]
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
public:
    vector<vector<int> > levelOrder(TreeNode *root) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        vector<vector<int> > v;
        if (!root) return v;
        int level = 0;
        int nextlevel = 0;
        queue<TreeNode *> q;
        q.push(root);
        level = 1;
        while (!q.empty()) {
            vector<int> n;
            while (level > 0) {
                TreeNode *tmp = q.front();
                q.pop();
                n.push_back(tmp->val);
                if (tmp->left) {
                    q.push(tmp->left);
                    nextlevel++;
                }
                if (tmp->right) {
                    q.push(tmp->right);
                    nextlevel++;
                }
                level--;
            }
            v.push_back(n);
            
            level = nextlevel;
            nextlevel = 0;
        }
        return v;
    }
};