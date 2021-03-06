/**
 * Search Insert Position
 * Given a sorted array and a target value, return the index if the target is found. If not, return the index where it would be if it were inserted in order.

You may assume no duplicates in the array.

Here are few examples.
[1,3,5,6], 5 → 2
[1,3,5,6], 2 → 1
[1,3,5,6], 7 → 4
[1,3,5,6], 0 → 0
 */

class Solution {
public:
    int searchInsert(int A[], int n, int target) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        if (n < 1) return 0;
        
        int i = 0;
        int j = n - 1;
        
        while (i < j) {
            int mid = (i + j) / 2;
            
            if (A[mid] == target) {
                return mid;
            }
            
            if (A[mid] < target) {
                i = mid + 1;
            } else {
                j = mid - 1;
            }
        }
        
        return (A[i] < target) ? i + 1 : i;
    }
};