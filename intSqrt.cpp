/**
 * Sqrt(x)
 * Implement int sqrt(int x).

Compute and return the square root of x.
 */
class Solution {
public:
    int sqrt(int x) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        if (x < 1) return 0;
        if (x < 4) return 1;
        
        int a = 2;
        int b = x / 2;
        
        while (a < b) {
            int s = (a + b) / 2;
            if (x / s == s) return s;
            if (x / s < s) {
                b = s - 1;
            } else {
                a = s + 1;
                if (x / a < a)  return s;
            }
        }
        
        return (a + b) / 2;
    }
};