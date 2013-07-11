#include <iostream>

using namespace std;

class Solution {
private:
    unsigned int _divide(unsigned int dividend, unsigned int divisor) {
        if (dividend < divisor) return 0;
        if (dividend == divisor) return 1;
        
        unsigned int dd = dividend;
        unsigned int dr = divisor;
        
        unsigned int quo = 1;
        
        while (dr * 2 < dd) {
            quo = quo + quo;
            dr = dr + dr;
        }
        
        return quo + _divide(dd - dr, divisor);
    }
public:
    int divide(int dividend, int divisor) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        bool negative = false;
        
        if (dividend < 0 && divisor > 0 || dividend > 0 && divisor < 0) {
            negative = true;
        }
        
        unsigned int dd = abs(dividend);
        unsigned int dr = abs(divisor);

        cout << dd << " " << dr << endl;
        
        int quotient = _divide(dd, dr);

        cout << quotient << ": " << 0 - quotient << ": " << -quotient << endl;
        
        if (negative) {
            return 0 - quotient;
        } else
            return quotient;
    }
};

int main() {
    Solution s;

    cout << s.divide(-2147483648, -1) << endl;
    return 0;
}