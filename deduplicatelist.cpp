/**
 * Remove Duplicates from Sorted Array II
 * Follow up for "Remove Duplicates":
What if duplicates are allowed at most twice?

For example,
Given sorted array A = [1,1,1,2,2,3],

Your function should return length = 5, and A is now [1,1,2,2,3].
 */
class Solution {
public:
    int removeDuplicates(int A[], int n) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        if (n < 1) return 0;
        int j = 0;
        int prev = A[0];
        int cnt = 0;
        
        for (int i = 1; i < n; i++) {
            if (A[i] == A[j]) {
                cnt++;
                if (cnt >= 2) continue;
            } else {
                prev = A[i];
                cnt = 0;
            }
            A[++j] = A[i];
        }
        return j + 1;
    }
};