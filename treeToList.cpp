#include <iostream>
#include <stdio.h>
#include <stack>

using namespace std;

struct TreeNode {
     int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};


	void flatten(TreeNode *root) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        if (!root) return;

        stack<TreeNode *> s;
	    TreeNode *list = root;
	    TreeNode *cur;
	    if (root->right) s.push(root->right);
	    if (root->left) s.push(root->left);
        

	    while (!s.empty()) {
		    cur = s.top();
		    s.pop();
		    list->right = cur;
		    list = cur;
		    if (cur->right) s.push(cur->right);
		    if (cur->left) s.push(cur->left);
	    }
    }

int main() {
	TreeNode root(1);
	TreeNode right(2);
	root.right = &right;
	flatten(&root);
	TreeNode *cur = &root;
	while (cur) {
		cout << "cur->val: " << cur->val << endl;
		cur = cur->right;
	}
}