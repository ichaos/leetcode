class Solution {
public:
    void merge(int A[], int m, int B[], int n) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        if (n < 1) return;
        
        int bi = n - 1;
        int ai = m - 1;
        int k = m + n - 1;
        while (bi >= 0 && ai >= 0) {
            if (B[bi] > A[ai]) {
                A[k] = B[bi];
                bi--;
            } else {
                A[k] = A[ai];
                ai--;
            }
            k--;
        }
        while (bi >= 0) {
            A[k] = B[bi];
            k--;
            bi--;
        }
    }
};