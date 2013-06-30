/**
 * Given an array where elements are sorted in ascending order, convert it to a height balanced BST.
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
    TreeNode *_sortedArrayToBST(int *a, int s) {
        if (s < 1) return NULL;
        TreeNode *root = new TreeNode(a[s / 2]);
        root->left = _sortedArrayToBST(a, s / 2);
        root->right = _sortedArrayToBST(a + s / 2 + 1, s - s / 2 - 1);
        return root;
    }
public:
    TreeNode *sortedArrayToBST(vector<int> &num) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        int length = num.size();
        if (length < 1) return NULL;
        
        int f[length];
        for (int i = 0; i < length; i++) {
            f[i] = num[i];
        }
        
        TreeNode *root = _sortedArrayToBST(f, length);
        
        return root;
    }
};