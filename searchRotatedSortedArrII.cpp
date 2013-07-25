/**
 * Search in Rotated Sorted Array II
 * Follow up for "Search in Rotated Sorted Array":
What if duplicates are allowed?

Would this affect the run-time complexity? How and why?

Write a function to determine if a given target is in the array.
 */
class Solution {
private:
    bool _search(int A[], int i, int j, int target) {
        while (i <= j) {
            int mid = (i + j) / 2;
            if (A[mid] == target) return true;
            
            if (A[i] < A[mid]) {
                if (A[i] <= target && target < A[mid]) {
                    j = mid - 1;
                } else {
                    i = mid + 1;
                }
            } else if (A[i] > A[mid]) {
                if (target > A[mid] && target <= A[j]) {
                    i = mid + 1;
                } else if (target < A[mid] || target > A[j]) {
                    j = mid - 1;
                }
            } else { // A[i] == A[mid]
                if (i == mid) {
                    return A[j] == target;
                }
                if (A[mid] > A[j]) {
                    if (target > A[mid]) return false;
                    else i = mid + 1;
                } else if (A[mid] < A[j]) {
                    if (target < A[mid]) return false;
                    else i = mid + 1;
                } else {
                    if (_search(A, i + 1, mid - 1, target)) return true;
                    return _search(A, mid + 1, j - 1, target);
                }
            }
        }
        return false;
    }
public:
    bool search(int A[], int n, int target) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        int i = 0;
        int j = n - 1;
        
        while (i <= j) {
            int mid = (i + j) / 2;
            if (A[mid] == target) return true;
            
            if (A[i] < A[mid]) {
                if (A[i] <= target && target < A[mid]) {
                    j = mid - 1;
                } else {
                    i = mid + 1;
                }
            } else if (A[i] > A[mid]) {
                if (target > A[mid] && target <= A[j]) {
                    i = mid + 1;
                } else if (target < A[mid] || target > A[j]) {
                    j = mid - 1;
                }
            } else { // A[i] == A[mid]
                if (i == mid) {
                    return A[j] == target;
                }
                if (A[mid] > A[j]) {
                    if (target > A[mid]) return false;
                    else i = mid + 1;
                } else if (A[mid] < A[j]) {
                    if (target < A[mid]) return false;
                    else i = mid + 1;
                } else {
                    if (_search(A, i + 1, mid - 1, target)) return true;
                    return _search(A, mid + 1, j - 1, target);
                }
            }
        }
        return false;
    }
};