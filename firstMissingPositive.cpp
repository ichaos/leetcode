/**
 * Given an unsorted integer array, find the first missing positive integer.

For example,
Given [1,2,0] return 3,
and [3,4,-1,1] return 2.

Your algorithm should run in O(n) time and uses constant space.
 */

class Solution {
public:
    int firstMissingPositive(int A[], int n) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        set<int> s;
        for (int i = 0; i < n; i++) {
            s.insert(A[i]);
        }
        for (int i = 1; i <= n + 1; i++) {
            if (s.find(i) == s.end())
                return i;
        }
        return 1;
    }
};