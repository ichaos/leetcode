/**
 * Symmetric Tree
 * Given a binary tree, check whether it is a mirror of itself (ie, symmetric around its center).

For example, this binary tree is symmetric:

    1
   / \
  2   2
 / \ / \
3  4 4  3
But the following is not:

    1
   / \
  2   2
   \   \
   3    3
Note:
Bonus points if you could solve it both recursively and iteratively.
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
    bool isSymmetric(TreeNode *root) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        if (!root) return true;
        
        vector<TreeNode *> v;
        int level = 0;
        
        v.push_back(root);
        
        while (!v.empty()) {
            int num = v.size();
            
            //check if it's symmetric at this level
            int i = 0;
            int j = v.size() - 1;
            
            while (i < j) {
                if (v[i] == NULL && v[j] == NULL) {
                    i++;
                    j--;
                } else if (v[i] && v[j] && v[i]->val == v[j]->val) {
                    i++; j--;
                } else
                    return false;
            }
            
            while (num > 0) {
                num--;
                if (v[0]) {
                    v.push_back(v[0]->left);
                    v.push_back(v[0]->right);
                }
                v.erase(v.begin());
            }
            level++;
        }
        
        return true;
    }
};