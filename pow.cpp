/**
 * Implement pow(x, n).
 */
class Solution {
private:
    
public:
    double pow(double x, int n) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        if (n == 0) return 1;
        if (n < 0 && x != 0) {
            if (n % 2) {
                return pow(1 / (x * x), 0 - (n / 2)) / x;
            } else {
                return pow(1 / (x * x), 0 - (n / 2));
            }
        }
        
        if (n == 1) return x;
        if (n % 2) {
            return pow(x * x, n / 2) * x;
        } else {
            return pow(x * x, n / 2);
        }
    }
};