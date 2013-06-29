/**
 * Given a binary tree and a sum, find all root-to-leaf paths where each path's sum equals the given sum.

For example:
Given the below binary tree and sum = 22,
              5
             / \
            4   8
           /   / \
          11  13  4
         /  \    / \
        7    2  5   1
return

[
   [5,4,11,2],
   [5,8,4,5]
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
    void travel(TreeNode *root, int sum, int cur, vector<vector<int> > &res, vector<int> rcd) {
        if (!root) return;
        else {
		    cur += root->val;
		    rcd.push_back(root->val);
            if (cur == sum) {
                if (!root->left && !root->right) {
                    res.push_back(rcd);
                    return;
                }  
    	    }
			travel(root->left, sum, cur, res, rcd);
			travel(root->right, sum, cur, res, rcd);
	    }
    }

public:
    vector<vector<int> > pathSum(TreeNode *root, int sum) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        vector<vector<int> > v;
        vector<int> rcd;
	    travel(root, sum, 0, v, rcd);
	    return v;
    }
};