/**
 * Search in Rotated Sorted Array
 * Suppose a sorted array is rotated at some pivot unknown to you beforehand.

(i.e., 0 1 2 4 5 6 7 might become 4 5 6 7 0 1 2).

You are given a target value to search. If found in the array return its index, otherwise return -1.

You may assume no duplicate exists in the array.
 */
class Solution {
public:
    int search(int A[], int n, int target) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        if (n < 1) return -1;
        
        int i = 0;
        int j = n - 1;
        
        while (i <= j) {
            int mid = (i + j) / 2;
            if (A[mid] == target) return mid;
            
            if (A[i] <= A[mid]) {
                if (target < A[i] || target > A[mid]) {
                    i = mid + 1;
                } else {
                    j = mid - 1;
                }
            } else {
                if (target >= A[i] || target < A[mid]) {
                    j = mid - 1;
                } else {
                    i = mid + 1;
                }
            }
        }
        return -1;
    }
};