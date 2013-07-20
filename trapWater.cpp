/**
 * Trapping Rain Water
 * Given n non-negative integers representing an elevation map where the width of each bar is 1, compute how much water it is able to trap after raining.

For example, 
Given [0,1,0,2,1,0,1,3,2,1,2,1], return 6.



The above elevation map is represented by array [0,1,0,2,1,0,1,3,2,1,2,1]. 
In this case, 6 units of rain water (blue section) are being trapped.
 */

class Solution {
public:
    int trap(int A[], int n) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        stack<int> s;
        if (n < 1) return 0;
        
        s.push(0);
        int sum = 0;
        
        for (int i = 1; i < n; i++) {
            int last = s.top();
            if (A[i] < A[last]) {
                s.push(i);
            } else {
                s.pop();
                int tmp = 0;
                while (!s.empty()) {
                    last = s.top();
                    if (A[last] > A[i]) {
                        s.push(i);
                        break;
                    } else {
                        s.pop();
                    }
                }
                if (s.empty()) {
                   tmp = A[last] * (i - last - 1);
                   for (int j = last + 1; j < i; j++) {
                       tmp -= A[j];
                   }
                   if (tmp > 0) sum += tmp;
                   s.push(i);
                }
            }
        }
        if (!s.empty()) {
            int cur = s.top();
            s.pop();
            while (!s.empty()) {
                int last = s.top();
                s.pop();
                int tmp = (cur - last - 1) * A[cur];
                for (int j = last + 1; j < cur; j++) {
                    tmp -= A[j];
                }
                if (tmp > 0) sum += tmp;
                cur = last;
            }
        }
        return sum;
    }
};