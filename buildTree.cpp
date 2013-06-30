/**
 * Given preorder and inorder traversal of a tree, construct the binary tree.

Note:
You may assume that duplicates do not exist in the tree.
 *
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

 #include <iostream>
 #include <stack>
 #include <queue>

 using namespace std;

 struct TreeNode {
      int val;
      TreeNode *left;
      TreeNode *right;
      TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 };
class Solution {
private:
    struct Unit {
        int left;
        int right;
        TreeNode **pos;
        Unit(int l, int r, TreeNode **p) : left(l), right(r), pos(p) {}
    };
    
public:
    TreeNode *buildTree(vector<int> &preorder, vector<int> &inorder) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        if (preorder.size() < 1 || preorder.size() != inorder.size()) return NULL;
        TreeNode *root = new TreeNode(preorder[0]);
        stack<Unit> s;
        
        
        //find the root in inorder list
        for (int i = 0; i < inorder.size(); i++) {
            if (preorder[0] == inorder[i]) {
                Unit r(i + 1, inorder.size() - 1, &(root->right));
                s.push(r);
                Unit l(0, i - 1, &(root->left));
                s.push(l);
                break;
            }
        }
        int sp = 1;
        while (!s.empty()) {
            Unit u = s.top();
            s.pop();
            if (u.left > u.right) continue;
            //find root
            for (int i = u.left; i <= u.right; i++) {
                if (preorder[sp] == inorder[i]) {
                    TreeNode *tn = new TreeNode(inorder[i]);
                    sp++;
                    *u.pos = tn;
                    Unit r(i + 1, u.right, &(tn->right));
                    s.push(r);
                    Unit l(u.left, i - 1, &(tn->left));
                    s.push(l);
                    break;
                }
            }
        }
        
        return root;
    }
};

void travel(TreeNode *root) {
    if (!root) return;
    travel(root->left);
    cout << root->val << ", ";
    travel(root->right);
}

int main() {
    int a[] = {1,2,3};
    int b[] = {2,1,3};

    Solution s;

    vector<int> va(a, a + 3);
    std::vector<int> vb(b, b + 3);

    TreeNode *root = s.buildTree(va, vb);

    travel(root);
}