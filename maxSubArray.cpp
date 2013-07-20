/**
 * maxSubArray
 * Find the contiguous subarray within an array (containing at least one number) which has the largest sum.

For example, given the array [−2,1,−3,4,−1,2,1,−5,4],
the contiguous subarray [4,−1,2,1] has the largest sum = 6.

More practice:
If you have figured out the O(n) solution, try coding another solution using the divide and conquer approach, which is more subtle.
 */
class Solution {
private:
    int _maxSubArray(int A[], int i, int j) {
        if (i > j) return INT_MIN;
        if (i == j) return A[i];
        int mid = (i + j) / 2;
        int left = _maxSubArray(A, i, mid - 1);
        int right = _maxSubArray(A, mid + 1, j);
        int cross = A[mid];
        int lm = 0;
        int tmp = 0;
        //to left
        int ti = mid - 1;
        while (ti >= i) {
            tmp += A[ti];
            if (tmp > lm) lm = tmp;
            ti--;
        }
        cross += lm;
        int rm = 0;
        tmp = 0;
        ti = mid + 1;
        while (ti <= j) {
            tmp += A[ti];
            if (tmp > rm) rm = tmp;
            ti++;
        }
        cross += rm;
        if (left < right) {
            left = right;
        }
        if (left < cross) {
            left = cross;
        }
        return left;
    }
public:
    int maxSubArray(int A[], int n) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        if (n < 1) return 0;
        if (n == 1) return A[0];
        return _maxSubArray(A, 0, n - 1);
    }
};