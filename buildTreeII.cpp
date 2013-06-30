/**
 * Given inorder and postorder traversal of a tree, construct the binary tree.
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
    struct Unit {
        int left;
        int right;
        TreeNode **pos;
        Unit(int l, int r, TreeNode **p) : left(l), right(r), pos(p) {}
    };

public:
    TreeNode *buildTree(vector<int> &inorder, vector<int> &postorder) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        int ps = postorder.size();
        int is = inorder.size();
        
        if (ps < 1 || ps != is) return NULL;
        TreeNode *root = new TreeNode(postorder[ps - 1]);
        stack<Unit> s;
        
        
        //find the root in inorder list
        for (int i = 0; i < inorder.size(); i++) {
            if (postorder[ps - 1] == inorder[i]) {
                Unit l(0, i - 1, &(root->left));
                s.push(l);
                Unit r(i + 1, inorder.size() - 1, &(root->right));
                s.push(r);
                break;
            }
        }
        int sp = ps - 2;
        while (!s.empty()) {
            Unit u = s.top();
            s.pop();
            if (u.left > u.right) continue;
            //find root
            for (int i = u.left; i <= u.right; i++) {
                if (postorder[sp] == inorder[i]) {
                    TreeNode *tn = new TreeNode(inorder[i]);
                    sp--;
                    *u.pos = tn;
                    Unit l(u.left, i - 1, &(tn->left));
                    s.push(l);
                    Unit r(i + 1, u.right, &(tn->right));
                    s.push(r);
                    break;
                }
            }
        }
        
        return root;
    }
};