/**
 * Jump Game II
 * Given an array of non-negative integers, you are initially positioned at the first index of the array.

Each element in the array represents your maximum jump length at that position.

Your goal is to reach the last index in the minimum number of jumps.

For example:
Given array A = [2,3,1,1,4]

The minimum number of jumps to reach the last index is 2. (Jump 1 step from index 0 to 1, then 3 steps to the last index.)
 */
class Solution {
public:
    int jump(int A[], int n) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        if (n < 1) return 0;
        
        int B[n];
        for (int i = 0; i < n; i++) {
            B[i] = INT_MAX - 10;
        }
        B[0] = 0;
        for (int i = 0; i < n; i++) {
            for (int j = 1; j <= A[i] && i + j < n; j++) {
                if (B[i + j] - 1 > B[i])
                    B[i + j] = B[i] + 1;
            }
        }
        return B[n - 1];
    }
};