/**
 * Binary Tree Zigzag Level Order Traversal
 * Given a binary tree, return the zigzag level order traversal of its nodes' values. (ie, from left to right, then right to left for the next level and alternate between).

For example:
Given binary tree {3,9,20,#,#,15,7},

    3
   / \
  9  20
    /  \
   15   7
return its zigzag level order traversal as:

[
  [3],
  [20,9],
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
    vector<vector<int> > zigzagLevelOrder(TreeNode *root) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        vector<vector<int> > v;
        
        if (!root) return v;
        
        int level = 0;
        int nextLevel = 0;
        
        queue<TreeNode *> q;
        
        q.push(root);
        level = 1;
        
        int d = 0; //from left to right; 1 - from right to left
        
        while (!q.empty()) {
            vector<int> n;
            while (level > 0) {
                level--;
                TreeNode *tmp = q.front();
                q.pop();
                n.push_back(tmp->val);
                if (tmp->left) {
                    q.push(tmp->left);
                    nextLevel++;
                }
                
                if (tmp->right) {
                    q.push(tmp->right);
                    nextLevel++;
                }
            }
            if (d) {
                vector<int> r;
                for (int i = n.size() - 1; i >= 0; i--) {
                    r.push_back(n[i]);
                }
                n = r;
            }
            v.push_back(n);
            d = ~d;
            level = nextLevel;
            nextLevel = 0;
        }
        return v;
    }
};