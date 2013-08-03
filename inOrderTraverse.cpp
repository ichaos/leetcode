/**
 * Binary Tree Inorder Traversal
 * Given a binary tree, return the inorder traversal of its nodes' values.

For example:
Given binary tree {1,#,2,3},

   1
    \
     2
    /
   3
return [1,3,2].

Note: Recursive solution is trivial, could you do it iteratively?
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
    enum TYPE { LEFT = 0, MID, RIGHT };
    struct _TreeNode {    
        int type; //left = 0; 
        TreeNode *node;
        _TreeNode(TreeNode *nn, Solution::TYPE tt) : node(nn), type(tt) {}
    };
    
    void _inorderTraversal(vector<int> &ret, TreeNode *root) {
        if (!root) return;
        
        _inorderTraversal(ret, root->left);
        ret.push_back(root->val);
        _inorderTraversal(ret, root->right);
    }
    
    void _inorderTraversalNonRecursive(vector<int> &ret, TreeNode *root) {
        if (!root) return;
        
        stack<_TreeNode> s;
        
        _TreeNode n(root, LEFT);
        s.push(n);
        while (!s.empty()) {
            _TreeNode n = s.top();
            s.pop();
            if (n.type == MID) ret.push_back(n.node->val);
            else {
                if (n.node->right) {
                    _TreeNode t(n.node->right, RIGHT);
                    s.push(t);
                }
                _TreeNode t(n.node, MID);
                s.push(t);
                if (n.node->left) {
                    _TreeNode t(n.node->left, LEFT);
                    s.push(t);
                }                
            }
        }
    }
public:
    vector<int> inorderTraversal(TreeNode *root) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        vector<int> ret;
        //_inorderTraversal(ret, root);
        _inorderTraversalNonRecursive(ret, root);
        return ret;
    }
};