/**
 * Unique Binary Search Trees
 * Given n, how many structurally unique BST's (binary search trees) that store values 1...n?

For example,
Given n = 3, there are a total of 5 unique BST's.

   1         3     3      2      1
    \       /     /      / \      \
     3     2     1      1   3      2
    /     /       \                 \
   2     1         2                 3
 */

class Solution {
private:
    int _numTrees(int s, int e) {
        if (s == e) {
            return 1;
        }
        
        if (s > e) return 0;
        int sum = 0;
        for (int i = s; i <= e; i++) {            
            int left = _numTrees(s, i - 1);
            int right = _numTrees(i + 1, e);
            if (left != 0 && right != 0)
                sum += (left * right);
            else
                sum += (left + right);
        }
        
        return sum;
    }
public:
    int numTrees(int n) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        int sum = 0;
        sum = _numTrees(0, n - 1);
        return sum;
    }
};